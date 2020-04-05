#include <iostream>
#include "headers/qubitOperation.h"

using namespace std;

void printQubit(double *qubit, const int qubitRows) {
    for (int i = 0; i < qubitRows; i++) {
        cout << qubit[i] << endl;
    }
    cout << endl;
}

void printComplexQubit(complex<double> *qubit, const int qubitRows) {
    for (int i = 0; i < qubitRows; i++) {
        if (imag(qubit[i]) >= 0) {
            cout << real(qubit[i]) << "+" << imag(qubit[i]) << "i" << endl;
        }
        else if (real(qubit[i]) == 0 && imag(qubit[i]) == 0) {
            cout << real(qubit[i]) << endl;
        }
        else {
            cout << real(qubit[i]) << imag(qubit[i]) << "i" << endl;
        }
    }
    cout << endl;
}

double *getBaseVectorAsArray(vector<double> baseVector) {
    double *baseVectorAsArray = new double[baseVector.size()];
    std::copy(baseVector.begin(), baseVector.end(), baseVectorAsArray);

    return baseVectorAsArray;
}
