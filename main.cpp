#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <time.h>

#include "optimizer.h"
#include "test.h"


int main()
{

    VectorXd b = getB();
    VectorXd c = getC();
    MatrixXd M = getM();
    std::vector<std::size_t> constraints_lengths = getConstraintsLengths();

    // clock_t start, end; 
    // start = clock();

    // constexpr int times { 1000 };

    // for (int i {0}; i != times; i++)
    // {
    //     HDiff(x_cone, s, mu, M, constraints_lengths);
    // }

    // end = clock();

    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 

    // std::cout << std::setprecision(10) << "Time taken by one iteration is : " << std::fixed  
    //      << time_taken / double(times); 
    // std::cout << " sec " << std::endl;

    VectorXd result = Solve(M, b, c, constraints_lengths);

    std::cout << result << std::endl;

    return 0; 
}