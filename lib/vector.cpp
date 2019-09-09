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


Vector Vector::operator()(Vector& indices){
    std::size_t length { indices.size() };
    std::vector<double> subVectorValues(length);
    Vector subVector(indices.size(), subVectorValues);
    size_t subIndex = 0;
    for(
        std::vector<double>::iterator xIndex { indices.values.begin() };
        xIndex != indices.values.end();
        ++xIndex, subIndex++
    )
    {
        subVector[subIndex] = values[*xIndex];
    }
    return subVector;
}


Vector Vector::operator+(Vector vector)
{
    Vector addedVectors = Vector(length, values);
    for(auto i { 0 }; i != length; i++)
    {
        addedVectors[i] += vector[i];
    }
    return addedVectors;
}


Vector Vector::operator-(Vector vector)
{
    Vector substractedVectors = Vector(length, values);
    for(auto i { 0 }; i != length; i++)
    {
        substractedVectors[i] -= vector[i];
    }
    return substractedVectors;
}


double Vector::euclideanNorm(std::size_t startIndex)
{
    double sumOfSquares { 0 };
    for(auto xi { values.begin() + startIndex }; xi != values.end(); ++xi)
    {
        sumOfSquares += *xi * *xi;
    }
    return std::sqrt(sumOfSquares);
}


std::size_t Vector::size()
{
    return values.size();
}

double Vector::sum()
{
    double runningSum { 0 };
    for (auto element : values)
    {
        runningSum += element;
    }
    return runningSum;
}


void Vector::print()
{
    for(auto element : values)
    {
        std::cout << element << ' ' << std::endl;
    };
};


Vector operator*(double scalar, Vector vector)
{
    std::vector<double> multipliedVector(vector.length);
    std::transform(
        vector.values.begin(),
        vector.values.end(),
        multipliedVector.begin(),
        [scalar](double& c)
        {
            return c * scalar;
        }
    );
    return Vector(vector.length, multipliedVector);
}


Vector operator*(Vector vector, double scalar)
{
    return scalar * vector;
}
