#include <iostream>
#include <complex>

using namespace std;

complex<double> **assembleQuantumGates(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    complex<double> **outputGate = new complex<double> *[gateSize];
    for (int i = 0; i < gateSize; i++) {
        outputGate[i] = new complex<double>[gateSize];
    }

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            for (int k = 0; k < gateSize; k++) {
                outputGate[i][j] += firstGate[i][k] * secondGate[k][j];
            }
        }
    }

    return outputGate;
}

complex<double> **getIdentityMatrixForDefinedSize(int gateSize) {
    complex<double> **identityMatrix = new complex<double> *[gateSize];
    for (int i = 0; i < gateSize; i++) {
        identityMatrix[i] = new complex<double>[gateSize];
    }

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

bool isIdentityMatrixAndMultipliedGatesAreEqual(complex<double> **identityMatrix, complex<double> **multipliedGates, int gateSize) {
    double epsilon = 0.0000001;
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if(fabs(identityMatrix[i][j] - multipliedGates[i][j]) >= epsilon) {
                return false;
            }
        }
    }

    return true;
}

bool isAssemblyOfGatesGiveIdentityMatrix(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    complex<double> **identityMatrix = getIdentityMatrixForDefinedSize(gateSize);
    complex<double> **outputGate = assembleQuantumGates(firstGate, secondGate, gateSize);

    return isIdentityMatrixAndMultipliedGatesAreEqual(identityMatrix, outputGate, gateSize);
}

bool isMatrixUnitary(complex<double> **quantumGate, complex<double> **conjugateTransposedQuantumGate, int gateSize) {
    complex<double> **identityMatrix = getIdentityMatrixForDefinedSize(gateSize);
    complex<double> **firstConditionMatrix = assembleQuantumGates(quantumGate, conjugateTransposedQuantumGate, gateSize);
    complex<double> **secondConditionMatrix = assembleQuantumGates(conjugateTransposedQuantumGate, quantumGate, gateSize);

    bool isFirstConditionDone = isIdentityMatrixAndMultipliedGatesAreEqual(identityMatrix, firstConditionMatrix, gateSize);
    bool isSecondConditionDone = isIdentityMatrixAndMultipliedGatesAreEqual(identityMatrix, secondConditionMatrix, gateSize);
    return isFirstConditionDone && isSecondConditionDone;
}

