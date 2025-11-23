#!/bin/bash

BUILD_DIR="build"

if [ -f /etc/os-release ] && grep -q "ID=debian" /etc/os-release; then
    echo "==========================================="
    echo "Linux (Debian/Ubuntu based) system detected."
    echo "Checking for required dependency: libgtk-3-dev..."
    
    # Check if the package is already installed using dpkg
    if ! dpkg -l | grep -q "libgtk-3-dev"; then
        echo "libgtk-3-dev is not installed. SUDO PASSWORD may be required for installation."
        
        sudo apt update
        sudo apt install -y libgtk-3-dev
        
        # Check if installation is successful
        if [ $? -eq 0 ]; then
            echo "libgtk-3-dev installed successfully."
        else
            echo "ERROR: libgtk-3-dev installation failed. Please try installing it manually."
            exit 1
        fi
    else
        echo "libgtk-3-dev is already installed. Continuing."
    fi
    echo "==========================================="
fi

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