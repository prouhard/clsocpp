#ifndef MATRIX_H
#define MATRIX_H

#include <vector>


class Matrix
{
    private:
        unsigned nrows;
        unsigned ncols;
        std::vector<double> values;
    public:
        Matrix(
            unsigned nrows,
            unsigned ncols,
            const std::vector<double>& values
        );
        double& operator() (unsigned row, unsigned col);
        void print();
};

#endif