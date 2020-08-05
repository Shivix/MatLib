cmake_minimum_required(VERSION 3.16)
project(MatLib)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDES
        ../MatLib/matrix.hpp)
set(TESTSRC
        unitTest.cpp)

find_package(Boost REQUIRED COMPONENTS system)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(MatLib ${INCLUDES} ${TESTSRC})
target_link_libraries(MatLib -lboost_unit_test_framework)