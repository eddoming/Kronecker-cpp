# Kronecker-cpp
Project to resolve a system on nxn matrix, using the product of Kronecker, and not the inverse
# LAPACK library install
sudo apt update
sudo apt install liblapacke-dev liblapack-dev libblas-dev

# Execute terminal
g++ main.cpp -o test -llapacke -llapack

# Clean and rerun build in CMake
cd /home/ragde/Kronecker-cpp/build
rm -rf *
cmake ..
cmake --build .
