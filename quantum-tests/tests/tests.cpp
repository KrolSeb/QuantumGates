#include "gtest/gtest.h"
#include "headers/matrixOperation.h"
#include "headers/quantumComputer.h"
#include "headers/quantumGate.h"
#include "headers/quantumGateOperation.h"
#include "headers/qubitOperation.h"

using namespace std;

/// Test to check if matrices are equal (original and conjugate transposed one)
TEST(hermitianMatrix, equalsOfMatricesElements) {
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