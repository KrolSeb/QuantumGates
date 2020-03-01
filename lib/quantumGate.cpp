#include <iostream>
#include "headers/quantumGate.h"
#include "headers/temporaryQubit.h"

using namespace std;

/// @params - matrix representations of quantum logic gates
const int NOT_QUANTUM_GATE[][NOT_GATE_COLUMNS] = {{0, 1},
                                                  {1, 0}};

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
