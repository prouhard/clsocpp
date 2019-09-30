#include <algorithm>
#include <cmath>
#include <iostream>

#include "jordan.h"


MatrixXd jordanSymMatrix(const VectorXd& x_cone)
{
    const auto nrows = x_cone.size();
    MatrixXd values(nrows, nrows);
    double x_cone0 { x_cone[0] };
    values(0, 0) = x_cone0;
    for(auto i = 1; i < nrows; i++)
    {
        values(0, i) = values(i, 0) = x_cone[i];
        values(i, i) = x_cone0;
    }
    return values;
}


double truncatedNorm(VectorXd x, std::size_t from)
{
    return x.tail(x.size() - from).norm();
}


VectorXd spectralVector(const VectorXd& x_cone, int sgn)
{
    const double euclidean_norm { truncatedNorm(x_cone) };
    const auto length = x_cone.size();
    VectorXd values(length);
    if (euclidean_norm < 1e-12)
    {
        if (length > 1)
        {
            auto coefficient = sgn * 0.5 * std::sqrt(1.0 / (length - 1));
            values << 0.5, VectorXd::Constant(length - 1, coefficient);
            return values;
        }
        else 
        {
            return VectorXd::Constant(1, 0.5);
        }
    }
    else 
    {
        values = (sgn * 0.5 / euclidean_norm) * x_cone;
        values[0] = 0.5;
        return values;
    }
}


VectorXd firstSpectralVector(const VectorXd& x_cone)
{
    return spectralVector(x_cone, -1);
}


VectorXd secondSpectralVector(const VectorXd& x_cone)
{
    return spectralVector(x_cone, 1); 
}


double firstSpectralValue(const VectorXd& x_cone)
{
    return x_cone[0] - truncatedNorm(x_cone);
}


double secondSpectralValue(const VectorXd& x_cone)
{
    return x_cone[0] + truncatedNorm(x_cone);
}


VectorXd spectralDecompositionSquared(const VectorXd& x_cone)
{
    const double lambda_1 { firstSpectralValue(x_cone) };
    const double lambda_2 { secondSpectralValue(x_cone) };
    return (lambda_1 * lambda_1) * firstSpectralVector(x_cone) + (lambda_2 * lambda_2) * secondSpectralVector(x_cone);
}

VectorXd spectralDecompositionRoot(const VectorXd& x_cone)
{
    
    const double lambda_1 { firstSpectralValue(x_cone) };
    const double lambda_2 { secondSpectralValue(x_cone) };
    return std::sqrt(lambda_1) * firstSpectralVector(x_cone) + std::sqrt(lambda_2) * secondSpectralVector(x_cone);
}


VectorXd phiRootTerm(
    const Eigen::VectorBlock<const VectorXd>& sliced_x_cone,
    const Eigen::VectorBlock<const VectorXd>& sliced_s,
    const double mu_i,
    const std::size_t current_constraint_length
)
{
    return spectralDecompositionRoot(
        spectralDecompositionSquared(sliced_x_cone + mu_i * sliced_s)
        + spectralDecompositionSquared(mu_i * sliced_x_cone + sliced_s)
        + 2 * (mu_i * mu_i) * jordanIdentity(VectorXd::Constant(1, current_constraint_length))
    );
}


VectorXd SmoothedFischerBurmeister(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const std::vector<std::size_t>& constraints_lengths
)
{
    VectorXd phi(x_cone.size());
    std::size_t current_length { 0 };
    std::size_t current_constraint_length;
    for(
        std::size_t i { 0 };
        i != constraints_lengths.size();
        current_length += constraints_lengths[i],
        i++
    )
    {
        current_constraint_length = constraints_lengths[i];

        const VectorBlock sliced_x_cone = x_cone.segment(current_length, current_constraint_length);
        const VectorBlock sliced_s = s.segment(current_length, current_constraint_length);
        
        phi.segment(current_length, current_constraint_length) = (1 + mu[i]) * (sliced_x_cone + sliced_s) - phiRootTerm(
            sliced_x_cone,
            sliced_s,
            mu[i],
            current_constraint_length
        );
   }
   return phi;
}
