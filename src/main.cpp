#include <iostream>
#include <vector>
#include <filesystem>
#include <cstdlib> // for std::exit
#include <iostream>
#include <fstream>
#include <limits> // for std::numeric_limits
#include <cmath>

// Standard C-linkage header for LAPACKE
#include <lapacke.h>
// Local code
#include "include/Functions.h"
#include "src/core/CurrentSession.hpp"
#include "src/utility/Initialization.hpp"


int main() {
    core::CurrentSession currentSession{};
    //TODO [A Kronecker B] x = b
    //TODO Polinomios de Lagere (No asociados) variable x
    std::cout << "Kronecker-cpp Project" << std::endl;
    Initialization::initializer(currentSession);
    for (auto a : currentSession.xi)
    {
        std::cout << std::setprecision(17);
        std::cout << a << std::endl;
    }

    double x = 0.5;
    unsigned int n = 2;
    
    // Calculate L_2(0.5)
    double result = std::laguerre(n, x);
    std::cout << "L_" << n << "(" << x << ") = " << result << std::endl;

    return EXIT_SUCCESS;
    //[[maybe_unused]] auto var = Functions::a_t(1, 2, 3) * Functions::b_t(1, 2, 3);
    //std::cout << var << std::endl; 
    // Solve Ax = b
    // A = [ 1, 2 ]
    //     [ 3, 4 ]
    // b = [ 5, 11 ]
    //
    //int n = 2; // Matrix size (n x n)
    //int nrhs = 1; // Number of right-hand columns
//
    //std::vector<double> A = {1.0, 2.0,
    //                         3.0, 4.0};
    //std::vector<double> b = {5.0,
    //                         11.0};
//
    //// LAPACK will output the pivot indices here
    //std::vector<int> ipiv(n);
//
    //// Call LAPACKE using Row Major layout
    //int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs,
    //                         A.data(), n,
    //                         ipiv.data(),
    //                         b.data(), nrhs);
//
    //if (info == 0) {
    //    std::cout << "Solution successful!" << std::endl;
    //    std::cout << "x = [" << b[0] << ", " << b[1] << "]" << std::endl;
    //    // Expected output: x = [1, 2]
    //} else {
    //    std::cerr << "LAPACK Matrix factorization failed. Info code: " << info << std::endl;
    //}

//    std::string result = "1/2"; 
//
//    std::string text_markup = 
//        "<span size='large' foreground='#555555'>Calculation Complete</span>\\n\\n"
//        "The final result is: <span font='26' weight='bold' foreground='#1A73E8'>" + result + "</span>";
//
//    // Set custom options: window title, icon style, width/height boundaries, and disable ugly line wrapping
//    std::string command = "zenity --info "
//                          "--title=\"Kronecker Engine\" "
//                          "--window-icon=\"info\" "
//                          "--width=350 "
//                          "--no-wrap "
//                          "--text=\"" + text_markup + "\"";
//
//    // Execute directly
//    std::system(command.c_str());
//
//    return 0;
}
