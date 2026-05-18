cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Kroneckercpp VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the executable and its source files
add_executable(Kronecker src/main.cpp)
