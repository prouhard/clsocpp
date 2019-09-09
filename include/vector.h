#ifndef VECTOR_H
#define VECTOR_H

#include <vector>


class Vector
{
    private:
        
    public:
        std::size_t length;
        std::vector<double> values;
        Vector(
            std::size_t length,
            std::vector<double>& values
        );

        const double& operator[](std::size_t index) const;

        double& operator[](std::size_t index);

        Vector operator()(Vector& indices);

        Vector operator+(Vector vector);

        Vector operator-(Vector vector);

        double euclideanNorm(std::size_t startIndex);

        std::size_t size();

        double sum();

        void print();
};


Vector operator*(double scalar, Vector vector);


Vector operator*(Vector vector, double scalar);

#endif
