#!/bin/bash

# Navigate to the directory where the script is located
cd "$(dirname "$0")"

# Remove the build directory if it exists
rm -rf build

# Create a new build directory
mkdir build

# Navigate into the build directory
cd build

# Run CMake to configure the project
cmake ..

# Build the project
cmake --build .

clear

# Run the resulting executable
echo "####################"
echo "# Running './main' #"
echo "####################"
echo ""
./main