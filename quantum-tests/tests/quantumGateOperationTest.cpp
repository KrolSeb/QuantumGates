#include "gtest/gtest.h"
#include "headers/quantumGate.h"
#include "headers/quantumGateOperation.h"
#include "headers/matrixOperation.h"
#include <iostream>
#include <complex>

using namespace std;

/// Helper method used to get not unitary matrix (determinant not equal 1)
complex<double> **getNotUnitaryMatrix(int matrixSize) {
    complex<double> **matrixWithZeroDeterminant = new complex<double>*[matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        matrixWithZeroDeterminant[i] = new complex<double>[matrixSize];
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrixWithZeroDeterminant[i][j] = complex<double>(0,0);
        }
    }

    return matrixWithZeroDeterminant;
}


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

TEST(quantumGateOperation, testComposeOfTwoNotQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfTwoHadamardQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getHadamardGate(), getHadamardGate(), ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfTwoSwapQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getSwapGate(), getSwapGate(), TWO_ARGUMENTS_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPI) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(M_PI), ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPiAndMinusPi) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(-M_PI), ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPiAndPiDividedByTwo) {
    ASSERT_FALSE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(M_PI/2), ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testComposeOfCnotAndSwapQuantumGates) {
    ASSERT_FALSE(isComposeOfGatesGivesIdentityMatrix(getCnotGate(), getSwapGate(), TWO_ARGUMENTS_GATE_SIZE));
}

TEST(quantumGateOperation, testIsCnotGatesUnitary) {
    complex<double> **cnotGate = getCnotGate();
    complex<double> **conjugateTransposedCnotGate = makeConjugateTranspose(getCnotGate(), TWO_ARGUMENTS_GATE_SIZE, TWO_ARGUMENTS_GATE_SIZE);

    ASSERT_TRUE(isMatrixUnitary(cnotGate, conjugateTransposedCnotGate, TWO_ARGUMENTS_GATE_SIZE));
}

TEST(quantumGateOperation, testNotGateAndZeroDeterminantMatrixNotUnitary) {
    complex<double> **notGate = getNotGate();
    complex<double> **conjugateTransposedMatrix = makeConjugateTranspose(
            getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE),
            ONE_ARGUMENT_GATE_SIZE, ONE_ARGUMENT_GATE_SIZE);

    ASSERT_FALSE(isMatrixUnitary(notGate, conjugateTransposedMatrix, ONE_ARGUMENT_GATE_SIZE));
}

TEST(quantumGateOperation, testTwoZeroDeterminantMatricesNotUnitary) {
    complex<double> **notUnitaryMatrix = getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE);
    complex<double> **conjugateTransposedMatrix = makeConjugateTranspose(
            getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE),
            ONE_ARGUMENT_GATE_SIZE, ONE_ARGUMENT_GATE_SIZE);

    ASSERT_FALSE(isMatrixUnitary(notUnitaryMatrix, conjugateTransposedMatrix, ONE_ARGUMENT_GATE_SIZE));
}