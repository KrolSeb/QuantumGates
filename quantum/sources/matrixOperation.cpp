#include <iostream>
#include <iomanip>
#include "headers/matrixOperation.h"

using namespace std;

complex<double> **getAllocatedMatrix(int firstDimension, int secondDimension) {
    if (secondDimension > firstDimension) {
        swap(firstDimension, secondDimension);
    }

    complex<double> **matrix = new complex<double>*[firstDimension];
    for (int i = 0; i < firstDimension; i++) {
        matrix[i] = new complex<double>[secondDimension];
    }

    return matrix;
}

complex<double> **getRandomHermitianMatrix(int dimension) {
    complex<double> number;
    complex<double> **outputMatrix = getAllocatedMatrix(dimension, dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            number = complex<double>(static_cast<double> (rand() % 10),static_cast<double> (rand() % 10));
            outputMatrix[i][j] = number;
            outputMatrix[j][i] = conj(number);
            if (i == j) {
                outputMatrix[i][j] = real(outputMatrix[i][j]);
            }
        }
    }

    return outputMatrix;
}

complex<double> **makeConjugateTranspose(complex<double> **matrix, const int rows, const int columns) {
    complex<double> **outputMatrix = getAllocatedMatrix(columns, rows);

    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            outputMatrix[i][j] = conj(matrix[j][i]);
        }
    }

    return outputMatrix;
}

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

void showMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            showSingleMatrixElement(matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}