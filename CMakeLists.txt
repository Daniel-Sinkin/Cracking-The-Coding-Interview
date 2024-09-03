cmake_minimum_required(VERSION 3.10)

project(CrackingTheCodingInterview)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main src/main.cpp src/datastructures.cpp)