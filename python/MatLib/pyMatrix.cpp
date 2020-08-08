#ifndef MATLIB_PYMATRIX_CPP
#define MATLIB_PYMATRIX_CPP

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "../../cpp/MatLib/matrix.hpp"

namespace py = pybind11;
using matrix2x2 = MatLib::matrix<double, 2, 2>;
using matrix3x3 = MatLib::matrix<double, 3, 3>;

PYBIND11_MODULE(matrix2x2, matrix2){
    py::class_<matrix2x2>(matrix2, "matrix2")
        .def(py::init<>())
        .def("empty", &matrix2x2::empty, "Returns true if the matrix has a size of 0")
        .def("fill", &matrix2x2::fill, "Fills the matrix with a single value")
        .def("getAugment", &matrix2x2::getAugment, "Calculates and returns augmented matrix")
        .def("getDeterminant", &matrix2x2::getDeterminant, "Calculates and returns augmented matrix")
        .def("getIdentity", &matrix2x2::getIdentity, "Calculates and returns augmented matrix")
        .def("getInverse", &matrix2x2::getInverse, "Calculates and returns augmented matrix")
        .def("getRowEchelon", &matrix2x2::getRowEchelon, "Calculates and returns augmented matrix")
        .def("getTranspose", &matrix2x2::getTranspose, "Calculates and returns augmented matrix")
        .def("isOrthogonal", &matrix2x2::isOrthogonal, "Calculates and returns augmented matrix")
        .def("size", &matrix2x2::size, "Calculates and returns augmented matrix")
        .def("swap", &matrix2x2::swap, "Calculates and returns augmented matrix")
        .def(py::self + matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self + double(), "Calculates and returns augmented matrix")
        .def(py::self * matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self * double(), "Calculates and returns augmented matrix")
        .def(py::self / double(), "Calculates and returns augmented matrix")
        //.def(py::self / matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self - double(), "Calculates and returns augmented matrix")
        .def(py::self - matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self += matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self += double(), "Calculates and returns augmented matrix")
        .def(py::self * matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self * double(), "Calculates and returns augmented matrix")
        .def(py::self /= matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self /= double(), "Calculates and returns augmented matrix")
        .def(py::self -= matrix2x2(), "Calculates and returns augmented matrix")
        .def(py::self -= double(), "Calculates and returns augmented matrix")
        //.def(-py::self, "Calculates and returns augmented matrix");
        .def("__iter__", [](const matrix2x2& matrix){
            return py::make_iterator(matrix.begin(), matrix.end());
        });
        //.def("at", &matrix2x2::at, "Calculates and returns augmented matrix");
}

PYBIND11_MODULE(matrix3x3, matrix3){
    py::class_<matrix3x3>(matrix3, "matrix3")
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
            .def(py::self + matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self + double(), "Calculates and returns augmented matrix")
            .def(py::self * matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self * double(), "Calculates and returns augmented matrix")
            .def(py::self / double(), "Calculates and returns augmented matrix")
            //.def(py::self / matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self - double(), "Calculates and returns augmented matrix")
            .def(py::self - matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self += matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self += double(), "Calculates and returns augmented matrix")
            .def(py::self * matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self * double(), "Calculates and returns augmented matrix")
            .def(py::self /= matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self /= double(), "Calculates and returns augmented matrix")
            .def(py::self -= matrix3x3(), "Calculates and returns augmented matrix")
            .def(py::self -= double(), "Calculates and returns augmented matrix")
            //.def(-py::self, "Calculates and returns augmented matrix");
            .def("__iter__", [](const matrix3x3& matrix){
                return py::make_iterator(matrix.begin(), matrix.end());
            });
    //.def("at", &matrix3x3::at, "Calculates and returns augmented matrix");
}

#endif //MATLIB_PYMATRIX_CPP