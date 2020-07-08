#include <iostream>
#include <algorithm>
#include "../MatLib/matrix.hpp"
#define BOOST_TEST_MODULE MatLib Test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiply_test)
{
    MatLib::matrix<int, 3, 3> matrix1 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
            }}};
    MatLib::matrix<int, 3, 3> matrix2 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
             }}};
    auto resultMatrix = matrix1 * matrix2;
    MatLib::matrix<int, 3, 3> expectedMatrix = {
            {{{15, 18, 21},
                              {42, 54, 66},
                              {69, 90, 111}
            }}};
    BOOST_TEST(resultMatrix == expectedMatrix);
}

BOOST_AUTO_TEST_CASE(determinant_test)
{
    MatLib::matrix<int, 3, 3> matrix1 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<int, 2, 2> matrix2 = {
            {{{0, 1},
                     {3, 4}
             }}};
    MatLib::matrix<int, 4, 4> matrix3 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    BOOST_TEST(matrix2.getDeterminant() == -3);
    BOOST_TEST(matrix1.getDeterminant() == 0);
    BOOST_TEST(matrix3.getDeterminant() == 14466);
}
