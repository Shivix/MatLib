#ifndef MATLIB_PYMATRIX_CPP
#define MATLIB_PYMATRIX_CPP

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "../../cpp/MatLib/matrix.hpp"

namespace py = pybind11;
using matrix2x2 = MatLib::matrix<double, 2, 2>;
using matrix3x3 = MatLib::matrix<double, 3, 3>;

PYBIND11_MODULE(matrix, matrix){
    py::class_<matrix3x3>(matrix, "matrix")
        .def(py::init<>())
        .def("empty", &matrix3x3::empty, "Returns true if the matrix has a size of 0")
        .def("fill", &matrix3x3::fill, "Fills the matrix with a single value")
        .def("getAugment", &matrix3x3::getAugment, "Calculates and returns augmented matrix")
        .def("getDeterminant", &matrix3x3::getDeterminant, "Calculates and returns augmented matrix")
        .def("getIdentity", &matrix3x3::getIdentity, "Calculates and returns augmented matrix")
        .def("getInverse", &matrix3x3::getInverse, "Calculates and returns augmented matrix")
        .def("getRowEchelon", &matrix3x3::getRowEchelon, "Calculates and returns augmented matrix")
        .def("getTranspose", &matrix3x3::getTranspose, "Calculates and returns augmented matrix")
        .def("isOrthogonal", &matrix3x3::isOrthogonal, "Calculates and returns augmented matrix")
        .def("size", &matrix3x3::size, "Calculates and returns augmented matrix")
        .def("swap", &matrix3x3::swap, "Calculates and returns augmented matrix")
        .def(py::self + py::self, "Calculates and returns augmented matrix")
        .def(py::self + double(), "Calculates and returns augmented matrix")
        .def(py::self * py::self, "Calculates and returns augmented matrix")
        .def(py::self * double(), "Calculates and returns augmented matrix")
        .def(py::self / double(), "Calculates and returns augmented matrix")
        .def(py::self / py::self, "Calculates and returns augmented matrix")
        .def(py::self - double(), "Calculates and returns augmented matrix")
        .def(py::self - py::self, "Calculates and returns augmented matrix")
        .def(py::self += py::self, "Calculates and returns augmented matrix")
        .def(py::self += double(), "Calculates and returns augmented matrix")
        .def(py::self * py::self, "Calculates and returns augmented matrix")
        .def(py::self * double(), "Calculates and returns augmented matrix")
        .def(py::self /= py::self, "Calculates and returns augmented matrix")
        .def(py::self /= double(), "Calculates and returns augmented matrix")
        .def(py::self -= py::self, "Calculates and returns augmented matrix")
        .def(py::self -= double(), "Calculates and returns augmented matrix")
        .def(-py::self, "Calculates and returns augmented matrix");
        //.def("data", &matrix3x3::data, "Calculates and returns augmented matrix")
        //.def("at", &matrix3x3::at, "Calculates and returns augmented matrix")
}

#endif //MATLIB_PYMATRIX_CPP