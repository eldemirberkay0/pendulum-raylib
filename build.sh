#!/bin/bash

BUILD_DIR="build"
#BUILD_TYPE="Release"

echo "Creating directory: ${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"

echo "Entering directory: ${BUILD_DIR}"
cd "${BUILD_DIR}"

echo "Starting cmake"
cmake ..

echo "Building the project"
cmake --build .
echo "-------------------------"
echo "Builded successfully"
echo "Executing the project"
./pendulum_raylib
echo "Going back to root directory"
cd ..