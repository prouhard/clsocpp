#include <iostream>

#include "jordan.h"
#include "vector.h"


int main()
{
    std::vector<double> values = {1, 2, 3, 4};
    Vector vector = Vector(4, values);
    Matrix matrix = jordanSymMatrix(vector);
    matrix.print();
    Vector decomposedVector = spectralDecomposition(vector);
    decomposedVector.print();
    return 0;
}
