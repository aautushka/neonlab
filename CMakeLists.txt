cmake_minimum_required(VERSION 3.1)

project(neonlab)

add_compile_options(-std=gnu++1z)

set(SRC source/main.cpp)
add_executable(neonlab ${SRC})

