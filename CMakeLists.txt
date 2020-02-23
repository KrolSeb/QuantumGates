cmake_minimum_required(VERSION 3.15)
project(QuantumGates)

set(CMAKE_CXX_STANDARD 17)

add_library(
        qg STATIC
        lib/headers/matrixOperations.h
        lib/headers/quantum.h
        lib/quantum.cpp
        lib/matrixOperations.cpp
)

add_executable(QuantumGates main.cpp)
target_link_libraries(QuantumGates qg)
