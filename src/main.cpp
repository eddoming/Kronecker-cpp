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
#include "src/calculation/Calculation.hpp"
// Eigen Documentation https://libeigen.gitlab.io/eigen/docs-5.0/GettingStarted.html
#include <iostream>
#include <src/external/eigen/Eigen/Dense>

void matrixFill(core::CurrentSession& currentSession)
{
    Calculation::resizeAndZero(currentSession.dx, currentSession.nx);
    Calculation::fillDr(currentSession.dx, currentSession.nx, currentSession.xi);
}

int main()
{
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
    matrixFill(currentSession);
    std::cout << currentSession.dx << std::endl;

    return EXIT_SUCCESS;
}
