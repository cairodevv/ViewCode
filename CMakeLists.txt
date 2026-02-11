cmake_minimum_required(VERSION 4.1)
project(ViewCode)

set(CMAKE_CXX_STANDARD 26)

add_executable(ViewCode main.cpp
        types.h
        blocks.h)
