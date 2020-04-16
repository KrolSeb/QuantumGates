cmake_minimum_required(VERSION 3.15)
project(QuantumGates)

set(CMAKE_CXX_STANDARD 17)

include_directories(quantum)

add_subdirectory(quantum)
add_subdirectory(quantum-tests)

add_executable(QuantumGatesRun main.cpp)
target_link_libraries(QuantumGatesRun quantum)
