#include <iostream>
#include "headers/quantumGate.h"

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
const complex<double> SQRT_NOT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{FACTOR_SQRT_NOT_GATE * positiveComplex, FACTOR_SQRT_NOT_GATE * negativeComplex},
                                                                         {FACTOR_SQRT_NOT_GATE * negativeComplex, FACTOR_SQRT_NOT_GATE * positiveComplex}};
/// @params - Hadamard quantum gate matrix representation
const double FACTOR_HADAMARD_GATE = 1 / sqrt(2);
const double HADAMARD_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * 1},
                                                                {FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * -1}};

/// @params - Phase shift quantum gate matrix representation
const complex<double> I_COMPLEX_VALUE(0, 1);
const double EULER = exp(1.0);
const double PHASE_SHIFT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{1, 0},
                                                                   {0, EULER}};

/// @param - PAULI X(NOT) quantum gate matrix representation
const double PAULI_X_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, 1},
                                                               {1, 0}};

/// @param - PAULI Y quantum gate matrix representation
const complex<double> MINUS_I_COMPLEX_VALUE(0, -1);
const complex<double> PAULI_Y_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, MINUS_I_COMPLEX_VALUE},
                                                                        {I_COMPLEX_VALUE, 0}};

/// @param - PAULI Z(PHASE SHIFT for PI argument) quantum gate matrix representation
const double PAULI_Z_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{1, 0},
                                                               {0, -1}};

//TODO: Reverse and combining/folding of quantum gates

/// Function used to make NOT on qubit
double *makeNotOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += NOT_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make SQRT(NOT) on qubit
complex<double> *makeSqrtNotOnQubit(double *qubit) {
    complex<double> sum;
    complex<double> *outputQubit = new complex<double>[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += SQRT_NOT_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make CNOT on qubit
double *makeCnotOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[TWO_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
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
double *makeSwapOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[TWO_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
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
double *makeFredkinOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[THREE_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
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
double *makeToffoliOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[THREE_ARGUMENTS_GATE_SIZE];

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < THREE_ARGUMENTS_GATE_SIZE; k++) {
                sum += TOFFOLI_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make HADAMARD(WALSH) on qubit
double *makeHadamardOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += HADAMARD_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }
    return outputQubit;
}

/// Helper function used to set correct form of PHASE SHIFT quantum gate
void setPhaseShiftAngle(double **phaseShiftQuantumGate, double angle) {
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            phaseShiftQuantumGate[i][j] = PHASE_SHIFT_QUANTUM_GATE[i][j];
            if (phaseShiftQuantumGate[i][j] == EULER) {
                //Euler's formula - e^ix = cos(x) + i * sin(x)
                phaseShiftQuantumGate[i][j] = cos(angle) + (imag(I_COMPLEX_VALUE) * sin(angle));
            }
        }
    }
}

/// Helper function used to return updated PHASE SHIFT quantum gate
double **getUpdatedPhaseShiftQuantumGate(double angle) {
    double **phaseShiftQuantumGate = new double *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        phaseShiftQuantumGate[i] = new double[ONE_ARGUMENT_GATE_SIZE];
    }

    setPhaseShiftAngle(phaseShiftQuantumGate, angle);
    return phaseShiftQuantumGate;
}

/// Function used to make PHASE SHIFT on qubit
double *makePhaseShiftOnQubit(double angle, double *qubit) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];
    double **phaseShiftQuantumGate = getUpdatedPhaseShiftQuantumGate(angle);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += phaseShiftQuantumGate[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make PAULI X on qubit
double *makePauliXOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_X_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make PAULI Y on qubit
complex<double> *makePauliYOnQubit(double *qubit) {
    complex<double> sum;
    complex<double> *outputQubit = new complex<double>[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_Y_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to make PAULI Z on qubit
double *makePauliZOnQubit(double *qubit) {
    double sum;
    double *outputQubit = new double[ONE_ARGUMENT_GATE_SIZE];

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_Z_QUANTUM_GATE[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/// Function used to Hadamard gate and factor value multiplication - eg. 1/sqrt(2) * 1 or -1
void multiplyHadamardGateByFactor(double **hadamardGate, int gateSize, int indexNumber) {
    double factorValue = pow((1/sqrt(2)), indexNumber);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            hadamardGate[i][j] = hadamardGate[i][j] * factorValue;
        }
    }
}

/// Function used to setting Hadamard gate values
void setHadamardGateValues(double **hadamardGate, int gateSize, int indexNumber) {
    for (int k = 1; k < gateSize; k += k) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                hadamardGate[i + k][j]   =  hadamardGate[i][j];
                hadamardGate[i][j + k]   =  hadamardGate[i][j];
                hadamardGate[i + k][j + k] = hadamardGate[i][j] * -1;
            }
        }
    }

    multiplyHadamardGateByFactor(hadamardGate, gateSize, indexNumber);
}

/// Function used to generation Hadamard gate of declared size
double **generateMultidimensionalHadamardGate(int indexNumber) {
    int gateSize = pow(2, indexNumber);

    double **hadamardGate = new double *[gateSize];
    for (int i = 0; i < gateSize; i++) {
        hadamardGate[i] = new double[gateSize];
    }
    //Hadamard H0 element definition
    hadamardGate[0][0] = 1;

    if (indexNumber > 0) {
        setHadamardGateValues(hadamardGate, gateSize, indexNumber);
    }

    return hadamardGate;
}

/// Function used to print multidimensional Hadamard gate
void printMultidimensionalHadamardGate(double **hadamardGate, int indexNumber) {
    int gateSize = pow(2, indexNumber);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if (hadamardGate[i][j] > 0) {
                cout << " " << hadamardGate[i][j] << " ";
            }
            else {
                cout << hadamardGate[i][j] << " ";
            }
        }
        cout <<  endl;
    }

}

/// Function used to get multidimensional Hadamard gate
double **getMultidimensionalHadamardGate(int indexNumber) {
    return generateMultidimensionalHadamardGate(indexNumber);
}
