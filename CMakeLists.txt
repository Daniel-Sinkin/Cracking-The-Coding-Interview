cmake_minimum_required(VERSION 3.10)

project(CrackingTheCodingInterview VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files from the src directory
add_executable(main
    src/main.cpp
    src/algorithms.cpp
    src/examples.cpp
    src/datastructures/binary_search_tree.cpp
    src/datastructures/binary_tree.cpp
    src/datastructures/dynamic_array.cpp
    src/datastructures/graph.cpp
    src/datastructures/linked_list.cpp
    src/datastructures/min_heap.cpp
    src/datastructures/tree.cpp
    src/datastructures/trie.cpp
)

# Add include directory for header files, including datastructures folder
target_include_directories(main PRIVATE 
    include
    include/datastructures
)

# Checks for unused imports
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "include-what-you-use")

# Set compiler options
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
