cmake_minimum_required(VERSION 3.1)

project(neonlab)
include(googletest.cmake)

add_compile_options(-std=gnu++1z)

add_subdirectory(tests)
