cmake_minimum_required(VERSION 4.1)
project(ViewCode)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(ViewCode main.cpp
        types.h
        blocks.h)
