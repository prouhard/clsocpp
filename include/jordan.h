#ifndef JORDAN_H
#define JORDAN_H

#include "matrix.h"


Matrix jordanSymMatrix(const std::vector<double>& values);

double euclideanNorm(const std::vector<double>& x, unsigned startIndex=0);

double lambda1(const std::vector<double>& x);

double lambda2(const std::vector<double>& x);

std::vector<double> u1(const std::vector<double>& x, int sgn);

std::vector<double> getU1(const std::vector<double>& x);

std::vector<double> getU2(const std::vector<double>& x);


#endif