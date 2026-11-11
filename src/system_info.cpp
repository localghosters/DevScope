#include "../include/system_info.hpp"

#include <cstdlib>
#include <thread>

namespace devscope {

namespace {

// Operating system name, resolved at compile time.
std::string detect_os() {
#if defined(_WIN32)
    return "Windows";
#elif defined(__APPLE__)
    return "macOS";
#elif defined(__linux__)
    return "Linux";
#else
    return "Unknown";
#endif
}

// CPU architecture of the build target, resolved at compile time.
std::string detect_arch() {
#if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
#elif defined(__aarch64__) || defined(_M_ARM64)
    return "arm64";
#elif defined(__i386__) || defined(_M_IX86)
    return "x86";
#elif defined(__arm__) || defined(_M_ARM)
    return "arm";
#else
    return "unknown";
#endif
}

// A tool counts as available if "<tool> --version" runs and exits with 0.
// Output is discarded; only the exit code matters.
bool is_tool_available(const std::string &tool) {
#if defined(_WIN32)
    const std::string command = tool + " --version > NUL 2>&1";
#else
    const std::string command = tool + " --version > /dev/null 2>&1";
#endif
    return std::system(command.c_str()) == 0;
}

} // namespace

SystemInfo collect_system_info() {
    SystemInfo info;
    info.os_name = detect_os();
    info.cpu_arch = detect_arch();
    info.cpu_cores = std::thread::hardware_concurrency(); // 0 if unknown

    for (const char *tool : {"g++", "clang++", "cmake", "git"}) {
        info.tools.push_back({tool, is_tool_available(tool)});
    }
    return info;
}

} // namespace devscope
