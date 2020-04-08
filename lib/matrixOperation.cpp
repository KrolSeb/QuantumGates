#include <iostream>
#include <iomanip>
#include "headers/matrixOperation.h"

/// @param - global variable used to store matrix size
int complexMatrixDimension;

void setComplexMatrixDimension(int dimension) {
    complexMatrixDimension = dimension;
}

/// Function used to allocate complex matrix
/// @param @ dimension - array size
/// @returns - allocated matrix
complex<double> **allocateComplexMatrix(int dimension) {
    complex<double> **matrix = new complex<double>*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new complex<double>[dimension];
    }

    return matrix;
}

/// Function used to fill allocated matrix with complex numbers - complex double type
/// @param matrix - allocated matrix
/// @returns - filled matrix
complex<double> **generateRandomComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < complexMatrixDimension; i++) {
        for (int j = 0; j < complexMatrixDimension; j++) {
            /// Generation of random matrix values
            /// @if random number equals zero, then save complex number to matrix
            /// @else take only real part of complex number and save to matrix
            if (rand() % 2 == 0) {
                matrix[i][j] = complex<double>(static_cast<double> (rand() % 20 - 10),
                                               static_cast<double> (rand() % 20 - 10));
            }
            else {
                matrix[i][j] = real(complex<double>(static_cast<double> (rand() % 20 - 10),
                                                    static_cast<double> (rand() % 20 - 10)));
            }

            /// @if matrix element on diagonal, take only real part of complex number
            if (i == j) {
                matrix[i][j] = real(matrix[i][j]);
            }
        }
    }

    return matrix;
}

/// Function used to transpose complex matrix
/// @param matrix
/// @returns - transposed matrix
complex<double> **transposeComplexMatrix(complex<double> **matrix) {
    complex<double> **transposedMatrix = allocateComplexMatrix(complexMatrixDimension);
    for (int i = 0; i < complexMatrixDimension; i++) {
        for (int j = 0; j < complexMatrixDimension; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

/// Function used to conjugate complex matrices
/// @param matrix
/// @returns - conjugated matrix
complex<double> **conjugateComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < complexMatrixDimension; i++) {
        for (int j = 0; j < complexMatrixDimension; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }
    return matrix;
}

/// Function used to show  matrix on output - complex double type
void printHermitianComplexMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            /// Formatting output of complex matrix
            if (i == j || imag(matrix[i][j]) == 0.000000) {
                cout << setw(8) << real(matrix[i][j]);
            }
            else {
                if (imag(matrix[i][j]) > 0) {
                    cout << setw(5) << real(matrix[i][j]) << "+" << imag(matrix[i][j]) << "i";
                }
                else {
                    cout << setw(5) << real(matrix[i][j]) << imag(matrix[i][j]) << "i";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printComplexMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            /// Formatting output of complex matrix
            if (imag(matrix[i][j]) > 0) {
                cout << setw(5) << real(matrix[i][j]) << "+" << imag(matrix[i][j]) << "i";
            }
            else {
                cout << setw(5) << real(matrix[i][j]) << imag(matrix[i][j]) << "i";
            }
        }
        cout << endl;
    }
    cout << endl;
}