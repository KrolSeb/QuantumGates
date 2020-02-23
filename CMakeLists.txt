cmake_minimum_required(VERSION 3.15)
project(QuantumGates)

set(CMAKE_CXX_STANDARD 17)

add_library(
        qg STATIC
        lib/matrixOperations.cpp
        lib/matrixOperations.h
)

add_executable(QuantumGates main1.cpp)
target_link_libraries(QuantumGates qg)
