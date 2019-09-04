#include <iostream>

#include "matrix.h"


Matrix::Matrix(
    std::size_t nrows,
    std::size_t ncols,
    std::vector<double>& values
):
    nrows { nrows },
    ncols { ncols },
    values { values }
{};


double& Matrix::operator()(std::size_t row, std::size_t col)
{
    return values[row * nrows + col];
}


void Matrix::print()
{
    for(auto row{0} ; row < nrows; row++)
    {
        for(auto col{0}; col < ncols; col++)
        {
            std::cout << values[row * nrows + col] << ' ';
        }
        std::cout << std::endl;
    };
};
