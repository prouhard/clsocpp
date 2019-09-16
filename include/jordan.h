#ifndef JORDAN_H
#define JORDAN_H

#include <Eigen/Dense>


using Eigen::MatrixXd, Eigen::VectorXd;


MatrixXd jordanSymMatrix(const VectorXd& values);

double truncatedNorm(VectorXd x, std::size_t from=1);

double firstSpectralValue(const VectorXd& x_cone);

double secondSpectralValue(const VectorXd& x_cone);

VectorXd spectralVector(const VectorXd& x_cone, int sgn);

VectorXd firstSpectralVector(const VectorXd& x_cone);

VectorXd secondSpectralVector(const VectorXd& x_cone);

VectorXd spectralDecompositionSquared(const VectorXd& x_cone);

VectorXd spectralDecompositionRoot(const VectorXd& x_cone);

VectorXd jordanIdentity(const VectorXd& kvec);

VectorXd SmoothedFischerBurmeister(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const std::vector<std::size_t>& indices
);


#endif
