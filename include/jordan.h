#ifndef JORDAN_H
#define JORDAN_H

#include "matrix.h"
#include "vector.h"


Matrix jordanSymMatrix(Vector& values);

double firstSpectralValue(Vector& xCone);

double secondSpectralValue(Vector& xCone);

Vector spectralVector(Vector& xCone, int sgn);

Vector firstSpectralVector(Vector& xCone);

Vector secondSpectralVector(Vector& xCone);

Vector spectralDecompositionSquared(Vector& xCone);

Vector spectralDecompositionRoot(Vector& xCone);

Vector jordanIdentity(Vector& kvec);

Vector SmoothedFischerBurmeister(Vector& xCone, Vector& s, Vector& mu, Vector& indices);


#endif
