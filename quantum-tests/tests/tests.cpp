#include "gtest/gtest.h"
#include "headers/matrixOperation.h"
#include "headers/quantumComputer.h"
#include "headers/quantumGate.h"
#include "headers/quantumGateOperation.h"
#include "headers/qubitOperation.h"

using namespace std;
using namespace quantum;

/// Test to check that matrices are equal (original and conjugate transposed one)
TEST(matrixOperation, equalsOfHermitianMatrices) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int dimension = rand() % 4 + 2;
    complex<double> **hermitianMatrix = getRandomHermitianMatrix(dimension);
    complex<double> **hermitianMatrixAfterConjugateTranspose = makeConjugateTranspose(hermitianMatrix, dimension, dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            ASSERT_EQ(hermitianMatrix[i][j], hermitianMatrixAfterConjugateTranspose[i][j]);
        }
    }
}

/// Test to check that normalization of base vector works properly for incorrect probabilities
TEST(quantumComputer, isSumOfProbabilitiesAfterNormalizationEqualOne) {
    int numberOfQubits = 3;
    int arraySize = pow(2, numberOfQubits);
    double probabilities[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};

    /// Definition of structure
    /// Method validateProbability() is launched and when (sum of probabilities are != 1)
    /// normalizeRegister and resetState methods are executed (correction of probabilities)
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);

    /// Show probabilities after normalization
    quantumComputer.viewProbability();

    /// Sum of probabilities after correction (it should be 1)
    double result = 0.0;
    for (auto x: quantumComputer.baseVector) {
        result += pow(sqrt(fabs(x)), 2);
    }

    ASSERT_EQ(1.0, result);
}