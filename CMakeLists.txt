cmake_minimum_required(VERSION 3.15)
project(QuantumGates)

set(CMAKE_CXX_STANDARD 17)

add_library(
        qg STATIC
        lib/headers/quantumComputer.h
        lib/headers/complexMatrix.h
        lib/headers/numericMatrix.h
        lib/headers/quantumGate.h
        lib/headers/temporaryQubit.h
        lib/quantumComputer.cpp
        lib/complexMatrix.cpp
        lib/numericMatrix.cpp
        lib/quantumGate.cpp
        lib/temporaryQubit.cpp)

add_executable(QuantumGates main.cpp)
target_link_libraries(QuantumGates qg)
