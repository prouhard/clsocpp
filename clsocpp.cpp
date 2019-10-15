#include "optimizer.h"

#include <Eigen/Dense>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>


PYBIND11_MODULE(clsocpp, m) {
    m.doc() = "CLSOCPP solver.";

    m.def(
        "Solve",
        &Solve,
        pybind11::arg("M"),
        pybind11::arg("b"),
        pybind11::arg("c"),
        pybind11::arg("constraints_lengths"),
        pybind11::arg("gamma_fac")    = 0.95,
        pybind11::arg("delta0")       = 0.75,
        pybind11::arg("sigma0")       = 0.25,
        pybind11::arg("mu0")          = 0.01,
        pybind11::arg("zero_tol")     = 1e-06,
        pybind11::arg("max_iter")     = 100,
        pybind11::arg("min_progress") = 1e-08
    );
}