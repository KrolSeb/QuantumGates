#include <iostream>
#include "headers/quantumGate.h"

/// @params - matrix representations of quantum logic gates
const int CNOT_MATRIX_DIMENSION = 2;
const int CNOT_LOGIC_GATE[][CNOT_MATRIX_DIMENSION] = {{0, 1},
                                                      {1, 0}};

/// Function used to show matrix on output - int type
void printLogicGateRepresentation() {
    for (int i = 0; i < CNOT_MATRIX_DIMENSION; i++) {
        for (int j = 0; j < CNOT_MATRIX_DIMENSION; j++) {
            cout << CNOT_LOGIC_GATE[i][j];
        }
        cout << endl;
    }
    cout << endl;
}