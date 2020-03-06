#include <iostream>
#include "headers/qubitOperation.h"

using namespace std;

void printSingleQubit(double *singleQubit) {
    for (int i = 0; i < SINGLE_QUBIT_ROWS; i++) {
        cout << singleQubit[i] << endl;
    }
    cout << endl;
}

void printTwoQubits(double *qubits) {
    for (int i = 0; i < TWO_QUBIT_ROWS; i++) {
        cout << qubits[i] << endl;
    }
    cout << endl;
}

void printThreeQubits(double *qubits) {
    for (int i = 0; i < THREE_QUBIT_ROWS; i++) {
        cout << qubits[i] << endl;
    }
    cout << endl;
}

double *getBaseVectorAsArray(vector<double> baseVector) {
    double *baseVectorAsArray = new double[baseVector.size()];
    std::copy(baseVector.begin(), baseVector.end(), baseVectorAsArray);

    return baseVectorAsArray;
}
