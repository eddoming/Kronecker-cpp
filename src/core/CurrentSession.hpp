#pragma once

namespace core {

struct CurrentSession
{
    int data {0};
    int nx{0};
    int ny{0};
    std::vector<double> xi;
    std::vector<double> yi;
};
}
