#include <complex>
#include "headers/quantumGate.h"

vector2d composeQuantumGates(vector2d firstGate, vector2d secondGate) {
    vector2d outputGate = getPreparedContainerForQuantumGate(firstGate.size());

    for (int i = 0; i < firstGate.size(); i++) {
        for (int j = 0; j < firstGate[0].size(); j++) {
            for (int k = 0; k < firstGate.size(); k++) {
                outputGate[i][j] += firstGate[i][k] * secondGate[k][j];
            }
        }
    }

    return outputGate;
}

vector2d getIdentityMatrix(int gateSize) {
    vector2d identityMatrix = getPreparedContainerForQuantumGate(gateSize);

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

bool isIdentityMatrixAndComposedGatesAreEqual(vector2d identityMatrix, vector2d composedGates) {
    double epsilon = 0.0000001;
    for (int i = 0; i < identityMatrix.size(); i++) {
        for (int j = 0; j < identityMatrix.size(); j++) {
            if (fabs(identityMatrix[i][j] - composedGates[i][j]) >= epsilon) {
                return false;
            }
        }
    }

    return true;
}

bool isComposeOfGatesGivesIdentityMatrix(vector2d firstGate, vector2d secondGate) {
    vector2d identityMatrix = getIdentityMatrix(firstGate.size());
    vector2d outputGate = composeQuantumGates(firstGate, secondGate);

    return isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, outputGate);
}

bool isMatrixUnitary(vector2d quantumGate, vector2d conjugateTransposedQuantumGate) {
    vector2d identityMatrix = getIdentityMatrix(quantumGate.size());
    vector2d firstConditionMatrix = composeQuantumGates(quantumGate, conjugateTransposedQuantumGate);
    vector2d secondConditionMatrix = composeQuantumGates(conjugateTransposedQuantumGate, quantumGate);

    bool isFirstConditionDone = isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, firstConditionMatrix);
    bool isSecondConditionDone = isIdentityMatrixAndComposedGatesAreEqual(identityMatrix, secondConditionMatrix);
    return isFirstConditionDone && isSecondConditionDone;
}
