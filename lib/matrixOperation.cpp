#include <iostream>
#include <iomanip>
#include "headers/matrixOperation.h"

using namespace std;

/// Function used to allocate complex matrix
/// @param @ dimension - array size
/// @returns - allocated matrix
complex<double> **allocateMatrix(int dimension) {
    complex<double> **matrix = new complex<double>*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new complex<double>[dimension];
    }

    return matrix;
}

/// Function used to fill allocated matrix with complex numbers - complex double type
/// @param matrix - allocated matrix
/// @returns - filled matrix
complex<double> **getRandomHermitianMatrix(int dimension) {
    complex<double> number;
    complex<double> **outputMatrix = allocateMatrix(dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            /// Generation of random matrix values
            number = complex<double>(static_cast<double> (rand() % 20 - 10),static_cast<double> (rand() % 20 - 10));
            outputMatrix[i][j] = number;
            outputMatrix[j][i] = conj(number);

            /// @if matrix element on diagonal, take only real part of complex number
            if (i == j) {
                outputMatrix[i][j] = real(outputMatrix[i][j]);
            }
        }
    }

    return outputMatrix;
}

complex<double> **makeConjugateTranspose(complex<double> **quantumGate, const int rows, const int columns) {
    complex<double> **outputGate = new complex<double>*[columns];
    for (int i = 0; i < columns; i++) {
        outputGate[i] = new complex<double>[rows];
    }

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            outputGate[i][j] = conj(quantumGate[j][i]);
        }
    }

    return outputGate;
}

void printMatrixElement(complex<double> element) {
    if (imag(element) == 0) {
        cout << setw(6) << real(element) << " " << setw(4);
    }
    else if (real(element) == 0) {
        cout << setw(6) << imag(element) << "i" << setw(4);
    }
    else {
        if (imag(element) > 0) {
            cout << setw(4) << real(element) << "+" << imag(element) << "i" << setw(6);
        }
        else {
            cout << setw(4) << real(element) << imag(element) << "i" << setw(6);
        }
    }

}

void printMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printMatrixElement(matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}