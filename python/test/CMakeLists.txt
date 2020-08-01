cmake_minimum_required(VERSION 3.16)
project(MatLib)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        ../MatLib/pyMatrix.hpp)
set(TESTSRC
        unitTest.py)

# find_package(Python ${PY_VERSION} REQUIRED)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_executable(MatLib ${SRC})
# add_library(Matlib INTERFACE)