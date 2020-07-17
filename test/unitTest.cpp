#include "../MatLib/matrix.hpp"
#define BOOST_TEST_MODULE MatLib Test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiply_test) // NOLINT
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
    MatLib::matrix<int, 3, 3> matrix1i = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<int, 3, 3> matrix2i = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix = {
            {{{15, 18, 21},
                              {42, 54, 66},
                              {69, 90, 111}
            }}};
    MatLib::matrix<int, 3, 3> expectedMatrixi = {
            {{{15, 18, 21},
                     {42, 54, 66},
                     {69, 90, 111}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix2 = {
            {{{0, 5, 10},
                     {15, 20, 25},
                     {30, 35, 40}
             }}};
    BOOST_TEST((matrix1 * matrix2) == expectedMatrix);
    BOOST_TEST((matrix1i * matrix2i) == expectedMatrixi);
    BOOST_TEST((matrix1 * 5) == expectedMatrix2);
}

BOOST_AUTO_TEST_CASE(divide_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{10, 11, 12},
                     {13, 14, 15},
                     {16, 17, 18}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{7, 6, 7},
                     {3, 7, 5},
                     {14, 15, 16}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix = {
            {{{-1.2, -0.4, 1.4},
                     {-0.3, -0.1, 1.1},
                     {0.6, 0.2, 0.8}
             }}};
    MatLib::matrix<double, 3, 3> matrix3 = {
                    {{{10, 15, 20},
                             {5, 6, 8},
                             {14, 7, 88}
                     }}};
    MatLib::matrix<double, 3, 3> expectedMatrix2 = {
            {{{2, 3, 4},
                     {1, 1.2, 1.6},
                     {2.8, 1.4, 17.6}
             }}};
    BOOST_TEST((matrix1 / matrix2) == expectedMatrix);
    BOOST_TEST((matrix3 / 5) == expectedMatrix2);
}

BOOST_AUTO_TEST_CASE(addition_test) // NOLINT
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
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 2, 4},
                     {6, 8, 10},
                     {12, 14, 16}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{7, 8, 9},
                     {10, 11, 12},
                     {13, 14, 15}
             }}};
    BOOST_TEST((matrix1 + matrix2) == expectedMatrix12);
    BOOST_TEST((matrix1 + 7) == expectedMatrix1S);
    expectedMatrix1S += 1;
    MatLib::matrix<float, 3, 3> expectedTest = {
            {{{8, 9, 10},
                     {11, 12, 13},
                     {14, 15, 16}
             }}};
    BOOST_TEST(expectedMatrix1S == expectedTest);
}

BOOST_AUTO_TEST_CASE(subtraction_test) // NOLINT
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
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{-5, -4, -3},
                     {-2, -1, 0},
                     {1, 2, 3}
             }}};
    BOOST_TEST((matrix1 - matrix2) == expectedMatrix12);
    BOOST_TEST((matrix1 - 5) == expectedMatrix1S);
}

BOOST_AUTO_TEST_CASE(determinant_test, *boost::unit_test::tolerance(0.01)) // NOLINT
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

BOOST_AUTO_TEST_CASE(row_echelon_test) // NOLINT
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

BOOST_AUTO_TEST_CASE(transpose_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{0, 3, 6},
                     {1, 4, 7},
                     {2, 5, 8}
             }}};
    BOOST_TEST(matrix3x3.getTranspose() == expectedMatrix3x3);
    MatLib::matrix<int, 4, 4> matrix4x4 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<int, 4, 4> expectedMatrix4x4 = {
            {{{5, 4, 4, 12},
                     {8, 5, 9, 77},
                     {2, 12, 10, 14},
                     {3, 7, 11, 14}
             }}};
    BOOST_TEST(matrix4x4.getTranspose() == expectedMatrix4x4);
}

BOOST_AUTO_TEST_CASE(augment_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix3x32 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 6> expectedMatrix3x3 = {
            {{{0, 1, 2, 0,  1, 2},
                     {3, 4, 5, 3, 4, 5},
                     {6, 7, 8, 6, 7, 8}
             }}};
    BOOST_TEST(matrix3x3.getAugment(matrix3x32) == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(identity_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{1, 0, 0},
                     {0, 1, 0},
                     {0, 0, 1}
             }}};
    BOOST_TEST(matrix3x3.getIdentity() == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(inverse_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{3, 7, 8},
                     {5, 1, 5},
                     {7, 2, 5}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{-0.063291139240506329147, -0.24050632911392405062	, 0.3417721518987341772},
                     {0.12658227848101265819, -0.51898734177215189872	, 0.31645569620253164556},
                     {0.037974683544303797508, 0.54430379746835443037, -0.40506329113924050632}
             }}};
    BOOST_TEST(matrix3x3.getInverse() == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(sort_test)  // NOLINT // helps check begin and rebegin iterators.
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{3, 7, 8},
                     {5, 1, 5},
                     {7, 2, 5}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{1, 2, 3},
                     {5, 5, 5},
                     {7, 7, 8}
             }}};
    std::sort(matrix3x3.begin(), matrix3x3.end());
    BOOST_TEST(matrix3x3 == expectedMatrix3x3);
    MatLib::matrix<float, 3, 3> expectedReversed = {
            {{{8, 7, 7},
                     {5, 5, 5},
                     {1, 2, 3}
             }}};
    std::sort(matrix3x3.rbegin(), matrix3x3.rend());
    BOOST_TEST(matrix3x3 == expectedReversed);
}

BOOST_AUTO_TEST_CASE(find_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> matrix3x3 = {
            {{{3, 7, 0},
                     {5, 1, 2},
                     {5, 2, 5}
             }}};
    BOOST_TEST((*std::find(matrix3x3.cbegin(), matrix3x3.cend(), 0)) == 0);
}