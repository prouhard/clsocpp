#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <Eigen/Dense>


using Eigen::MatrixXd, Eigen::VectorXd;


MatrixXd computeBlock(
    const MatrixXd& omega_bar_inv,
    const VectorXd& omega_1_bar,
    const VectorXd& omega_2_bar,
    double mu_i,
    std::size_t size,
    bool mu_i_on_1
);

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


#endif