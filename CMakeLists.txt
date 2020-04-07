cmake_minimum_required(VERSION 3.15)
project(QuantumGates)

set(CMAKE_CXX_STANDARD 17)

add_library(
        qg STATIC
        lib/headers/qubitOperation.h
        lib/headers/quantumComputer.h
        lib/headers/quantumGate.h
        lib/headers/quantumGateOperation.h
        lib/headers/complexMatrix.h
        lib/qubitOperation.cpp
        lib/quantumComputer.cpp
        lib/quantumGate.cpp
        lib/quantumGateOperation.cpp
        lib/complexMatrix.cpp
)

add_executable(QuantumGates main.cpp)
target_link_libraries(QuantumGates qg)
