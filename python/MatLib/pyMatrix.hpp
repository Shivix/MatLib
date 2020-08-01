#ifndef MATLIB_PYMATRIX_CPP
#define MATLIB_PYMATRIX_CPP

#include <pybind11/pybind11.h>
#include "../../cpp/MatLib/matrix.hpp"

namespace py = pybind11;
using matrix2x2 = MatLib::matrix<double, 2, 2>;
using matrix3x3 = MatLib::matrix<double, 3, 3>;

PYBIND11_MODULE(matrix, matrix){
    py::class_<matrix3x3>(matrix, "matrix")
        .def(py::init<>())
        .def("empty", &matrix3x3::empty, "Returns true if the matrix has a size of 0");
}

#endif //MATLIB_PYMATRIX_CPP
