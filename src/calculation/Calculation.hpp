namespace Calculation
{

    void resizeAndZero(Eigen::MatrixXd &currentMatrix, int size)
    {
        // currentMatrix = Eigen::MatrixXd::Identity(currentSession.nx, currentSession.nx);
        currentMatrix.resize(size, size);
        currentMatrix.setZero();
    }

    double laguerre(int n, double x)
    {
        return std::laguerre(n, x);
    }

    double dlaguerre(int n, double x)
    {
        if ((n > 0) && (x > 0.00000000000000001))
        {
            // return ((n * laguerre(n, x) - (n * laguerre(n - 1, x))) / x);
            return ((n * laguerre(n - 1, x)) / x);
        }
        else
        {
            std::exit(1);
            return 0.0;
        }
    }

    void fillDr(Eigen::MatrixXd &currentMatrix, int n_r, std::vector<double> &xr)
    {
        // Fill
        double r_i{0};
        double r_k{0};

        for (int i{0}; i < n_r; i++)
        {
            r_i = xr[i];
            for (int k{0}; k < n_r; k++)
            {
                r_k = xr[k];
                if (k != i)
                {
                    currentMatrix(i, k) = ((r_i) / ((r_k) * (r_i - r_k))) * ((dlaguerre(n_r, r_i)) / (dlaguerre(n_r, r_k)));
                }
                else
                {
                    currentMatrix(i, k) = (r_i + 1) / (2 * r_i);
                }
            }
        }
    }
}