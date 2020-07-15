#include "../MatLib/matrix.hpp"
#define BOOST_TEST_MODULE MatLib Test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiply_test)
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
            }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
             }}};
    auto resultMatrix = matrix1 * matrix2;
    MatLib::matrix<float, 3, 3> expectedMatrix = {
            {{{15, 18, 21},
                              {42, 54, 66},
                              {69, 90, 111}
            }}};
    auto resultMatrix2 = matrix1 * 5;
    MatLib::matrix<float, 3, 3> expectedMatrix2 = {
            {{{0, 5, 10},
                     {15, 20, 25},
                     {30, 35, 40}
             }}};
    BOOST_TEST(resultMatrix == expectedMatrix);
    BOOST_TEST(resultMatrix2 == expectedMatrix2);
}

BOOST_AUTO_TEST_CASE(addition_test)
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    auto resultMatrix12 = matrix1 + matrix2;
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 2, 4},
                     {6, 8, 10},
                     {12, 14, 16}
             }}};
    auto resultMatrix1S = matrix1 + 7;
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{7, 8, 9},
                     {10, 11, 12},
                     {13, 14, 15}
             }}};
    BOOST_TEST(resultMatrix12 == expectedMatrix12);
    BOOST_TEST(resultMatrix1S == expectedMatrix1S);
}

BOOST_AUTO_TEST_CASE(subtraction_test)
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    auto resultMatrix12 = matrix1 - matrix2;
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}
             }}};
    auto resultMatrix1S = matrix1 - 5;
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{-5, -4, -3},
                     {-2, -1, 0},
                     {1, 2, 3}
             }}};
    BOOST_TEST(resultMatrix12 == expectedMatrix12);
    BOOST_TEST(resultMatrix1S == expectedMatrix1S);
}

BOOST_AUTO_TEST_CASE(determinant_test, *boost::unit_test::tolerance(0.01))
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 2, 2> matrix2x2 = {
            {{{0, 1},
                     {3, 4}
             }}};
    MatLib::matrix<float, 4, 4> matrix4x4 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<int, 4, 4> matrix4x4i = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<double, 5, 5> matrix5x5 = {
            {{{5, 35, 2, 3, 39.4},
                     {12.004, 15, 12, 7, 31},
                     {24, 9, 10, 11.3, 4.4},
                     {12, 47.234, 5, 14, 14},
                     {3.32, 6, 1, 26, 5}
             }}};
    BOOST_TEST(matrix2x2.getDeterminant() == -3);
    BOOST_TEST(matrix3x3.getDeterminant() == 0);
    BOOST_TEST(matrix4x4.getDeterminant() == 14466);
    BOOST_TEST(matrix4x4i.getDeterminant() == 14466);
    BOOST_TEST(matrix5x5.getDeterminant() == 5182129.02628431);
}

BOOST_AUTO_TEST_CASE(row_echelon_test)
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{3, 4, 5},
                     {3, 1, 2},
                     {6, 7, 0}
             }}};
    auto [result3x3, isAddition] = matrix3x3.getRowEchelon();
    BOOST_TEST(result3x3 == expectedMatrix3x3);
    MatLib::matrix<int, 4, 4> matrix4x4 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<int, 4, 4> expectedMatrix4x4 = {
            {{{5, 8, 2, 3},
                     {-0, -1, 10, 4},
                     {0, 0, 27, 17},
                     {0, 0, 0, -74}
             }}};
    auto [result4x4, isAddition4x4] = matrix4x4.getRowEchelon();
    BOOST_TEST(result4x4 == expectedMatrix4x4);
}