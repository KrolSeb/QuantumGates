#include <iostream>
#include "headers/quantumGate.h"

/// @params - matrix representations of quantum logic gates
const int NOT_GATE_DIMENSION = 2;
const int NOT_QUANTUM_GATE[][NOT_GATE_DIMENSION] = {{0, 1},
                                                    {1, 0}};

/// Function used to show quantum gate on output - int type
void printLogicGateRepresentation() {
    for (int i = 0; i < NOT_GATE_DIMENSION; i++) {
        for (int j = 0; j < NOT_GATE_DIMENSION; j++) {
            cout << NOT_QUANTUM_GATE[i][j];
        }
        cout << endl;
    }
    cout << endl;
}