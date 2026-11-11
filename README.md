# DevScope (C++ component, v0.0.1)

A tiny C++17 module that collects basic system information and checks
whether a few common development tools are installed. It uses only the
standard library.

It reports:

- OS name, CPU architecture, number of CPU cores
- Availability of `g++`, `clang++`, `cmake` and `git`

Results are returned as a plain `devscope::SystemInfo` struct
(`cpp/include/system_info.hpp`); `main.cpp` just prints them.

## Build and run

```sh
cd cpp
cmake -S . -B build
cmake --build build
./build/devscope_cpp        # Windows: .\build\Debug\devscope_cpp.exe
```

## Notes

- A tool is "found" if `<tool> --version` exits successfully.
- This is a prototype. The Rust core is developed separately and is not part of this repo section.
