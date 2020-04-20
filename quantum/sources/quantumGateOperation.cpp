#include <complex>
#include "headers/quantumGate.h"

complex<double> **composeQuantumGates(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    complex<double> **outputGate = getAllocatedQuantumGate(gateSize);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            for (int k = 0; k < gateSize; k++) {
                outputGate[i][j] += firstGate[i][k] * secondGate[k][j];
            }
        }
    }

    return outputGate;
}

complex<double> **getIdentityMatrix(int gateSize) {
    complex<double> **identityMatrix = getAllocatedQuantumGate(gateSize);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if (i == j) {
                identityMatrix[i][j] = 1;
            }
            else {
                identityMatrix[i][j] = 0;
            }
        }
    }

    return identityMatrix;
}

bool isIdentityMatrixAndComposedGatesAreEqual(complex<double> **identityMatrix, complex<double> **composedGates, int gateSize) {
    double epsilon = 0.0000001;
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if(fabs(identityMatrix[i][j] - composedGates[i][j]) >= epsilon) {
                return false;
            }
        }
    }

    return true;
}

bool isComposeOfGatesGivesIdentityMatrix(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    complex<double> **identityMatrix = getIdentityMatrix(gateSize);
    complex<double> **outputGate = composeQuantumGates(firstGate, secondGate, gateSize);

    return isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, outputGate, gateSize);
}

bool isMatrixUnitary(complex<double> **quantumGate, complex<double> **conjugateTransposedQuantumGate, int gateSize) {
    complex<double> **identityMatrix = getIdentityMatrix(gateSize);
    complex<double> **firstConditionMatrix = composeQuantumGates(quantumGate, conjugateTransposedQuantumGate, gateSize);
    complex<double> **secondConditionMatrix = composeQuantumGates(conjugateTransposedQuantumGate, quantumGate, gateSize);

    bool isFirstConditionDone = isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, firstConditionMatrix, gateSize);
    bool isSecondConditionDone = isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, secondConditionMatrix, gateSize);
    return isFirstConditionDone && isSecondConditionDone;
}
