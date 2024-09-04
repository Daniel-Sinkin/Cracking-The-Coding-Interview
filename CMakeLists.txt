cmake_minimum_required(VERSION 3.10)

project(CrackingTheCodingInterview VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main
    src/main.cpp
    src/datastructures.cpp
    src/examples.cpp
)

target_include_directories(main PRIVATE include)