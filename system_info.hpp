#pragma once

#include <string>
#include <vector>

namespace devscope {

// Availability of a single development tool.
struct ToolStatus {
    std::string name;
    bool available;
};

// Everything the C++ component collects in v0.0.1.
struct SystemInfo {
    std::string os_name;
    std::string cpu_arch;
    unsigned int cpu_cores;
    std::vector<ToolStatus> tools;
};

// Collects basic system information and checks a few common tools.
SystemInfo collect_system_info();

}  // namespace devscope
