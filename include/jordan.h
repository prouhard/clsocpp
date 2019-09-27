#ifndef JORDAN_H
#define JORDAN_H

#include <vector>
#include <Eigen/Dense>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using VectorBlock = Eigen::VectorBlock<const Eigen::VectorXd>;


MatrixXd jordanSymMatrix(const VectorXd& values);

VectorXd jordanIdentity(const VectorXd& kvec);

double truncatedNorm(VectorXd x, std::size_t from=1);

double firstSpectralValue(const VectorXd& x_cone);

double secondSpectralValue(const VectorXd& x_cone);

VectorXd spectralVector(const VectorXd& x_cone, int sgn);

VectorXd firstSpectralVector(const VectorXd& x_cone);

VectorXd secondSpectralVector(const VectorXd& x_cone);

VectorXd spectralDecompositionSquared(const VectorXd& x_cone);

VectorXd spectralDecompositionRoot(const VectorXd& x_cone);

VectorXd phiRootTerm(
    const Eigen::VectorBlock<const VectorXd>& sliced_x_cone,
    const Eigen::VectorBlock<const VectorXd>& sliced_s,
    const double mu_i,
    const std::size_t current_constraint_length
);

VectorXd SmoothedFischerBurmeister(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const std::vector<std::size_t>& constraints_lengths
);


#endif
