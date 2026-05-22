# Kronecker-cpp
Project to resolve a system on nxn matrix, using the product of Kronecker, and not the inverse
# LAPACK library install
sudo apt update
sudo apt install liblapacke-dev liblapack-dev libblas-dev

# Execute terminal
g++ main.cpp include/**.cpp -o test -llapacke -llapack

# Clean and rerun build in CMake
cd /home/ragde/Kronecker-cpp/build
rm -rf *
cmake ..
cmake --build .

# Release and Debug
mkdir Release
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
And for Debug (again from the root of your project):

mkdir Debug
cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
