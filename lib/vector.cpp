#include <algorithm>
#include <cmath>
#include <iostream>

#include "vector.h"


Vector::Vector(
    std::size_t length,
    std::vector<double>& values
):
    length { length },
    values { values }
{};


const double& Vector::operator[](std::size_t index) const
{
    return values[index];
}


double& Vector::operator[](std::size_t index)
{
    return values[index];
}


double Vector::euclideanNorm(std::size_t startIndex)
{
    double sumOfSquares = 0;
    for(auto xi{values.begin()+startIndex}; xi<values.end(); ++xi) sumOfSquares += *xi * *xi;
    return std::sqrt(sumOfSquares);
}


std::size_t Vector::size(){return values.size();}


void Vector::print()
{
    for(auto element : values)
    {
        std::cout << element << ' ' << std::endl;
    };
};


Vector operator*(double scalar, Vector& vector)
{
    std::vector<double> multipliedVector(vector.length);
    std::transform(vector.values.begin(), vector.values.end(), multipliedVector.begin(), [scalar](double& c){ return c * scalar; });
    return Vector(vector.length, multipliedVector);
}


Vector operator*(Vector& vector, double scalar)
{
    return scalar * vector;
}
