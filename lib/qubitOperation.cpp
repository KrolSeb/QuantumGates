#include <iostream>
#include "headers/qubitOperation.h"

using namespace std;

void printQubit(double **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            cout << qubit[i][j];
        }
        cout << endl;
    }
}

void printComplexQubit(complex<double> **qubit, const int qubitRows) {
    for(int i = 0; i < qubitRows; i++) {
        for(int j = 0; j < COLUMN_NUMBER_IN_QUBIT; j++) {
            if (imag(qubit[i][j]) >= 0) {
                cout << real(qubit[i][j]) << "+" << imag(qubit[i][j]) << "i";
            }
            else if (real(qubit[i][j]) == 0 && imag(qubit[i][j]) == 0) {
                cout << real(qubit[i][j]);
            }
            else {
                cout << real(qubit[i][j]) << imag(qubit[i][j]) << "i";
            }
        }
        cout << endl;
    }
}

double **getBaseVectorAsTwoDimensionalArray(vector<double> baseVector) {
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