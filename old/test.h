#ifndef TEST_H
#define TEST_H

#include <Eigen/Dense>
#include <vector>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;


VectorXd getB();

VectorXd getC();

VectorXi getConstraintsLengths();

MatrixXd getM();

#endif