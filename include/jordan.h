#ifndef JORDAN_H
#define JORDAN_H

#include <vector>
#include <Eigen/Dense>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::VectorXi;
using VectorBlock = Eigen::VectorBlock<const Eigen::VectorXd>;


MatrixXd jordanSymMatrix(const VectorXd& values);

template<class T>
VectorXd jordanIdentity(const T& kvec)
{
    double _sum { 0 };
    for (auto i { 0 }; i != kvec.size(); i++)
    {
        _sum += kvec[i];
    }
    const std::size_t length { static_cast<std::size_t>(_sum) };
    VectorXd values = VectorXd::Zero(length);
    std::size_t current_index { 0 };
    for (auto i { 0 }; i != kvec.size(); i++)
    {
        values[current_index] = 1;
        current_index += kvec[i];
    }
    return values;
}

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
    const VectorXi& constraints_lengths
);


#endif
