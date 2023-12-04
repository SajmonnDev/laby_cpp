cmake_minimum_required(VERSION 3.26)
project(kolos1)

set(CMAKE_CXX_STANDARD 17)

add_executable(kolos1 main.cpp
        zderzacz.h
        zderzacz.cpp)
