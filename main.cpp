#include <iostream>

#include "system_info.hpp"

int main() {
    const devscope::SystemInfo info = devscope::collect_system_info();

    std::cout << "DevScope v0.0.1 (C++ component)\n\n";

    std::cout << "System\n";
    std::cout << "  OS:           " << info.os_name << "\n";
    std::cout << "  Architecture: " << info.cpu_arch << "\n";
    std::cout << "  CPU cores:    " << info.cpu_cores << "\n\n";

    std::cout << "Tools\n";
    for (const auto& tool : info.tools) {
        std::cout << "  " << tool.name << ": "
                  << (tool.available ? "found" : "not found") << "\n";
    }
    return 0;
}
