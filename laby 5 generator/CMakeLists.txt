cmake_minimum_required(VERSION 3.26)
project(zadanie5_generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(zadanie5_generator main.cpp
        generator.cpp
        generator.h)
