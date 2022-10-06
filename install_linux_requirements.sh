#!/bin/bash
sudo apt update
sudo apt install -y gpg wget zip unzip cmake build-essential pkg-config ninja-build clang clang-tidy
# Glew dependencies
sudo apt install -y libxmu-dev libxi-dev libgl-dev
# GLFW dependencies
sudo apt install -y libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev
# Latest CMake
wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null
echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ focal main' | sudo tee /etc/apt/sources.list.d/kitware.list >/dev/null
sudo apt-get update
sudo apt install -y cmake
