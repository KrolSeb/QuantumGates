#include <iostream>
#include <cmath>

using namespace std;

double **assembleQuantumGates(double **firstGate, double **secondGate, int gateSize) {
    double **outputGate = new double *[gateSize];
    for (int i = 0; i < gateSize; i++) {
        outputGate[i] = new double[gateSize];
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

double **getIdentityMatrixForDefinedSize(int gateSize) {
    double **identityMatrix = new double *[gateSize];
    for (int i = 0; i < gateSize; i++) {
        identityMatrix[i] = new double[gateSize];
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

bool isIdentityMatrixAndMultipliedGatesAreEqual(double **identityMatrix, double **outputGate, int gateSize) {
    double epsilon = 0.0000001;
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if(fabs(identityMatrix[i][j] - outputGate[i][j]) >= epsilon) {
                return false;
            }
        }
    }

    return true;
}

bool isAssemblyOfGatesGiveIdentityMatrix(double **firstGate, double **secondGate, int gateSize) {
    double **identityMatrix = getIdentityMatrixForDefinedSize(gateSize);
    double **outputGate = assembleQuantumGates(firstGate, secondGate, gateSize);

    return isIdentityMatrixAndMultipliedGatesAreEqual(identityMatrix, outputGate, gateSize);
}


