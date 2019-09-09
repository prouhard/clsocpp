#include "jordan.h"


int main()
{
    std::vector<double> values = {3, 2, 2};
    Vector vector = Vector(3, values);
    Matrix matrix = jordanSymMatrix(vector);
    matrix.print();
    Vector e = jordanIdentity(vector);
    e.print();
    return 0;
}
