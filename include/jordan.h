#ifndef JORDAN_H
#define JORDAN_H

#include "matrix.h"
#include "vector.h"


Matrix jordanSymMatrix(Vector& values);

double firstSpectralValue(Vector& x);

double secondSpectralValue(Vector& x);

Vector spectralVector(Vector& x, int sgn);

Vector firstSpectralVector(Vector& x);

Vector secondSpectralVector(Vector& x);

Vector spectralDecomposition(Vector& x);


#endif
