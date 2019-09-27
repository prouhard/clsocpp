#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <vector>
#include <Eigen/Dense>


using Eigen::MatrixXd;
using Eigen::VectorXd;
using VectorBlock = Eigen::VectorBlock<const Eigen::VectorXd>;


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