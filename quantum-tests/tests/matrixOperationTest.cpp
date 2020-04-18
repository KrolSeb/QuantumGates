#include "gtest/gtest.h"
#include "headers/matrixOperation.h"

using namespace std;

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