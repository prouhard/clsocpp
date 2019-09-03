#include <cmath>

#include "jordan.h"


Matrix jordanSymMatrix(const std::vector<double>& x)
{
    auto nrows = x.size(), ncols = nrows;
    std::vector<double> values(nrows * ncols);
    double x0 = x[0];
    values[0] = x0;
    for(auto i{1}; i<nrows; i++)
    {
        values[i] = values[i * nrows] = x[i];
        values[i * (nrows + 1)] = x0;
    }
    return Matrix(nrows, ncols, values);
}

double euclideanNorm(const std::vector<double>& x)
{
    double sumOfSquares = 0;
    for(const double& xi : x)
    {
        sumOfSquares += xi * xi;
    }
    return std::sqrt(sumOfSquares);
}
