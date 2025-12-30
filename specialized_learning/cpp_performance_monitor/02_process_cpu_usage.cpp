#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <unistd.h>
#include <sstream>

struct ProcStats {
    unsigned long long utime, stime;
    unsigned long long total_system_time;
};

// 1. Find PID by process name
int findPidByName(const std::string& name) {
    DIR* dir = opendir("/proc");
    if (!dir) return -1;

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            std::string pid_str = entry->d_name;
            if (pid_str.find_first_not_of("0123456789") == std::string::npos) {
                std::ifstream comm_file("/proc/" + pid_str + "/comm");
                std::string line;
                if (std::getline(comm_file, line) && line == name) {
                    closedir(dir);
                    return std::stoi(pid_str);
                }
            }
        }
    }
    closedir(dir);
    return -1;
}

// 2. Get Memory (RSS) in KB
long getMemoryUsage(int pid) {
    std::ifstream status("/proc/" + std::to_string(pid) + "/status");
    std::string line;
    while (std::getline(status, line)) {
        if (line.find("VmRSS:") == 0) {
            std::stringstream ss(line);
            std::string label;
            long value;
            ss >> label >> value;
            return value;
        }
    }
    return 0;
}

// 3. Get raw CPU ticks for process and system
ProcStats getCpuTicks(int pid) {
    ProcStats stats = {0, 0, 0};
    
    // Process ticks
    std::ifstream pstat("/proc/" + std::to_string(pid) + "/stat");
    std::string tmp;
    for(int i=1; i<=13; ++i) pstat >> tmp; // Skip first 13 fields
    pstat >> stats.utime >> stats.stime;

    // Total system ticks
    std::ifstream sstat("/proc/stat");
    sstat >> tmp; // Skip "cpu"
    unsigned long long val, sum = 0;
    while (sstat >> val) sum += val;
    stats.total_system_time = sum;

    return stats;
}

int main() {
    const std::string target = "htop";
    int pid = findPidByName(target);

    if (pid == -1) {
        std::cerr << "Process '" << target << "' not found." << std::endl;
        return 1;
    }

    std::cout << "Monitoring " << target << " (PID: " << pid << ")..." << std::endl;

    while (true) {
        // Sample 1
        ProcStats s1 = getCpuTicks(pid);
        usleep(500000); // Wait 500ms
        // Sample 2
        ProcStats s2 = getCpuTicks(pid);

        // Calculate CPU %
        double process_diff = (s2.utime + s2.stime) - (s1.utime + s1.stime);
        double system_diff = s2.total_system_time - s1.total_system_time;
        double cpu_percent = (process_diff / system_diff) * 100.0;

        // Get Memory
        long mem_kb = getMemoryUsage(pid);

        std::cout << "\rCPU: " << cpu_percent << "% | MEM: " << mem_kb << " KB    " << std::flush;
    }

    return 0;
}
