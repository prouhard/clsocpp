#include <iostream>

#include "matrix.h"

Matrix::Matrix(
    unsigned nrows,
    unsigned ncols,
    std::vector<double> values
):
    nrows(nrows),
    ncols(ncols),
    values(values)
{};


double& Matrix::operator() (unsigned row, unsigned col) {
    return values[row * nrows + col];
}


void Matrix::print()
{
    for(unsigned row(0); row < nrows; row++)
    {
        for(unsigned col(0); col < ncols; col++)
        {
            std::cout << values[row * nrows + col] << ' ';
        }
        std::cout << std::endl;
    };
};
