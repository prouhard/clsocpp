#include "jordan.h"
#include "optimizer.h"

#include <iostream>


VectorXd H(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const VectorXd& b,
    const std::vector<std::size_t>& constraints_lengths
)
{
    VectorXd h(M.cols() + M.rows() + constraints_lengths.size());
    h << b - M * x_cone, SmoothedFischerBurmeister(
        x_cone, s, mu, constraints_lengths
    ), mu;
    return h;
}


MatrixXd computeBlock(
    const MatrixXd& omega_bar_inv,
    const VectorXd& omega_1_bar,
    const VectorXd& omega_2_bar,
    double mu_i,
    std::size_t size,
    bool mu_i_on_1
)
{
    auto temp_matrix = mu_i_on_1 ?
        jordanSymMatrix(omega_2_bar) + mu_i * jordanSymMatrix(omega_1_bar)
      : jordanSymMatrix(omega_1_bar) + mu_i * jordanSymMatrix(omega_2_bar);
    return (1 + mu_i) * MatrixXd::Identity(size, size) - (omega_bar_inv * temp_matrix).eval();
}


MatrixXd HDiff(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const std::vector<std::size_t>& constraints_lengths
)
{
    auto k = M.rows();
    auto m = M.cols();
    auto n = constraints_lengths.size();
    MatrixXd h_diff(m + k + n, m + k + n);
    MatrixXd N = MatrixXd::Zero(k, k);
    MatrixXd M2 = MatrixXd::Zero(k, k);
    MatrixXd P = MatrixXd::Zero(k, n);
    h_diff.block(0, 0, k, m) = - M;
    std::size_t current_length = 0;
    std::size_t current_constraint_length;
    for(
        std::size_t i = 0;
        i != constraints_lengths.size();
        current_length += constraints_lengths[i],
        i++
    )
    {
        current_constraint_length = constraints_lengths[i];
        auto mu_i = mu[i];
        auto sliced_x_cone = x_cone.segment(current_length, current_constraint_length);
        auto sliced_s = s.segment(current_length, current_constraint_length);
        auto omega_1_bar = sliced_x_cone + mu_i * sliced_s;
        auto omega_2_bar = sliced_x_cone * mu_i + sliced_s;
        
        auto omega_bar_inv = jordanSymMatrix(
            phiRootTerm(
                sliced_x_cone,
                sliced_s,
                mu_i,
                current_constraint_length
            )
        ).inverse();

        M2.block(current_length, current_length, current_constraint_length, current_constraint_length) = computeBlock(
            omega_bar_inv,
            omega_1_bar,
            omega_2_bar,
            mu_i,
            current_constraint_length,
            false
        );
    }
    return M2;
}