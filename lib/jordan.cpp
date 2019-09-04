#include <algorithm>
#include <cmath>

#include "jordan.h"


Matrix jordanSymMatrix(Vector& xCone)
{
    auto nrows = xCone.size(), ncols = nrows;
    std::vector<double> values(nrows * ncols);
    double xCone0 = xCone[0];
    values[0] = xCone0;
    for(auto i{1}; i<nrows; i++)
    {
        values[i] = values[i * nrows] = xCone[i];
        values[i * (nrows + 1)] = xCone0;
    }
    return Matrix(nrows, ncols, values);
}


Vector computeSpectralVector(Vector& xCone, int sgn)
{
    double euclideanNorm = xCone.euclideanNorm(1);
    auto length = xCone.size();
    if (euclideanNorm < 1e-12)
    {
        if (length > 1)
        {
            std::vector<double> spectralVector(length, sgn * 0.5 * std::sqrt(1.0 / (length - 1)));
            spectralVector[0] = 0.5;
            return Vector(length, spectralVector);
        }
        else 
        {
            std::vector<double> spectralVector{0.5};
            return Vector(length, spectralVector);
        }
    }
    else 
    {
        Vector spectralVector = (sgn * 0.5 / euclideanNorm) * xCone;
        spectralVector[0] = 0.5;
        return spectralVector;
    }
}


Vector computeFirstSpectralVector(Vector& xCone) { return computeSpectralVector(xCone, -1); }


Vector computeSecondSpectralVector(Vector& xCone) { return computeSpectralVector(xCone, 1); }


double computeFirstSpectralValue(Vector& xCone) { return xCone[0] - xCone.euclideanNorm(1); }


double computeSecondSpectralValue(Vector& xCone) { return xCone[0] + xCone.euclideanNorm(1); }
