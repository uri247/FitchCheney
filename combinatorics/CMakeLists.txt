cmake_minimum_required(VERSION 3.10)
project(FitchCheney)

set(CMAKE_CXX_STANDARD 20)

add_library(combinatorics
    "combinatorics.h"
    "combinations.cpp"
    "permutations.cpp"
    "factoradic.cpp"
    "io.cpp"
    )

add_executable(test_combinatorics test_combinatorics.cpp)
target_link_libraries(test_combinatorics combinatorics)

add_executable(test_factoradic test_factoradic.cpp)
target_link_libraries(test_factoradic combinatorics)
