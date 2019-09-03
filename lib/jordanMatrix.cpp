#include "jordanMatrix.h"


Matrix jordanSymMatrix(std::vector<double> x)
{
    unsigned nrows, ncols;
    nrows = ncols = x.size();
    std::vector<double> values(nrows * ncols);
    double x0 = x[0];
    values[0] = x0;
    for(unsigned i=1; i<nrows; i++)
    {
        values[i] = values[i * nrows] = x[i];
        values[i * (nrows + 1)] = x0;
    }
    return Matrix(nrows, ncols, values);
}