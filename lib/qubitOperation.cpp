#include <iostream>
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"

using namespace std;

/// Function used to get allocated array for qubit.
complex<double> **getAllocatedQubit(int rows) {
    complex<double> **matrix = new complex<double>*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new complex<double>[QUBIT_NUMBER_OF_COLUMNS];
    }

    return matrix;
}

/// Function used to make dot product of two qubits
/// @returns matrix with single value
/// Dot product - https://en.wikipedia.org/wiki/Dot_product#Algebraic_definition
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

/// Function used to convert qubit as vector to two dimensional array
/// and change type from double to complex<double>
complex<double> **convertBaseVectorTo2dArray(vector<double> baseVector) {
    complex<double> **baseVectorAsTwoDimensionalArray = getAllocatedMatrix(baseVector.size(), QUBIT_NUMBER_OF_COLUMNS);

    for(int i = 0; i < baseVector.size(); i++) {
        for(int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            baseVectorAsTwoDimensionalArray[i][j] = baseVector.at(i);
        }
    }

    return baseVectorAsTwoDimensionalArray;
}

/// Function used to get qubit as complex type 2D array
complex<double> **getQubitRepresentation(vector<double> baseVector) {
    return convertBaseVectorTo2dArray(baseVector);
}

/// Function used to show single element of qubit (2D array)
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

/// Function used to show all elements of qubit (2D array)
void showQubit(complex<double> **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to show qubit after conjugate transpose (reversed columns and rows number)
void showQubitAfterConjugateTranspose(complex<double> **qubit, const int qubitRows) {
    for (int i = 0; i < QUBIT_NUMBER_OF_COLUMNS; i++) {
        for (int j = 0; j < qubitRows; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to show scalar product
void showScalarProduct(complex<double> **scalarProduct) {
    for (int i = 0; i < QUBIT_NUMBER_OF_COLUMNS; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            showSingleQubitElement(scalarProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}