#include <iostream>
#include <vector>

// Standard C-linkage header for LAPACKE
#include <lapacke.h>

int main() {
    std::cout << "Kronecker-cpp Project" << std::endl;
    // Solve Ax = b
    // A = [ 1, 2 ]
    //     [ 3, 4 ]
    // b = [ 5, 11 ]
    //
    int n = 2; // Matrix size (n x n)
    int nrhs = 1; // Number of right-hand columns

    std::vector<double> A = {1.0, 2.0,
                             3.0, 4.0};
    std::vector<double> b = {5.0,
                             11.0};

    // LAPACK will output the pivot indices here
    std::vector<int> ipiv(n);

    // Call LAPACKE using Row Major layout
    int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs,
                             A.data(), n,
                             ipiv.data(),
                             b.data(), nrhs);

    if (info == 0) {
        std::cout << "Solution successful!" << std::endl;
        std::cout << "x = [" << b[0] << ", " << b[1] << "]" << std::endl;
        // Expected output: x = [1, 2]
    } else {
        std::cerr << "LAPACK Matrix factorization failed. Info code: " << info << std::endl;
    }

    return 0;
}
