#include <iostream>
#include <Eigen/Dense>

#include "jordan.h"


int main()
{
    VectorXd xCone(5);
    xCone << 0.1, 0.2, 0.3, 0.4, 0.5;
    VectorXd s(5);
    s << 0.6, 0.7, 0.8, 0.9, 1;
    VectorXd mu(3);
    mu << 0.5, 0.2, 0.3;
    std::vector<std::size_t> constraints_lengths = {2, 2, 1};
    VectorXd result = SmoothedFischerBurmeister(xCone, s, mu, constraints_lengths);
    std::cout << result << std::endl;
}