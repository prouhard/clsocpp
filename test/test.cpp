/********************************************************************************************************
 ********************************************************************************************************
 ** This file is temporary and is just there to store the test data for debugging / profiling purposes **
 ********************************************************************************************************
 ********************************************************************************************************/

#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include "test.h"

using namespace Eigen;

template<typename M>
M load_csv (const std::string & path) {
    std::ifstream indata;
    indata.open(path);
    std::string line;
    std::vector<double> values;
    uint rows = 0;
    while (std::getline(indata, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        while (std::getline(lineStream, cell, ',')) {
            values.push_back(std::stod(cell));
        }
        ++rows;
    }
    return Map<const Matrix<typename M::Scalar, M::RowsAtCompileTime, M::ColsAtCompileTime, RowMajor>>(values.data(), rows, values.size()/rows);
}


VectorXd getB()
{
    VectorXd b = load_csv<MatrixXd>("data/b.csv");
    return b;
}


VectorXd getC()
{
    VectorXd c = load_csv<MatrixXd>("data/c.csv");
    return c;
}


VectorXi getConstraintsLengths()
{
    VectorXi constraints_lengths(40);
    constraints_lengths << 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 19, 19, 19;
    return constraints_lengths; 
}


MatrixXd getM()
{
    MatrixXd M = load_csv<MatrixXd>("data/M.csv");
    return M;
}
