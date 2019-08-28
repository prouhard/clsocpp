#include <iostream>
#include <vector>

#include "matrix.h"

Matrix::Matrix(
    unsigned nrows,
    unsigned ncols,
    std::vector<float> values
):
    nrows(nrows),
    ncols(ncols),
    values(values)
{};


float& Matrix::operator() (unsigned row, unsigned col) {
    return values[row * nrows + col];
}


void Matrix::print()
{
    for(unsigned row(0); row < nrows; row++)
    {
        for(unsigned col(0); col < ncols; col++)
        {
            std::cout << values[row * nrows + col] << std::endl;
        }
    };
};
