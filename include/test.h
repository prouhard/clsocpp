#ifndef TEST_H
#define TEST_H

#include <Eigen/Dense>
#include <vector>


using Eigen::MatrixXd;
using Eigen::VectorXd;


VectorXd getB();

VectorXd getC();

std::vector<std::size_t> getConstraintsLengths();

MatrixXd getM();

#endif