include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(QuantumGatesTest tests.cpp)

target_link_libraries(QuantumGatesTest gtest gtest_main)
target_link_libraries(QuantumGatesTest quantum)