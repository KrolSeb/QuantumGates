#include "gtest/gtest.h"
#include "headers/quantumGate.h"
#include "headers/quantumGateOperation.h"
#include "headers/matrixOperation.h"
#include <iostream>
#include <complex>

using namespace std;
typedef vector<vector<complex<double>>> vector2d;

/// Helper method used to get not unitary matrix (determinant not equal 1)
vector2d getNotUnitaryMatrix(int matrixSize) {
    vector2d matrixWithZeroDeterminant;
    matrixWithZeroDeterminant.resize(matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        matrixWithZeroDeterminant[i].resize(matrixSize);
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

    vector2d hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    vector2d expectedGate = {{1}};

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

    vector2d hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    vector2d expectedGate = {{0.707107, 0.707107},
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

    vector2d hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    vector2d expectedGate = {{0.5, 0.5,  0.5,  0.5},
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

    vector2d hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    vector2d expectedGate = {{0.353553, 0.353553,  0.353553,  0.353553,  0.353553,  0.353553,  0.353553,  0.353553},
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

    vector2d phaseShiftGate = getPhaseShiftGate(angle);
    const complex<double> imaginary(-1, 0);

    vector2d expectedQubit = {{1, 0},
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

    vector2d phaseShiftGate = getPhaseShiftGate(angle);
    vector2d expectedQubit = {{1, 0},
                              {0, result}};

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            ASSERT_EQ(expectedQubit[i][j], phaseShiftGate[i][j]);
        }
    }
}

TEST(quantumGateOperation, testComposeOfTwoNotQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getNotGate(), getNotGate()));
}

TEST(quantumGateOperation, testComposeOfTwoHadamardQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getHadamardGate(), getHadamardGate()));
}

TEST(quantumGateOperation, testComposeOfTwoSwapQuantumGates) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getSwapGate(), getSwapGate()));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPI) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(M_PI)));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPiAndMinusPi) {
    ASSERT_TRUE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(-M_PI)));
}

TEST(quantumGateOperation, testComposeOfTwoPhaseShiftQuantumGatesForPiAndPiDividedByTwo) {
    ASSERT_FALSE(isComposeOfGatesGivesIdentityMatrix(getPhaseShiftGate(M_PI), getPhaseShiftGate(M_PI/2)));
}

TEST(quantumGateOperation, testComposeOfCnotAndSwapQuantumGates) {
    ASSERT_FALSE(isComposeOfGatesGivesIdentityMatrix(getCnotGate(), getSwapGate()));
}

TEST(quantumGateOperation, testIsCnotGatesUnitary) {
    vector2d cnotGate = getCnotGate();
    vector2d conjugateTransposedCnotGate = makeConjugateTranspose(getCnotGate());

    ASSERT_TRUE(isMatrixUnitary(cnotGate, conjugateTransposedCnotGate));
}

TEST(quantumGateOperation, testNotGateAndZeroDeterminantMatrixNotUnitary) {
    vector2d notGate = getNotGate();
    vector2d conjugateTransposedMatrix = makeConjugateTranspose(getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE));

    ASSERT_FALSE(isMatrixUnitary(notGate, conjugateTransposedMatrix));
}

TEST(quantumGateOperation, testTwoZeroDeterminantMatricesNotUnitary) {
    vector2d notUnitaryMatrix = getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE);
    vector2d conjugateTransposedMatrix = makeConjugateTranspose(getNotUnitaryMatrix(ONE_ARGUMENT_GATE_SIZE));

    ASSERT_FALSE(isMatrixUnitary(notUnitaryMatrix, conjugateTransposedMatrix));
}