#include <iostream>
#include <vector>

#include "matrix.h"

int main()
{
    std::vector<float> values = {1, 2, 3, 4};
    unsigned nrows = 2;
    unsigned ncols = 2;
    Matrix matrix(nrows, ncols, values);
    matrix.print();
    return 0;
}