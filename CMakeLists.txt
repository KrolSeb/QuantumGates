cmake_minimum_required(VERSION 3.15)
project(TransposeConjugateMatrix C)

set(CMAKE_C_STANDARD 11)

add_executable(TransposeConjugateMatrix main.c)
target_link_libraries(TransposeConjugateMatrix m)
