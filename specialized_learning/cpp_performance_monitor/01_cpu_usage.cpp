#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <unistd.h>

struct CPUData {
    long user, nice, system, idle, iowait, irq, softirq, steal;
};

CPUData readCPU() {
    std::ifstream file("/proc/stat");
    std::string cpu;
    CPUData data;
    file >> cpu >> data.user >> data.nice >> data.system >> data.idle 
         >> data.iowait >> data.irq >> data.softirq >> data.steal;
    return data;
}

double calculateUsage(const CPUData& a, const CPUData& b) {
    long activeA = a.user + a.nice + a.system + a.irq + a.softirq + a.steal;
    long idleA = a.idle + a.iowait;
    long totalA = activeA + idleA;

    long activeB = b.user + b.nice + b.system + b.irq + b.softirq + b.steal;
    long idleB = b.idle + b.iowait;
    long totalB = activeB + idleB;

    return 100.0 * (activeB - activeA) / (totalB - totalA);
}

void printMemory() {
    std::ifstream file("/proc/meminfo");
    std::string label;
    long total, free;
    while (file >> label) {
        if (label == "MemTotal:") file >> total;
        if (label == "MemAvailable:") { file >> free; break; }
        file.ignore(256, '\n');
    }
    std::cout << "Memory Usage: " << (total - free) / 1024 << " MB / " 
              << total / 1024 << " MB" << std::endl;
}

int main() {
    CPUData s1 = readCPU();
    sleep(1); // Wait 1 second for sample delta
    CPUData s2 = readCPU();

    std::cout << "CPU Usage: " << calculateUsage(s1, s2) << "%" << std::endl;
    printMemory();
    return 0;
}
