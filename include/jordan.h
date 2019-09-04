#ifndef JORDAN_H
#define JORDAN_H

#include "matrix.h"
#include "vector.h"


Matrix jordanSymMatrix(Vector& values);

double euclideanNorm(Vector& x, std::size_t startIndex=0);

double computeFirstSpectralValue(Vector& x);

double computeSecondSpectralValue(Vector& x);

Vector computeSpectralVector(Vector& x, int sgn);

Vector computeFirstSpectralVector(Vector& x);

Vector computeSecondSpectralVector(Vector& x);


#endif