#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include <Eigen/Dense>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using VectorBlock = Eigen::VectorBlock<const Eigen::VectorXd>;


double Rho(double gamma, double norm_h);

VectorXd H(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const VectorXd& b,
    const std::vector<std::size_t>& constraints_lengths
);

MatrixXd HDiff(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const std::vector<std::size_t>& constraints_lengths
);

struct OptimizationResult
{
    VectorXd x;
    VectorXd y;
    VectorXd s;
    int code;
};

VectorXd Solve(
    const MatrixXd& M,
    const VectorXd& b,
    const VectorXd& c,
    const std::vector<std::size_t>& constraints_lengths,
    const double gamma_fac=0.95,
    const double delta0=0.75,
    const double sigma0=0.25,
    const double mu0=0.01,
    const double zero_tol=1e-06,
    const double max_iter=100,
    const double min_progress=1e-08
);


#endif