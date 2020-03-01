#include <iostream>
#include "headers/quantumGate.h"
#include "headers/temporaryQubit.h"
#include "headers/complexMatrix.h"

using namespace std;

/// @params - matrix representations of quantum logic gates
const int NOT_QUANTUM_GATE[][NOT_GATE_COLUMNS] = {{0, 1},
                                                  {1, 0}};
/// @params - constans before sqrt not and Hadamard quartum gates, 1+i and 1-i values
const double FACTOR_SQRT_NOT_GATE = 0.5;
const complex<double> positiveComplex(1,1);
const complex<double> negativeComplex(1,-1);
const complex<double> SQRT_NOT_QUANTUM_GATE[][NOT_GATE_COLUMNS] = {{positiveComplex, negativeComplex},
                                                                   {negativeComplex, positiveComplex}};
const double FACTOR_HADAMARD_GATE = 1/sqrt(2);
const complex<double> HADAMARD_QUANTUM_GATE[][NOT_GATE_COLUMNS] = {{1, 1},
                                                                   {1, -1}};

//TODO: Implementation of all quantum gates
//TODO: Reverse and combining/folding of quantum gates

/// Function used to show quantum gate on output - int type
void printNotGateRepresentation() {
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            cout << NOT_QUANTUM_GATE[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void setNotGateValues(int **notGateRepresentation) {
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            notGateRepresentation[i][j] = NOT_QUANTUM_GATE[i][j];
        }
    }
}

int **getNotGate() {
    int **notGateRepresentation = new int *[NOT_GATE_ROWS];
    for (int i = 0; i < NOT_GATE_ROWS; i++)
        notGateRepresentation[i] = new int[NOT_GATE_COLUMNS];

    setNotGateValues(notGateRepresentation);
    printNotGateRepresentation();
    return notGateRepresentation;
}

complex<double> **multiplySqrtNotScalarByMatrix() {
    auto **matrix = new complex<double>*[NOT_GATE_ROWS];
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        matrix[i] = new complex<double>[NOT_GATE_COLUMNS];
    }

    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            matrix[i][j] = SQRT_NOT_QUANTUM_GATE[i][j];
        }
    }

    cout << "Defined matrix: " << endl;
    printComplexMatrix(matrix, NOT_GATE_ROWS);

    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            matrix[i][j] = SQRT_NOT_QUANTUM_GATE[i][j] * FACTOR_SQRT_NOT_GATE;
        }
    }

    cout << "Matrix after multiplication by scalar (1/2): " << endl;
    printComplexMatrix(matrix, NOT_GATE_ROWS);

    return matrix;
}

complex<double> **multiplyHadamardScalarByMatrix() {
    auto **matrix = new complex<double>*[NOT_GATE_ROWS];
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        matrix[i] = new complex<double>[NOT_GATE_COLUMNS];
    }

    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            matrix[i][j] = HADAMARD_QUANTUM_GATE[i][j];
        }
    }

    cout << "Defined matrix: " << endl;
    printComplexMatrix(matrix, NOT_GATE_ROWS);

    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < NOT_GATE_COLUMNS; j++) {
            matrix[i][j] = HADAMARD_QUANTUM_GATE[i][j] * FACTOR_HADAMARD_GATE;
        }
    }

    cout << "Matrix after multiplication by scalar (1/sqrt(2)): " << endl;
    printComplexMatrix(matrix, NOT_GATE_ROWS);

    return matrix;
}


//Function used to make NOT(negation) on qubit
int **makeNotOnQubit(int **qubit, const int QUBIT_COLUMNS) {
    int sum;
    int **outputQubit = new int * [NOT_GATE_ROWS];
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        outputQubit[i] = new int [QUBIT_COLUMNS];
    }

    //Matrix multiplication
    for (int i = 0; i < NOT_GATE_ROWS; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0;
            for (int k = 0; k < NOT_GATE_COLUMNS; k++) {
                sum += NOT_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    printSingleQubit(outputQubit);
    return outputQubit;
}