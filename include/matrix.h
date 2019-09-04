#ifndef MATRIX_H
#define MATRIX_H

#include <vector>


class Matrix
{
    private:
        std::size_t nrows;
        std::size_t ncols;
        std::vector<double> values;
    public:
        Matrix(
            std::size_t nrows,
            std::size_t ncols,
            std::vector<double>& values
        );
        double& operator() (std::size_t row, std::size_t col);
        void print();
};

#endif