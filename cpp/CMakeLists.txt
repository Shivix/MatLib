cmake_minimum_required(VERSION 3.16)
project(MatLib)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDES
        MatLib/matrix.hpp)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_library(MatLib INTERFACE)