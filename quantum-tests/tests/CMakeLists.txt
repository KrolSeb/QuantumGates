include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(QuantumGatesTest
        matrixOperationTest.cpp
        quantumComputerTest.cpp
        quantumGateTest.cpp
        quantumGateOperationTest.cpp
        qubitOperationTest.cpp)

target_link_libraries(QuantumGatesTest gtest gtest_main)
target_link_libraries(QuantumGatesTest quantum)