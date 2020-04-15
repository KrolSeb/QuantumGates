#include <iostream>
#include <iomanip>
#include "headers/matrixOperation.h"

using namespace std;

/// Function used to allocate matrix.
complex<double> **allocateMatrix(int dimension) {
    complex<double> **matrix = new complex<double>*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new complex<double>[dimension];
    }

    return matrix;
}

/// Function used to get random hermitian matrix.
/// Hermitian matrix - https://pl.wikipedia.org/wiki/Macierz_hermitowska
complex<double> **getRandomHermitianMatrix(int dimension) {
    complex<double> number;
    complex<double> **outputMatrix = allocateMatrix(dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            number = complex<double>(static_cast<double> (rand() % 20 - 10),static_cast<double> (rand() % 20 - 10));
            outputMatrix[i][j] = number;
            outputMatrix[j][i] = conj(number);
            if (i == j) {
                outputMatrix[i][j] = real(outputMatrix[i][j]);
            }
        }
    }

    return outputMatrix;
}

/// Function used to make conjugate transpose of matrix.
/// Conjugate transpose - https://en.wikipedia.org/wiki/Conjugate_transpose#Example
complex<double> **makeConjugateTranspose(complex<double> **matrix, const int rows, const int columns) {
    complex<double> **outputMatrix = new complex<double>*[columns];
    for (int i = 0; i < columns; i++) {
        outputMatrix[i] = new complex<double>[rows];
    }

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            outputMatrix[i][j] = conj(matrix[j][i]);
        }
    }

    return outputMatrix;
}

/// Function used to show single element of matrix (2D array)
void showSingleMatrixElement(complex<double> element) {
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

/// Function used to show all elements of matrix (2D array)
void showMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            showSingleMatrixElement(matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}