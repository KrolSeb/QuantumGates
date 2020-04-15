#include <iostream>
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"

using namespace std;

/// Function used to make dot product of two qubits
/// @returns matrix with single value
/// Dot product - https://en.wikipedia.org/wiki/Dot_product#Algebraic_definition
complex<double> **makeDotProductOfQubits(complex<double> **firstQubit, complex<double> **secondQubit, int rows, int columns) {
    complex<double> sum;
    complex<double> **dotProduct = new complex<double>*[columns];
    for (int i = 0; i < columns; i++) {
        dotProduct[i] = new complex<double>[columns];
    }

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
double **convertBaseVectorTo2dArray(vector<double> baseVector) {
    double **baseVectorAsTwoDimensionalArray = new double *[baseVector.size()];
    for (int i = 0; i < baseVector.size(); i++) {
        baseVectorAsTwoDimensionalArray[i] = new double[COLUMN_NUMBER_IN_QUBIT];
    }

    for(int i = 0; i < baseVector.size(); i++) {
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            baseVectorAsTwoDimensionalArray[i][j] = baseVector.at(i);
        }
    }

    return baseVectorAsTwoDimensionalArray;
}

/// Function used to get qubit as complex type 2D array
complex<double> **getQubitRepresentation(vector<double> baseVector) {
    return reinterpret_cast<complex<double> **>(convertBaseVectorTo2dArray(baseVector));
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
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to show qubit after conjugate transpose (reversed columns and rows number)
void showQubitAfterConjugateTranspose(complex<double> **qubit, const int qubitRows) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < qubitRows; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to show scalar product
void showScalarProduct(complex<double> **scalarProduct) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            showSingleQubitElement(scalarProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}