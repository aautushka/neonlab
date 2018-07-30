cmake_minimum_required(VERSION 3.1)

project(console-app-android)

add_compile_options(-std=gnu++1z)

set(SRC main.cpp)
add_executable(console-app-android ${SRC})

