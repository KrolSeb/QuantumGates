#include <iostream>
#include "headers/qubitOperation.h"

using namespace std;

void printQubitElement(complex<double> qubitElement) {
    if (imag(qubitElement) == 0) {
        cout << real(qubitElement) << " ";
    }
    else if (real(qubitElement) == 0 && imag(qubitElement) == 1) {
        cout << "i ";
    }
    else if (real(qubitElement) == 0 && imag(qubitElement) == -1) {
        cout << "-i ";
    }
    else if (real(qubitElement) == 0) {
        cout << imag(qubitElement) << "i ";
    }
    else {
        if (imag(qubitElement) > 0) {
            cout << real(qubitElement) << "+" << imag(qubitElement) << "i ";
        }
        else {
            cout << real(qubitElement) << imag(qubitElement) << "i ";
        }
    }
}

void printQubit(complex<double> **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            printQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
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

double **getQubitRepresentation(vector<double> baseVector) {
    return migrateBaseVectorTo2dArray(baseVector);
}

complex<double> **convertQubitRepresentationToComplexType(double **qubitRepresentation) {
    return reinterpret_cast<complex<double> **>(qubitRepresentation);
}