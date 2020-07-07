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


