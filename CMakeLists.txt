cmake_minimum_required(VERSION 3.10)
project(devscope_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(devscope_cpp
    src/main.cpp
    src/system_info.cpp
)
target_include_directories(devscope_cpp PRIVATE include)
