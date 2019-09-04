#include <iostream>

#include "jordan.h"
#include "vector.h"


int main()
{
    std::vector<double> values = {1, 2, 3, 4};
    Vector vector = Vector(4, values);
    Matrix matrix = jordanSymMatrix(vector);
    matrix.print();
    Vector firstSpectralVector = computeFirstSpectralVector(vector);
    firstSpectralVector.print();
    return 0;
}