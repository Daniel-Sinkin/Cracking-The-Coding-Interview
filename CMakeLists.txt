cmake_minimum_required(VERSION 3.10)

project(CrackingTheCodingInterview VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files from the src directory
add_executable(main
    src/main.cpp
    src/algorithms.cpp
    src/binary_search_tree.cpp
    src/binary_tree.cpp
    src/dynamic_array.cpp
    src/examples.cpp
    src/graph.cpp
    src/linked_list.cpp
    src/min_heap.cpp
    src/tree.cpp
    src/trie.cpp
)

# Add include directory for header files
target_include_directories(main PRIVATE include)

# Set compiler options
target_compile_options(main PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
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