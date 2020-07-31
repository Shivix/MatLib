cmake_minimum_required(VERSION 3.16)
project(MatLib)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        MatLib/pyMatrix.hpp)

add_subdirectory(pybind11)
# pybind11_add_module(MatLib ${SRC})

include_directories(${PROJECT_SOURCE_DIR}/python/pybind11/include)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

add_executable(MatLib ${SRC})
# add_library(MatLib INTERFACE)
target_link_libraries(MatLib pybind11::embed)