#include "gtest/gtest.h"
#include "headers/matrixOperation.h"

using namespace std;
typedef vector<vector<complex<double>>> vector2d;

/// Test to check that matrices are equal (original and conjugate transposed one)
TEST(matrixOperation, equalsOfHermitianMatrices) {
    srand(static_cast<unsigned int>(time(nullptr)));
    int dimension = rand() % 4 + 2;
    vector2d hermitianMatrix = getRandomHermitianMatrix(dimension);
    vector2d conjugateTransposedMatrix = makeConjugateTranspose(hermitianMatrix);
    vector2d matrixAfterTwiceConjugateTransposition = makeConjugateTranspose(conjugateTransposedMatrix);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            ASSERT_EQ(hermitianMatrix[i][j], matrixAfterTwiceConjugateTransposition[i][j]);
        }
    }
}