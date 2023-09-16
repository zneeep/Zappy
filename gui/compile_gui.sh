#!/bin/bash

## Global variables
BINARY_PATH="$(pwd)/output/zappy_gui"

# Compilation
cmake . && make

## Output in case of failed compilation
if [ "$?" -ne 0 ]; then
    echo "Compilation failed"
    exit 1
else
    echo "Compilation succeeded"
fi
