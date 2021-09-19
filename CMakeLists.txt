cmake_minimum_required(VERSION 3.10)
project(FitchCheney)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(combinatorics)


add_executable(fitch-cheney
    main.cpp
    FitchCheney.h FitchCheney.cpp
    )

target_link_libraries(fitch-cheney combinatorics)
