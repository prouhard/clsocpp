#ifndef MATRIX_H
#define MATRIX_H

#include <vector>


class Matrix
{
    private:
        unsigned nrows;
        unsigned ncols;
        std::vector<float> values;
    public:
        Matrix(
            unsigned nrows,
            unsigned ncols,
            std::vector<float> values
        );
        float& operator() (unsigned row, unsigned col);
        void print();
};

#endif