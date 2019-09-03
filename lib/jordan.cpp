#include <algorithm>
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


double euclideanNorm(const std::vector<double>& x, unsigned startIndex)
{
    double sumOfSquares = 0;
    for(auto xi{x.begin()+startIndex}; xi<x.end(); ++xi) sumOfSquares += *xi * *xi;
    return std::sqrt(sumOfSquares);
}

std::vector<double> _getU(const std::vector<double>& x, int sgn)
{
    double _euclideanNorm = euclideanNorm(x, 1);
    auto n = x.size();
    if (_euclideanNorm < 1e-12)
    {
        if (n > 1)
        {
            std::vector<double> _u(n, sgn * 0.5 * std::sqrt(1.0 / (n - 1)));
            _u[0] = 0.5;
            return _u;
        }
        else return std::vector<double>(1, 0.5);
    }
    else 
    {
        std::vector<double> _u = x;
        double coefficient = sgn * 0.5 / _euclideanNorm;
        std::transform(_u.begin(), _u.end(), _u.begin(), [coefficient](double& c){return c * coefficient;});
        _u[0] = 0.5;
        return _u;
    }
}


std::vector<double> getU1(const std::vector<double>& x) {return _getU(x, -1);}


std::vector<double> getU2(const std::vector<double>& x) {return _getU(x, 1);}


double lambda1(const std::vector<double>& x) { return x[0] - euclideanNorm(x, 1); }


double lambda2(const std::vector<double>& x) { return x[0] + euclideanNorm(x, 1); }