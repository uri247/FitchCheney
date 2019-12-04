cmake_minimum_required(VERSION 3.10)
project(FitchCheney)

set(CMAKE_CXX_STANDARD 17)

add_executable(fitch-cheney main.cpp)
target_link_libraries(fitch-cheney comb)