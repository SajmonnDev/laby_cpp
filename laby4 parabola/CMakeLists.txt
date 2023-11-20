cmake_minimum_required(VERSION 3.26)
project(parabola)

set(CMAKE_CXX_STANDARD 17)

add_executable(parabola main.cpp
        parabola.cpp
        parabola.h
        "../laby4 parabola/main.cpp"
        "../laby4 parabola/parabola.cpp"
        "../laby4 parabola/parabola.h")
