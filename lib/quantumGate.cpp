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
    for (int i = 1; i < gateSize; i += i) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                hadamardGate[j + i][k]   =  hadamardGate[j][k];
                hadamardGate[j][k + i]   =  hadamardGate[j][k];
                hadamardGate[j + i][k + i] = hadamardGate[j][k] * -1;
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

/// Function used to make multidimensional Hadamard on qubit
double *makeMultidimensionalHadamardOnQubit(double **hadamardGate, int indexNumber, double *qubit, int qubitsNumber) {
    double sum;
    int gateSize = pow(2, indexNumber);
    int qubitRows = pow(2, qubitsNumber);

    if (indexNumber == 0) {
        return qubit;
    }

    if (gateSize != qubitRows) {
        string error = string("Incorrect sizes: gateSize = 2^indexNumber = 2^") + to_string(indexNumber) + " = " + to_string(gateSize) +
                       " and qubitRows = 2^qubitsNumber = 2^" + to_string(qubitsNumber) + " = " + to_string(qubitRows);
        throw error;
    }

    double *outputQubit = new double[gateSize];
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < QUBIT_COLUMNS_SIZE; j++) {
            sum = 0.0;
            for (int k = 0; k < gateSize; k++) {
                sum += hadamardGate[i][k] * qubit[k];
            }
            outputQubit[i] = sum;
        }
    }

    return outputQubit;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions used to return declared quantum gate

/// Function used to get NOT gate
double **getNotGate() {
    double **notGateToReturn = new double *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        notGateToReturn[i] = new double[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            notGateToReturn[i][j] = NOT_QUANTUM_GATE[i][j];
        }
    }

    return notGateToReturn;
}

/// Function used to get SQRT(NOT) gate
complex<double> **getSqrtNotGate() {
    complex<double> **sqrtNotGateToReturn = new complex<double> *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        sqrtNotGateToReturn[i] = new complex<double>[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            sqrtNotGateToReturn[i][j] = SQRT_NOT_QUANTUM_GATE[i][j];
        }
    }

    return sqrtNotGateToReturn;
}

/// Function used to get CNOT gate
double **getCnotGate() {
    double **cnotGateToReturn = new double *[TWO_ARGUMENTS_GATE_SIZE];
    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        cnotGateToReturn[i] = new double[TWO_ARGUMENTS_GATE_SIZE];
    }

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < TWO_ARGUMENTS_GATE_SIZE; j++) {
            cnotGateToReturn[i][j] = CNOT_QUANTUM_GATE[i][j];
        }
    }

    return cnotGateToReturn;
}

/// Function used to get SWAP gate
double **getSwapGate() {
    double **swapGateToReturn = new double *[TWO_ARGUMENTS_GATE_SIZE];
    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        swapGateToReturn[i] = new double[TWO_ARGUMENTS_GATE_SIZE];
    }

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < TWO_ARGUMENTS_GATE_SIZE; j++) {
            swapGateToReturn[i][j] = SWAP_QUANTUM_GATE[i][j];
        }
    }

    return swapGateToReturn;
}

/// Function used to get FREDKIN gate
double **getFredkinGate() {
    double **fredkinGateToReturn = new double *[THREE_ARGUMENTS_GATE_SIZE];
    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        fredkinGateToReturn[i] = new double[THREE_ARGUMENTS_GATE_SIZE];
    }

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < THREE_ARGUMENTS_GATE_SIZE; j++) {
            fredkinGateToReturn[i][j] = FREDKIN_QUANTUM_GATE[i][j];
        }
    }

    return fredkinGateToReturn;
}

/// Function used to get TOFFOLI gate
double **getToffoliGate() {
    double **toffoliGateToReturn = new double *[THREE_ARGUMENTS_GATE_SIZE];
    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        toffoliGateToReturn[i] = new double[THREE_ARGUMENTS_GATE_SIZE];
    }

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < THREE_ARGUMENTS_GATE_SIZE; j++) {
            toffoliGateToReturn[i][j] = TOFFOLI_QUANTUM_GATE[i][j];
        }
    }

    return toffoliGateToReturn;
}

/// Function used to get HADAMARD gate
double **getHadamardGate() {
    double **hadamardGateToReturn = new double *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        hadamardGateToReturn[i] = new double[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            hadamardGateToReturn[i][j] = HADAMARD_QUANTUM_GATE[i][j];
        }
    }

    return hadamardGateToReturn;
}

/// Function used to get multidimensional HADAMARD gate
double **getMultidimensionalHadamardGate(int indexNumber) {
    return generateMultidimensionalHadamardGate(indexNumber);
}

/// Function used to get PHASE SHIFT gate
double **getPhaseShiftGate(double angle) {
    return getUpdatedPhaseShiftQuantumGate(angle);
}

/// Function used to get PAULI X gate
double **getPauliXGate() {
    double **pauliXGateToReturn = new double *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        pauliXGateToReturn[i] = new double[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliXGateToReturn[i][j] = PAULI_X_QUANTUM_GATE[i][j];
        }
    }

    return pauliXGateToReturn;
}

/// Function used to get PAULI Y gate
complex<double> **getPauliYGate() {
    complex<double> **pauliYGateToReturn = new complex<double> *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        pauliYGateToReturn[i] = new complex<double>[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliYGateToReturn[i][j] = PAULI_Y_QUANTUM_GATE[i][j];
        }
    }

    return pauliYGateToReturn;
}

/// Function used to get PAULI Z gate
double **getPauliZGate() {
    double **pauliZGateToReturn = new double *[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        pauliZGateToReturn[i] = new double[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliZGateToReturn[i][j] = PAULI_Z_QUANTUM_GATE[i][j];
        }
    }

    return pauliZGateToReturn;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions used to show declared quantum gates

/// Function used to print any quantum gate
void printQuantumGate(double **quantumGate, const int gateSize) {
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            cout << quantumGate[i][j] << " ";
        }
        cout << endl;
    }
}

/// Function used to print any complex quantum gate
void printComplexQuantumGate(complex<double> **quantumGate, const int gateSize) {
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if (imag(quantumGate[i][j]) >= 0) {
                cout << real(quantumGate[i][j]) << "+" << imag(quantumGate[i][j]) << "i" << " ";
            }
            else if (real(quantumGate[i][j]) == 0 && imag(quantumGate[i][j]) == 0) {
                cout << real(quantumGate[i][j]) << " ";
            }
            else {
                cout << real(quantumGate[i][j]) << imag(quantumGate[i][j]) << "i" << " ";
            }
        }
        cout << endl;
    }
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