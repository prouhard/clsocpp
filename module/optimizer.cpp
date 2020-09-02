#include "jordan.h"
#include "optimizer.h"

#include <iostream>


double Rho(double gamma, double norm_h)
{
    return gamma * norm_h * std::min(1., norm_h);
}

VectorXd H(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const VectorXd& b,
    const VectorXi& constraints_lengths
)
{
    VectorXd h(M.cols() + M.rows() + constraints_lengths.size());
    h << b - M.transpose() * x_cone, SmoothedFischerBurmeister(
        x_cone, s, mu, constraints_lengths
    ), mu;
    return h;
}


MatrixXd HDiff(
    const VectorXd& x_cone,
    const VectorXd& s,
    const VectorXd& mu,
    const MatrixXd& M,
    const VectorXi& constraints_lengths
)
{
    const auto k = M.rows();
    const auto m = M.cols();
    const auto n = constraints_lengths.size();
    MatrixXd h_diff = MatrixXd::Zero(m + k + n, m + k + n);
    MatrixXd N = MatrixXd::Zero(k, k);
    MatrixXd M2 = MatrixXd::Zero(k, k);
    MatrixXd P = MatrixXd::Zero(k, n);
    h_diff.block(0, 0, m, k) = - M.transpose();
    std::size_t current_length = 0;
    std::size_t current_constraint_length;
    for(
        long int i = 0;
        i != constraints_lengths.size();
        current_length += constraints_lengths[i],
        i++
    )
    {
        current_constraint_length = constraints_lengths[i];

        auto mu_i = mu[i];

        if (current_constraint_length == 1)
        {
            double x_i = x_cone[i];
            double s_i = s[i];
            double omega_1_bar_i = x_i + mu_i * s_i;
            double omega_2_bar_i = x_i * mu_i + s_i;
            double omega_bar_inv_i = 1 / std::sqrt(omega_1_bar_i * omega_1_bar_i + omega_2_bar_i * omega_2_bar_i + 2 * mu_i * mu_i);
            N(current_length, current_length) = (1 + mu_i) - (omega_bar_inv_i * (mu_i * omega_1_bar_i + omega_2_bar_i));
            M2(current_length, current_length) = (1 + mu_i) - (omega_bar_inv_i * (mu_i * omega_2_bar_i + omega_1_bar_i));
            P(current_length, i) = x_i + s_i - omega_bar_inv_i * (omega_1_bar_i * s_i + omega_2_bar_i * (x_i + 2 * mu_i));
        }
        else
        {
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
    }

    h_diff.block(m, 0, k, k) = M2;
    h_diff.block(m, k, k, m) = - N * M;
    h_diff.block(m, m + k, k, n) = P;
    h_diff.block(m + k, m + k, n, n) = MatrixXd::Identity(n, n);

    return h_diff;
}


VectorXd Solve(
    const MatrixXd& M,
    const VectorXd& b,
    const VectorXd& c,
    const VectorXi& constraints_lengths,
    const double gamma_fac,
    const double delta_0,
    const double sigma_0,
    const double mu_0,
    const double zero_tol,
    const double max_iter,
    const double min_progress
)
{
    const std::size_t k = M.rows();
    const std::size_t m = M.cols();
    const std::size_t n = constraints_lengths.size();
    double delta { delta_0 };
    double sigma { delta_0 };
    VectorXd mu = mu_0 * VectorXd::Ones(n);
    VectorXd z_bar(m + k + n);
    z_bar << VectorXd::Zero(m + k), mu;
    VectorXd x_cone = jordanIdentity(constraints_lengths);
    VectorXd y = VectorXd::Zero(m);
    VectorXd s = c - (M * y).eval();
    VectorXd h_vector = H(x_cone, s, mu, M, b, constraints_lengths);
    double norm_H { h_vector.norm() };
    double old_norm_H { norm_H + 10 * min_progress };
    double gamma { gamma_fac * std::min(1., 1 / norm_H) };
    int iteration { 0 }, last_lk { 0 };
    while (true) {
        if (norm_H < zero_tol)
        {
            break;
        }
        else if (old_norm_H - norm_H < min_progress)
        {
            std::cout << "Minimum progress not achieved" << std::endl;
            break;
        }
        else if (iteration >= max_iter)
        {
            std::cout << "Maximum number of iterations reached" << std::endl;
            break;
        }
        
        double rho = Rho(gamma, norm_H);
        int lk { last_lk };
        double delta_lk { std::pow(delta, lk) };

        // TODO : handle non invertible matrices
        VectorXd delta_z = delta_lk * HDiff(
            x_cone, s, mu, M, constraints_lengths
        ).partialPivLu().solve(
            rho * z_bar - h_vector
        );

        VectorXd newx = x_cone + delta_z.segment(0, k);
        VectorXd newy = y + delta_z.segment(k, m);
        VectorXd newmu = mu + delta_z.segment(k + m, n);
        VectorXd news = c - (M * newy).eval();
        VectorXd newH = H(newx, news, newmu, M, b, constraints_lengths);
        double newnorm_H = newH.norm();
        bool oldsign = newnorm_H <= (1 - sigma * (1 - gamma * mu_0) * delta_lk) * norm_H;
        bool done = false;
        while (!done)
        {
            if (oldsign)
            {
                if (lk == 0) break;
                lk -= 1;
                delta_z /= delta;
            }
            else 
            {
                lk += 1;
                delta_z *= delta;
            }
            delta_lk = std::pow(delta, lk);
            newx = x_cone + delta_z.segment(0, k);
            newy = y + delta_z.segment(k, m);
            newmu = mu + delta_z.segment(k + m, n);
            news = c - (M * newy).eval();
            newH = H(newx, news, newmu, M, b, constraints_lengths);
            newnorm_H = newH.norm();
            bool sign = newnorm_H <= (1 - sigma * (1 - gamma * mu_0) * delta_lk) * norm_H;
            if (sign && !oldsign) done = true;
            oldsign = sign;
        }
        last_lk = std::max(lk - 1, 0);
        x_cone = newx;
        y = newy;
        mu = newmu;
        s = news;
        h_vector = newH;
        old_norm_H = norm_H;
        norm_H = newnorm_H;
        iteration += 1;
    }
    return y;
}
 