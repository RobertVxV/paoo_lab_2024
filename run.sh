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

# Run cmake and make commands
cmake ..
make

# Execute the 'homework1' binary
./homework1

