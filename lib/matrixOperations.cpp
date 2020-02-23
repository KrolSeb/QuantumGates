#include <iostream>
#include <iomanip>
#include "matrixOperations.h"
using namespace std;

/// @param - global variable used to store matrix size
int matrixDimension;

/// @params - matrix representations of quantum logic gates
const int CNOT_MATRIX_DIMENSION = 2;
const int CNOT_LOGIC_GATE[][2] = {{0, 1},
                                  {1, 0}};

void setMatrixDimension(int dimension) {
    matrixDimension = dimension;
}

/// Function used to show matrix on output - int type
void printLogicGateRepresentation() {
    for (int i = 0; i < CNOT_MATRIX_DIMENSION; i++) {
        for (int j = 0; j < CNOT_MATRIX_DIMENSION; j++) {
            cout << CNOT_LOGIC_GATE[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to allocate different type of matrices
/// @param @ dimension - array size
/// @returns - allocated matrix
template<typename T>
T **allocateMatrix(int dimension) {
    T **matrix = new T *[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new T[dimension];
    }

    return matrix;
}

/// Function used to fill allocated matrix with 0 and 1 values - int type
/// @param matrix - allocated matrix
/// @returns - filled matrix
int **generateRandom01Matrix(int **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}

/// Function used to fill allocated matrix with complex numbers - complex double type
/// @param matrix - allocated matrix
/// @returns - filled matrix
complex<double> **generateRandomComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
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

/// Function used to transpose different type of matrices
/// @param matrix
/// @returns - transposed matrix
template<typename T>
T **transposeMatrix(T **matrix) {
    T **transposedMatrix = allocateMatrix<T>(matrixDimension);
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

/// Function used to conjugate complex matrices
/// @param matrix
/// @returns - conjugated matrix
complex<double> **conjugateComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }
    return matrix;
}

/// Function used to show matrix on output - int type
void printMatrix(int **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to show matrix on output - complex double type
void printComplexMatrix(complex<double> **matrix, int dimension) {
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
