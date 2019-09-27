#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <time.h>

#include "optimizer.h"


int main()
{
    VectorXd x_cone(5);
    x_cone << 0.1, 0.2, 0.3, 0.4, 0.5;

    VectorXd s(5);
    s << 0.6, 0.7, 0.8, 0.9, 1;

    VectorXd mu(3);
    mu << 0.5, 0.2, 0.3;

    MatrixXd M(5, 4);
    M << 0.2, 0.1, 0.2, 0.3,
         0.3, 0.4, 0.1, 0.2,
         0.1, 0.2, 0.3, 0.4,
         0.1, 0.3, 0.2, 0.4,
         0.4, 0.2, 0.4, 0.1;

    VectorXd b(4);
    b << 0.1, 0.1, 0.3, 0.2;

    std::vector<std::size_t> constraints_lengths = {2, 2, 1};

    clock_t start, end; 
    start = clock();

    constexpr int times { 1000 };

    for (int i {0}; i != times; i++)
    {
        HDiff(x_cone, s, mu, M, constraints_lengths);
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 

    std::cout << std::setprecision(10) << "Time taken by one iteration is : " << std::fixed  
         << time_taken / double(times); 
    std::cout << " sec " << std::endl;

    std::cout << HDiff(x_cone, s, mu, M, constraints_lengths) << std::endl;

    return 0; 
}