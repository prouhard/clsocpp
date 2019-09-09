#include <algorithm>
#include <cmath>

#include "jordan.h"


Matrix jordanSymMatrix(Vector& xCone)
{
    auto nrows { xCone.size() }, ncols { nrows };
    std::vector<double> values(nrows * ncols);
    double xCone0 { xCone[0] };
    values[0] = xCone0;
    for(auto i{1}; i<nrows; i++)
    {
        values[i] = values[i * nrows] = xCone[i];
        values[i * (nrows + 1)] = xCone0;
    }
    return Matrix(nrows, ncols, values);
}


Vector spectralVector(Vector& xCone, int sgn)
{
    double euclideanNorm { xCone.euclideanNorm(1) };
    auto length { xCone.size() };
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
        Vector spectralVector { (sgn * 0.5 / euclideanNorm) * xCone };
        spectralVector[0] = 0.5;
        return spectralVector;
    }
}


Vector firstSpectralVector(Vector& xCone)
{
    return spectralVector(xCone, -1);
}


Vector secondSpectralVector(Vector& xCone)
{
    return spectralVector(xCone, 1); 
}


double firstSpectralValue(Vector& xCone)
{
    return xCone[0] - xCone.euclideanNorm(1);
}


double secondSpectralValue(Vector& xCone)
{
    return xCone[0] + xCone.euclideanNorm(1);
}


Vector spectralDecompositionSquared(Vector& xCone)
{
    double lambda1 { firstSpectralValue(xCone) };
    double lambda2 { secondSpectralValue(xCone) };
    return (lambda1 * lambda1) * firstSpectralVector(xCone) + (lambda2 * lambda2) * secondSpectralVector(xCone);
}

Vector spectralDecompositionRoot(Vector& xCone)
{
    double lambda1 { firstSpectralValue(xCone) };
    double lambda2 { secondSpectralValue(xCone) };
    return std::sqrt(lambda1) * firstSpectralVector(xCone) + std::sqrt(lambda2) * secondSpectralVector(xCone);
}


Vector jordanIdentity(Vector& kvec)
{
    std::size_t length = (std::size_t)kvec.sum();
    std::vector<double> _jordanIdentity(length);
    std::size_t currentIndex { 0 };
    for (auto index : kvec.values)
    {
        _jordanIdentity[currentIndex] = 1;
        currentIndex += index;
    }
    return Vector(length, _jordanIdentity);
}


Vector SmoothedFischerBurmeister(Vector& xCone, Vector& s, Vector& mu, std::vector<Vector>& indices)
{
    std::size_t length{indices.size()};
    std::vector<double> values;
    Vector phi = Vector(length, values);
    for(std::size_t i{0}; i<length; i++)
    {
        Vector slicedXCone { xCone(indices[i]) };
        Vector slicedS { s(indices[i]) };
        Vector smoothedX { slicedXCone + mu[i] * slicedS };
        Vector smoothedS { mu[i] * slicedXCone + slicedS };
        std::vector<double> _neutralE(1, indices[i].size());
        Vector neutralE { Vector(1, _neutralE) };
        Vector addedSmoothedXS { smoothedX + smoothedS + 2 * (mu[i] * mu[i]) * jordanIdentity(neutralE) };

        phi(indices[i]) = (1 + mu[i]) * (slicedXCone + slicedS) - spectralDecompositionRoot(addedSmoothedXS);
   }
   return phi;
}
