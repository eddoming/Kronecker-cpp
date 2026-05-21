#include "Functions.h"

namespace Functions {

    double a_t(double t1, double t2, double t3)
    {
        return ((2 * t1) * (t2 * t2 + t3 * t3 + t1 * (t2 + t3))) / ((t1 + t2) * (t1 + t3) * (t2 + t3));
    }

    double b_t(double t1, double t2, double t3)
    {
        return ((2 * t2) * (2 * t1 * t1 + (2 * t1 + t3) * (t2 + t3))) / ((t1 + t2) * (t1 + t3) * (t2 + t3));
    }

    double c_t(double t1, double t2, double t3)
    {
        return ((4 * t1 * t2) / ((t1 + t3) * (t2 + t3)));
    }

    double d_t(double t1, double t2, double t3)
    {
        return (-2 / (t1 + t2) - 2 / (t1 + t3) + 4 / (t2 + t3));
    }

    double e_t(double t1, double t2, double t3)
    {
        return (-2 / (t1 + t2) + 2 / (t1 + t3) + 4 / (t2 + t3));
    }

}