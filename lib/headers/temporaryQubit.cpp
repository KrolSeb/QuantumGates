#include <iostream>
#include <cstddef>
#include "temporaryQubit.h"

using namespace std;
const int FIRST_MATRIX_DIMENSION = 2;
const int SINGLE_QUBIT_SIZE = 1;

const int QUBIT_0[FIRST_MATRIX_DIMENSION][SINGLE_QUBIT_SIZE] = {{1},
                                                                {0}};
const int QUBIT_1[FIRST_MATRIX_DIMENSION][SINGLE_QUBIT_SIZE] = {{0},
                                                                {1}};

void printSingleQubit(int **singleQubit) {
    for (int i = 0; i < FIRST_MATRIX_DIMENSION; i++) {
        for (int j = 0; j < SINGLE_QUBIT_SIZE; j++) {
            cout << singleQubit[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void setQubitValues(int **qubitRepresentation, const int definedQubit[][SINGLE_QUBIT_SIZE]) {
    qubitRepresentation[0][0] = definedQubit[0][0];
    qubitRepresentation[1][0] = definedQubit[1][0];
}

int **getQubit0() {
    int **qubitRepresentation = new int *[FIRST_MATRIX_DIMENSION];
    for (int i = 0; i < FIRST_MATRIX_DIMENSION; i++)
        qubitRepresentation[i] = new int[SINGLE_QUBIT_SIZE];

    setQubitValues(qubitRepresentation, QUBIT_0);
    printSingleQubit(qubitRepresentation);
    return qubitRepresentation;
}

int **getQubit1() {
    int **qubitRepresentation = new int *[FIRST_MATRIX_DIMENSION];
    for (int i = 0; i < FIRST_MATRIX_DIMENSION; i++)
        qubitRepresentation[i] = new int[SINGLE_QUBIT_SIZE];

    setQubitValues(qubitRepresentation, QUBIT_1);
    printSingleQubit(qubitRepresentation);
    return qubitRepresentation;
}



