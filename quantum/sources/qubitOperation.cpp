#include <iostream>
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"

complex<double> **getAllocatedQubit(int rows) {
    complex<double> **matrix = new complex<double>*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new complex<double>[QUBIT_NUMBER_OF_COLUMNS];
    }

    return matrix;
}

complex<double> **makeDotProductOfQubits(complex<double> **firstQubit, complex<double> **secondQubit, int rows, int columns) {
    complex<double> sum;
    complex<double> **dotProduct = getAllocatedMatrix(columns, columns);

    sum = complex<double>(0, 0);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
           sum += firstQubit[i][j] * secondQubit[j][i];
        }
    }
    dotProduct[0][0] = sum;

    return dotProduct;
}

/// Helper function used to convert qubit as vector to two dimensional array
/// and change type from double to complex<double>
/// \param baseVector vector<double>
/// \return complex two dimensional array
complex<double> **convertBaseVectorTo2dArray(vector<double> baseVector) {
    complex<double> **baseVectorAsTwoDimensionalArray = getAllocatedMatrix(baseVector.size(), QUBIT_NUMBER_OF_COLUMNS);

    for(int i = 0; i < baseVector.size(); i++) {
        for(int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            baseVectorAsTwoDimensionalArray[i][j] = baseVector.at(i);
        }
    }

    return baseVectorAsTwoDimensionalArray;
}

complex<double> **getQubitRepresentation(vector<double> baseVector) {
    return convertBaseVectorTo2dArray(baseVector);
}

/// Used to show single formatted element of qubit
/// \param element complex<double>
void showSingleQubitElement(complex<double> element) {
    if (imag(element) == 0) {
        cout << real(element) << " ";
    }
    else if (real(element) == 0 && imag(element) == 1) {
        cout << "i ";
    }
    else if (real(element) == 0 && imag(element) == -1) {
        cout << "-i ";
    }
    else if (real(element) == 0) {
        cout << imag(element) << "i ";
    }
    else {
        if (imag(element) > 0) {
            cout << real(element) << "+" << imag(element) << "i ";
        }
        else {
            cout << real(element) << imag(element) << "i ";
        }
    }
}

void showQubit(complex<double> **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void showQubitAfterConjugateTranspose(complex<double> **qubit, const int qubitRows) {
    for (int i = 0; i < QUBIT_NUMBER_OF_COLUMNS; i++) {
        for (int j = 0; j < qubitRows; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void showDotProduct(complex<double> **dotProduct) {
    for (int i = 0; i < QUBIT_NUMBER_OF_COLUMNS; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            showSingleQubitElement(dotProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}