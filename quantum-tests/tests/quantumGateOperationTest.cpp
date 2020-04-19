#include "gtest/gtest.h"
#include <headers/quantumGate.h>
#include "headers/quantumGateOperation.h"
#include <iostream>
#include <complex>

using namespace std;

TEST(quantumGateOperation, testGenerationOfHadamardGateForIndex0) {
    int baseNumber = 2;
    int indexNumber = 0;
    int gateSize = pow(baseNumber, indexNumber);

    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    complex<double> expectedGate[1][1] = {{1}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_DOUBLE_EQ(real(expectedGate[i][j]), real(hadamardGate[i][j]));
        }
    }
}

TEST(quantumGateOperation, testGenerationOfHadamardGateForIndex1) {
    int baseNumber = 2;
    int indexNumber = 1;
    int gateSize = pow(baseNumber, indexNumber);

    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    complex<double> expectedGate[2][2] = {{0.707107, 0.707107},
                                          {0.707107, -0.707107}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_DOUBLE_EQ(round(real(expectedGate[i][j])), round(real(hadamardGate[i][j])));
        }
    }
}

TEST(quantumGateOperation, testGenerationOfHadamardGateForIndex2) {
    int baseNumber = 2;
    int indexNumber = 2;
    int gateSize = pow(baseNumber, indexNumber);

    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    complex<double> expectedGate[4][4] = {{0.5, 0.5,  0.5,  0.5},
                                          {0.5, -0.5, 0.5,  -0.5},
                                          {0.5, 0.5,  -0.5, -0.5},
                                          {0.5, -0.5, -0.5, 0.5}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_DOUBLE_EQ(real(expectedGate[i][j]), real(hadamardGate[i][j]));
        }
    }
}

TEST(quantumGateOperation, testGenerationOfHadamardGateForIndex3) {
    int baseNumber = 2;
    int indexNumber = 3;
    int gateSize = pow(baseNumber, indexNumber);

    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    complex<double> expectedGate[8][8] = {{0.353553, 0.353553,  0.353553,  0.353553,  0.353553,  0.353553,  0.353553,  0.353553},
                                          {0.353553, -0.353553, 0.353553,  -0.353553, 0.353553,  -0.353553, 0.353553,  -0.353553},
                                          {0.353553, 0.353553,  -0.353553, -0.353553, 0.353553,  0.353553,  -0.353553, -0.353553},
                                          {0.353553, -0.353553, -0.353553, 0.353553,  0.353553,  -0.353553, -0.353553, 0.353553},
                                          {0.353553, 0.353553,  0.353553,  0.353553,  -0.353553, -0.353553, -0.353553, -0.353553},
                                          {0.353553, -0.353553, 0.353553,  -0.353553, -0.353553, 0.353553,  -0.353553, 0.353553},
                                          {0.353553, 0.353553,  -0.353553, -0.353553, -0.353553, -0.353553, 0.353553,  0.353553},
                                          {0.353553, -0.353553, -0.353553, 0.353553,  -0.353553, 0.353553,  0.353553,  -0.353553}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_DOUBLE_EQ(round(real(expectedGate[i][j])), round(real(hadamardGate[i][j])));
        }
    }
}

TEST(quantumGateOperation, testGenerationOfPhaseShiftGateForMinusPi) {
    int gateSize = 2;
    double angle = -M_PI;

    complex<double> **phaseShiftGate = getPhaseShiftGate(angle);
    const complex<double> imaginary(-1, 0);
    complex<double> expectedQubit[2][2] = {{1, 0},
                                           {0, imaginary}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_EQ(real(expectedQubit[i][j]), real(phaseShiftGate[i][j]));
        }
    }
}

TEST(quantumGateOperation, testGenerationOfPhaseShiftGateForPiDividedByTwo) {
    int gateSize = 2;
    double angle = M_PI / 2;

    const complex<double> imaginary(0, 1);
    complex<double> result = exp(imaginary * angle);

    complex<double> **phaseShiftGate = getPhaseShiftGate(angle);
    complex<double> expectedQubit[2][2] = {{1, 0},
                                           {0, result}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_EQ(expectedQubit[i][j], phaseShiftGate[i][j]);
        }
    }

}