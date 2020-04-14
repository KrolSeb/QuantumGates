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

    sum = 0.0;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
           sum += firstQubit[i][j] * secondQubit[j][i];
        }
    }
    scalarProduct[0][0] = sum;

    return scalarProduct;
}

double **migrateBaseVectorTo2dArray(vector<double> baseVector) {
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
    return reinterpret_cast<complex<double> **>(migrateBaseVectorTo2dArray(baseVector));
}

void printElement(complex<double> element) {
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

void printQubit(complex<double> **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            printElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void printQubitAfterConjugateTranspose(complex<double> **qubit,  const int qubitRows) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < qubitRows; j++) {
            printElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void printScalarProduct(complex<double> **scalarProduct) {
    for (int i = 0; i < COLUMN_NUMBER_IN_QUBIT; i++) {
        for (int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            printElement(scalarProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}