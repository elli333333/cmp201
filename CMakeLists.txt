cmake_minimum_required(VERSION 3.19)
project(201Assessment)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt)

add_executable(201Assessment
        main.cpp
        fileHandling.hpp
        boyermoore.hpp
        rabinkarp.hpp)
target_link_libraries(201Assessment fmt::fmt)