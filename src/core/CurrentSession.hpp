#pragma once
#include <src/external/eigen/Eigen/Dense>

namespace core {

struct CurrentSession
{
    int data {0};
    int nx{0};
    int ny{0};
    std::vector<double> xi;
    std::vector<double> yi;
    Eigen::MatrixXd dx;
    Eigen::MatrixXd dxx;
    Eigen::MatrixXd dy;
    Eigen::MatrixXd dyy;
};
}
