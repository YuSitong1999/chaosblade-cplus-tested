cmake_minimum_required(VERSION 3.25)
project(chaosblade_cplus_tested)

# 保留调试信息，支持注入故障
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        main.cpp)
