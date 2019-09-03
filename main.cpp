#include "jordanMatrix.h"


int main()
{
    std::vector<double> values = {1, 2, 3, 4};
    Matrix matrix = jordanSymMatrix(values);
    matrix.print();
    return 0;
}