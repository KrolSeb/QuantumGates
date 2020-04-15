#include <iostream>
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"

using namespace std;

complex<double> **makeScalarProductOfQubits(complex<double> **firstQubit, complex<double> **secondQubit, int rows, int columns) {
    complex<double> sum;
    complex<double> **scalarProduct = new complex<double>*[columns];
    for (int i = 0; i < columns; i++) {
        scalarProduct[i] = new complex<double>[columns];
    }

    sum = complex<double>(0, 0);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
           sum += firstQubit[i][j] * secondQubit[j][i];
        }
    }
    scalarProduct[0][0] = sum;

    return scalarProduct;
}

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

complex<double> **getQubitRepresentation(vector<double> baseVector) {
    return reinterpret_cast<complex<double> **>(convertBaseVectorTo2dArray(baseVector));
}

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
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void showQubitAfterConjugateTranspose(complex<double> **qubit, const int qubitRows) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < qubitRows; j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void showScalarProduct(complex<double> **scalarProduct) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            showSingleQubitElement(scalarProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}