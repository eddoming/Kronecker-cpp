cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Kroneckercpp VERSION 1.1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# LAPACK and FLTK library
find_package(LAPACK REQUIRED)
#find_package(FLTK REQUIRED)

# Define the executable and its source files
add_executable(Kronecker src/main.cpp)

# Inputs for Relase and DEbug
#set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
add_library(Functions STATIC
    src/include/Functions.cpp
    src/include/Functions.h
)

target_include_directories(Functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Apply flags dynamically based on the active build type
target_compile_options(Kronecker PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -g>
    $<$<CONFIG:Release>:-O3 -march=native>
)

# Link LAPACK
target_link_libraries(Kronecker PRIVATE Functions lapacke ${LAPACK_LIBRARIES})
