#include <iostream>
#include "headers/quantumGate.h"
#include "headers/complexMatrix.h"

using namespace std;

/// @param - NOT quantum gate matrix representation
const double NOT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, 1},
                                                           {1, 0}};
/// @param - CNOT quantum gate matrix representation
const double CNOT_QUANTUM_GATE[][TWO_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0},
                                                             {0, 1, 0, 0},
                                                             {0, 0, 0, 1},
                                                             {0, 0, 1, 0}};

/// @param - SWAP quantum gate matrix representation
const double SWAP_QUANTUM_GATE[][TWO_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0},
                                                             {0, 0, 1, 0},
                                                             {0, 1, 0, 0},
                                                             {0, 0, 0, 1}};

/// @param - FREDKIN(CSWAP) quantum gate matrix representation
const double FREDKIN_QUANTUM_GATE[][THREE_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0, 0, 0, 0, 0},
                                                                  {0, 1, 0, 0, 0, 0, 0, 0},
                                                                  {0, 0, 1, 0, 0, 0, 0, 0},
                                                                  {0, 0, 0, 1, 0, 0, 0, 0},
                                                                  {0, 0, 0, 0, 1, 0, 0, 0},
                                                                  {0, 0, 0, 0, 0, 0, 1, 0},
                                                                  {0, 0, 0, 0, 0, 1, 0, 0},
                                                                  {0, 0, 0, 0, 0, 0, 0, 1}};

/// @param - TOFFOLI(CCNOT) quantum gate matrix representation
const double TOFFOLI_QUANTUM_GATE[][THREE_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0, 0, 0, 0, 0},
                                                                  {0, 1, 0, 0, 0, 0, 0, 0},
                                                                  {0, 0, 1, 0, 0, 0, 0, 0},
                                                                  {0, 0, 0, 1, 0, 0, 0, 0},
                                                                  {0, 0, 0, 0, 1, 0, 0, 0},
                                                                  {0, 0, 0, 0, 0, 1, 0, 0},
                                                                  {0, 0, 0, 0, 0, 0, 0, 1},
                                                                  {0, 0, 0, 0, 0, 0, 1, 0}};

/// @params - sqrt(NOT) quantum gate matrix representation
const double FACTOR_SQRT_NOT_GATE = 0.5;
const complex<double> positiveComplex(1, 1);
const complex<double> negativeComplex(1, -1);
const complex<double> SQRT_NOT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{positiveComplex, negativeComplex},
                                                                         {negativeComplex, positiveComplex}};
/// @params - Hadamard quantum gate matrix representation
const double FACTOR_HADAMARD_GATE = 1 / sqrt(2);
const complex<double> HADAMARD_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{1, 1},
                                                                         {1, -1}};

//TODO: Implementation of all quantum gates
//TODO: Reverse and combining/folding of quantum gates

/// Function used to show quantum gate on output - int type
void printNotGateRepresentation() {
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            cout << NOT_QUANTUM_GATE[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/// Function used to make NOT(negation) on qubit
double *makeNotOnQubit(double *qubit, const int QUBIT_COLUMNS) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += NOT_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make CNOT on qubit
double *makeCnotOnQubit(double *qubit, const int QUBIT_COLUMNS) {
    double sum;
    double *outputQubit = new double[TWO_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0.0;
            for (int k = 0; k < TWO_ARGUMENTS_GATE_SIZE; k++) {
                sum += CNOT_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make SWAP on qubit
double *makeSwapOnQubit(double *qubit, const int QUBIT_COLUMNS) {
    double sum;
    double *outputQubit = new double[TWO_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0.0;
            for (int k = 0; k < TWO_ARGUMENTS_GATE_SIZE; k++) {
                sum += SWAP_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make FREDKIN(CSWAP) on qubit
double *makeFredkinOnQubit(double *qubit, const int QUBIT_COLUMNS) {
    double sum;
    double *outputQubit = new double[THREE_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0.0;
            for (int k = 0; k < THREE_ARGUMENTS_GATE_SIZE; k++) {
                sum += FREDKIN_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make TOFFOLI(CCNOT) on qubit
double *makeToffoliOnQubit(double *qubit, const int QUBIT_COLUMNS) {
    double sum;
    double *outputQubit = new double[THREE_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS; j++) {
            sum = 0.0;
            for (int k = 0; k < THREE_ARGUMENTS_GATE_SIZE; k++) {
                sum += TOFFOLI_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

//////////////////////////////////////////////////////////////////////////
// Helper functions - multiply matrix elements and scalar eg. 1/2, 1/sqrt(2)
complex<double> **multiplySqrtNotScalarByMatrix() {
    auto **matrix = new complex<double> *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        matrix[i] = new complex<double>[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            matrix[i][j] = SQRT_NOT_QUANTUM_GATE[i][j];
        }
    }

    cout << "Defined matrix: " << endl;
    printComplexMatrix(matrix, ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            matrix[i][j] = SQRT_NOT_QUANTUM_GATE[i][j] * FACTOR_SQRT_NOT_GATE;
        }
    }

    cout << "Matrix after multiplication by scalar (1/2): " << endl;
    printComplexMatrix(matrix, ONE_ARGUMENT_GATE_SIZE);

    return matrix;
}

complex<double> **multiplyHadamardScalarByMatrix() {
    auto **matrix = new complex<double> *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        matrix[i] = new complex<double>[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            matrix[i][j] = HADAMARD_QUANTUM_GATE[i][j];
        }
    }

    cout << "Defined matrix: " << endl;
    printComplexMatrix(matrix, ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            matrix[i][j] = HADAMARD_QUANTUM_GATE[i][j] * FACTOR_HADAMARD_GATE;
        }
    }

    cout << "Matrix after multiplication by scalar (1/sqrt(2)): " << endl;
    printComplexMatrix(matrix, ONE_ARGUMENT_GATE_SIZE);

    return matrix;
}