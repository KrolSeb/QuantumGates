#include <iostream>
#include "headers/numericMatrix.h"

/// @param - global variable used to store matrix size
int numericMatrixDimension;

void setNumericMatrixDimension(int dimension) {
    numericMatrixDimension = dimension;
}

/// Function used to allocate numeric matrix
/// @param @ dimension - array size
/// @returns - allocated matrix
int **allocateNumericMatrix(int dimension) {
    int **matrix = new int*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new int[dimension];
    }

    return matrix;
}

/// Function used to fill allocated matrix with 0 and 1 values - int type
/// @param matrix - allocated matrix
/// @returns - filled matrix
int **generateRandomNumericMatrix(int **matrix) {
    for (int i = 0; i < numericMatrixDimension; i++) {
        for (int j = 0; j < numericMatrixDimension; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}

/// Function used to transpose numeric matrix
/// @param matrix
/// @returns - transposed matrix
int **transposeNumericMatrix(int **matrix) {
    int **transposedMatrix = allocateNumericMatrix(numericMatrixDimension);
    for (int i = 0; i < numericMatrixDimension; i++) {
        for (int j = 0; j < numericMatrixDimension; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

/// Function used to show matrix on output - int type
void printNumericMatrix(int **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
