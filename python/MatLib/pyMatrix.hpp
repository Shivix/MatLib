#ifndef MATLIB_PYMATRIX_CPP
#define MATLIB_PYMATRIX_CPP

#include <pybind11/pybind11.h>
#include "../../C++/MatLib/matrix.hpp"

namespace py = pybind11;

PYBIND11_MODULE(matrix, matrix){
    py::class_<MatLib::matrix<double, 3, 3>>(matrix, "matrix")
        .def(py::init<>());
}

#endif //MATLIB_PYMATRIX_CPP
