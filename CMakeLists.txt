cmake_minimum_required(VERSION 4.1)
project(ViewCode)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)

# GLAD
add_library(glad src/render/glad.c)
target_include_directories(glad PUBLIC external/include)

# Executable
add_executable(ViewCode
    src/main.cpp
    src/render/render.cpp
    src/render/render.h
    src/render/stb_image.h
    src/render/image.h
    src/compile/compile.cpp
    src/types/types.cpp
    src/types/types.h
    src/blocks/blocks.cpp
    src/blocks/blocks.h
    src/compile/compile.h
)

# Make sure ViewCode can see GLAD headers
target_include_directories(ViewCode PUBLIC external/include)

# Link
target_link_libraries(ViewCode
    glad
    glfw
)
