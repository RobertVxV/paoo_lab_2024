#!/bin/bash

# Check if the number of arguments is correct
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Check if the specified directory exists
if [ ! -d "$1" ]; then
    echo "Error: Directory '$1' does not exist."
    exit 1
fi

# Navigate to the specified directory
cd "$1" || exit

# Remove the 'build' directory if it exists, then recreate it
rm -rf build
mkdir build
cd build || exit

# Run cmake and check if it succeeded
cmake ..
if [ $? -ne 0 ]; then
    echo "Error: cmake failed."
    exit 1
fi

# Run make and check if it succeeded
make
if [ $? -ne 0 ]; then
    echo "Error: make failed."
    exit 1
fi

# Find the single executable file
executable_file=$(basename "$1")

# Check if exactly one executable file was found
if [ -z "$executable_file" ]; then
    echo "Error: Executable '$executable_file' not found."
    exit 1
fi

# Execute the found executable
echo "Running executable: $executable_file"
./$executable_file