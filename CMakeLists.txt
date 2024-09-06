cmake_minimum_required(VERSION 3.10)

project(CrackingTheCodingInterview VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/datastructures/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/algorithms/*.cpp"
)

add_executable(main ${SRC_FILES})

target_include_directories(main PRIVATE 
    include
    include/datastructures
    include/algorithms
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=undefined")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use")

target_compile_options(main PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -Wunused
    -fdiagnostics-show-option
    -Wconversion                    # Warn about implicit conversions
    -Wshadow                        # Warn about variable shadowing
    -Wshorten-64-to-32              # Warn when implicit truncation from 64-bit to 32-bit happens
    -Wnull-dereference
    -Wredundant-move
    -Wdouble-promotion
    -Wstrict-aliasing
    -Wpessimizing-move
    -Wformat-nonliteral
)
