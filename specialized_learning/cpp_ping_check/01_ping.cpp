#include <iostream>
#include <string>
#include <cstdlib>

enum class IPVersion {
    IPv4,
    IPv6
};

/**
 * @brief Checks internet connectivity using system ping command.
 * 
 * @param ip_version IPVersion::IPv4 or IPVersion::IPv6
 * @param target_host IP address or domain to ping
 * @param timeout_sec Maximum wait time in seconds
 * @return true if target responds to ping, false otherwise
 */
bool ping_check(IPVersion ip_version, const std::string& target_host, int timeout_sec = 2) {
    std::string command;

    if (ip_version == IPVersion::IPv4) {
        // -c 1: send 1 packet, -W: timeout in seconds
        command = "ping -c 1 -W " + std::to_string(timeout_sec) + " " + target_host + " > /dev/null 2>&1";
    } else {
        // -6 for IPv6 (or ping6 depending on system)
        command = "ping -6 -c 1 -W " + std::to_string(timeout_sec) + " " + target_host + " > /dev/null 2>&1";
    }

    int result = std::system(command.c_str());
    
    // std::system returns 0 if the command executed and ping succeeded
    return (result == 0);
}

int main() {
    // IPv4 Check
    std::string v4_ip = "8.8.8.8";
    std::cout << "Pinging IPv4 (" << v4_ip << "): " 
              << (ping_check(IPVersion::IPv4, v4_ip, 2) ? "ONLINE" : "OFFLINE") << std::endl;

    // IPv6 Check
    std::string v6_ip = "2001:4860:4860::8888";
    std::cout << "Pinging IPv6 (" << v6_ip << "): " 
              << (ping_check(IPVersion::IPv6, v6_ip, 2) ? "ONLINE" : "OFFLINE") << std::endl;

    return 0;
}
