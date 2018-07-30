cmake_minimum_required(VERSION 3.1)
project(tests CXX)
enable_testing()

include_directories(../source)
set(SRC neonlab_tests)

add_executable(tests ${SRC})
target_link_libraries(tests gtest)
