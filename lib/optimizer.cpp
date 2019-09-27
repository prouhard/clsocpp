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


MatrixXd HDiff(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const std::vector<std::size_t>& constraints_lengths
)
{
    const auto k = M.rows();
    const auto m = M.cols();
    const auto n = constraints_lengths.size();
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

        const VectorBlock sliced_x_cone = x_cone.segment(current_length, current_constraint_length);
        const VectorBlock sliced_s = s.segment(current_length, current_constraint_length);

        const VectorXd omega_1_bar = sliced_x_cone + mu_i * sliced_s;
        const VectorXd omega_2_bar = sliced_x_cone * mu_i + sliced_s;
        

        const MatrixXd jordan_sym_omega_1_bar = jordanSymMatrix(omega_1_bar);
        const MatrixXd jordan_sym_omega_2_bar = jordanSymMatrix(omega_2_bar);

        const MatrixXd omega_bar_inv = jordanSymMatrix(
            phiRootTerm(
                sliced_x_cone,
                sliced_s,
                mu_i,
                current_constraint_length
            )
        ).inverse();

        const MatrixXd mu_i_identity = (1 + mu_i) * MatrixXd::Identity(current_constraint_length, current_constraint_length);
        
        N.block(
            current_length,
            current_length,
            current_constraint_length,
            current_constraint_length
        ) = mu_i_identity - (omega_bar_inv * (mu_i * jordan_sym_omega_1_bar + jordan_sym_omega_2_bar));

        M2.block(
            current_length,
            current_length,
            current_constraint_length,
            current_constraint_length
        ) =  mu_i_identity - (omega_bar_inv * (jordan_sym_omega_1_bar + mu_i * jordan_sym_omega_2_bar));

        P.block(
            current_length,
            i,
            current_constraint_length,
            1
        ) = sliced_x_cone + sliced_s - omega_bar_inv * (
            jordan_sym_omega_1_bar * sliced_s
          + jordan_sym_omega_2_bar * (
              sliced_x_cone
            + 2 * mu_i * jordanIdentity(VectorXd::Constant(1, current_constraint_length))
            )
        );
    }

    h_diff.block(m, 0, k, k) = M2;
    h_diff.block(m, k, k, m) = - N * M;
    h_diff.block(m, m + k, k, n) = P;
    h_diff.block(m + k, m + k, n, n) = MatrixXd::Identity(n, n);

    return h_diff;
}