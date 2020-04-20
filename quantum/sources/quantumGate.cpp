#include <iostream>
#include "headers/quantumGate.h"
#include "headers/qubitOperation.h"

/// @param - NOT quantum gate matrix representation
const complex<double> NOT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, 1},
                                                                    {1, 0}};

/// @params - SQRT(NOT) quantum gate matrix representation
const double FACTOR_SQRT_NOT_GATE = 0.5;
const complex<double> positiveComplex(1, 1);
const complex<double> negativeComplex(1, -1);
const complex<double> SQRT_NOT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{FACTOR_SQRT_NOT_GATE * positiveComplex, FACTOR_SQRT_NOT_GATE * negativeComplex},
                                                                         {FACTOR_SQRT_NOT_GATE * negativeComplex, FACTOR_SQRT_NOT_GATE * positiveComplex}};

/// @param - CNOT quantum gate matrix representation
const complex<double> CNOT_QUANTUM_GATE[][TWO_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0},
                                                                      {0, 1, 0, 0},
                                                                      {0, 0, 0, 1},
                                                                      {0, 0, 1, 0}};

/// @param - SWAP quantum gate matrix representation
const complex<double> SWAP_QUANTUM_GATE[][TWO_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0},
                                                                      {0, 0, 1, 0},
                                                                      {0, 1, 0, 0},
                                                                      {0, 0, 0, 1}};

/// @param - FREDKIN(CSWAP) quantum gate matrix representation
const complex<double> FREDKIN_QUANTUM_GATE[][THREE_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0, 0, 0, 0, 0},
                                                                           {0, 1, 0, 0, 0, 0, 0, 0},
                                                                           {0, 0, 1, 0, 0, 0, 0, 0},
                                                                           {0, 0, 0, 1, 0, 0, 0, 0},
                                                                           {0, 0, 0, 0, 1, 0, 0, 0},
                                                                           {0, 0, 0, 0, 0, 0, 1, 0},
                                                                           {0, 0, 0, 0, 0, 1, 0, 0},
                                                                           {0, 0, 0, 0, 0, 0, 0, 1}};

/// @param - TOFFOLI(CCNOT) quantum gate matrix representation
const complex<double> TOFFOLI_QUANTUM_GATE[][THREE_ARGUMENTS_GATE_SIZE] = {{1, 0, 0, 0, 0, 0, 0, 0},
                                                                           {0, 1, 0, 0, 0, 0, 0, 0},
                                                                           {0, 0, 1, 0, 0, 0, 0, 0},
                                                                           {0, 0, 0, 1, 0, 0, 0, 0},
                                                                           {0, 0, 0, 0, 1, 0, 0, 0},
                                                                           {0, 0, 0, 0, 0, 1, 0, 0},
                                                                           {0, 0, 0, 0, 0, 0, 0, 1},
                                                                           {0, 0, 0, 0, 0, 0, 1, 0}};

/// @params - Hadamard quantum gate matrix representation
const double FACTOR_HADAMARD_GATE = 1 / sqrt(2);
const complex<double> HADAMARD_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * 1},
                                                                         {FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * -1}};

/// @params - Phase shift quantum gate matrix representation
const double EULER = exp(1.0);
const complex<double> I_COMPLEX_VALUE(0, 1);
const complex<double> PHASE_SHIFT_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{1, 0},
                                                                            {0, EULER}};

/// @param - PAULI X(NOT) quantum gate matrix representation
const complex<double> PAULI_X_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, 1},
                                                                        {1, 0}};

/// @param - PAULI Y quantum gate matrix representation
const complex<double> MINUS_I_COMPLEX_VALUE(0, -1);
const complex<double> PAULI_Y_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{0, MINUS_I_COMPLEX_VALUE},
                                                                        {I_COMPLEX_VALUE, 0}};

/// @param - PAULI Z(PHASE SHIFT for PI argument) quantum gate matrix representation
const complex<double> PAULI_Z_QUANTUM_GATE[][ONE_ARGUMENT_GATE_SIZE] = {{1, 0},
                                                                        {0, -1}};

complex<double> **getAllocatedQuantumGate(int dimension) {
    complex<double> **matrix = new complex<double>*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new complex<double>[dimension];
    }

    return matrix;
}

complex<double> **makeNotOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += NOT_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeSqrtNotOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += SQRT_NOT_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeCnotOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(TWO_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < TWO_ARGUMENTS_GATE_SIZE; k++) {
                sum += CNOT_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeSwapOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(TWO_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < TWO_ARGUMENTS_GATE_SIZE; k++) {
                sum += SWAP_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeFredkinOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(THREE_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < THREE_ARGUMENTS_GATE_SIZE; k++) {
                sum += FREDKIN_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeToffoliOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(THREE_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < THREE_ARGUMENTS_GATE_SIZE; k++) {
                sum += TOFFOLI_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makeHadamardOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += HADAMARD_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }
    return outputQubit;
}

/// Helper function used to set correct form of PHASE SHIFT quantum gate
/// Updating phase shift quantum gates elements via Euler's formula - e^ix
/// \param phaseShiftQuantumGate complex<double>
/// \param angle double
void setPhaseShiftAngle(complex<double> **phaseShiftQuantumGate, double angle) {
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            phaseShiftQuantumGate[i][j] = PHASE_SHIFT_QUANTUM_GATE[i][j];
            if (phaseShiftQuantumGate[i][j] == EULER) {
                phaseShiftQuantumGate[i][j] = exp(I_COMPLEX_VALUE * angle);
            }
        }
    }
}

/// Helper function used to return updated PHASE SHIFT quantum gate
/// \param angle double
/// \return phase shift quantum gate
complex<double> **getUpdatedPhaseShiftQuantumGate(double angle) {
    complex<double> **phaseShiftQuantumGate = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);
    setPhaseShiftAngle(phaseShiftQuantumGate, angle);

    return phaseShiftQuantumGate;
}

complex<double> **makePhaseShiftOnQubit(complex<double> **qubit, double angle) {
    complex<double> sum;
    complex<double> **phaseShiftQuantumGate = getUpdatedPhaseShiftQuantumGate(angle);
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += phaseShiftQuantumGate[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makePauliXOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_X_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makePauliYOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_Y_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

complex<double> **makePauliZOnQubit(complex<double> **qubit) {
    complex<double> sum;
    complex<double> **outputQubit = getAllocatedQubit(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < ONE_ARGUMENT_GATE_SIZE; k++) {
                sum += PAULI_Z_QUANTUM_GATE[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

/// Helper function used to Hadamard gate elements and factor value multiplication - eg. 1/sqrt(2) * 1 or -1
/// \param hadamardGate complex<double>
/// \param gateSize int
/// \param indexNumber int
void multiplyHadamardGateByFactor(complex<double> **hadamardGate, int gateSize, int indexNumber) {
    double factorValue = pow((1/sqrt(2)), indexNumber);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            hadamardGate[i][j] = hadamardGate[i][j] * factorValue;
        }
    }
}

/// Helper function used to set Hadamard gate values
/// \param hadamardGate complex<double>
/// \param gateSize int
/// \param indexNumber int
void setHadamardGateValues(complex<double> **hadamardGate, int gateSize, int indexNumber) {
    for (int i = 1; i < gateSize; i += i) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                hadamardGate[j + i][k]   =  hadamardGate[j][k];
                hadamardGate[j][k + i]   =  hadamardGate[j][k];
                hadamardGate[j + i][k + i] = hadamardGate[j][k] * -1.0;
            }
        }
    }

    multiplyHadamardGateByFactor(hadamardGate, gateSize, indexNumber);
}

/// Helper function used to generation Hadamard gate of declared size
/// Hadamard H0 definition - hadamardGate[0][0] = 1;
/// \param indexNumber int
/// \return multidimensional Hadamard gate
complex<double> **generateMultidimensionalHadamardGate(int indexNumber) {
    int gateSize = pow(2, indexNumber);
    complex<double> **hadamardGate = getAllocatedQuantumGate(gateSize);
    hadamardGate[0][0] = 1;

    if (indexNumber > 0) {
        setHadamardGateValues(hadamardGate, gateSize, indexNumber);
    }

    return hadamardGate;
}

complex<double> **makeMultidimensionalHadamardOnQubit(complex<double> **qubit, int numberOfQubits,
                                                      complex<double> **hadamardGate, int indexNumber) {
    complex<double> sum;
    int gateSize = pow(2, indexNumber);
    int qubitRows = pow(2, numberOfQubits);

    if (indexNumber == 0) {
        return qubit;
    }

    if (gateSize != qubitRows) {
        string error = string("Incorrect sizes: gateSize = 2^indexNumber = 2^") + to_string(indexNumber) + " = " +
                       to_string(gateSize) + " and qubitRows = 2^qubitsNumber = 2^" + to_string(numberOfQubits) + " = " +
                       to_string(qubitRows);
        throw error;
    }

    complex<double> **outputQubit = getAllocatedQubit(gateSize);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            sum = complex<double>(0, 0);
            for (int k = 0; k < gateSize; k++) {
                sum += hadamardGate[i][k] * qubit[k][j];
            }
            outputQubit[i][j] = sum;
        }
    }

    return outputQubit;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions used to return declared quantum gates

complex<double> **getNotGate() {
    complex<double> **notGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            notGateToReturn[i][j] = NOT_QUANTUM_GATE[i][j];
        }
    }

    return notGateToReturn;
}

complex<double> **getSqrtNotGate() {
    complex<double> **sqrtNotGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            sqrtNotGateToReturn[i][j] = SQRT_NOT_QUANTUM_GATE[i][j];
        }
    }

    return sqrtNotGateToReturn;
}

complex<double> **getCnotGate() {
    complex<double> **cnotGateToReturn = getAllocatedQuantumGate(TWO_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < TWO_ARGUMENTS_GATE_SIZE; j++) {
            cnotGateToReturn[i][j] = CNOT_QUANTUM_GATE[i][j];
        }
    }

    return cnotGateToReturn;
}

complex<double> **getSwapGate() {
    complex<double> **swapGateToReturn = getAllocatedQuantumGate(TWO_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < TWO_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < TWO_ARGUMENTS_GATE_SIZE; j++) {
            swapGateToReturn[i][j] = SWAP_QUANTUM_GATE[i][j];
        }
    }

    return swapGateToReturn;
}

complex<double> **getFredkinGate() {
    complex<double> **fredkinGateToReturn = getAllocatedQuantumGate(THREE_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < THREE_ARGUMENTS_GATE_SIZE; j++) {
            fredkinGateToReturn[i][j] = FREDKIN_QUANTUM_GATE[i][j];
        }
    }

    return fredkinGateToReturn;
}

complex<double> **getToffoliGate() {
    complex<double> **toffoliGateToReturn = getAllocatedQuantumGate(THREE_ARGUMENTS_GATE_SIZE);

    for (int i = 0; i < THREE_ARGUMENTS_GATE_SIZE; i++) {
        for (int j = 0; j < THREE_ARGUMENTS_GATE_SIZE; j++) {
            toffoliGateToReturn[i][j] = TOFFOLI_QUANTUM_GATE[i][j];
        }
    }

    return toffoliGateToReturn;
}

complex<double> **getHadamardGate() {
    complex<double> **hadamardGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            hadamardGateToReturn[i][j] = HADAMARD_QUANTUM_GATE[i][j];
        }
    }

    return hadamardGateToReturn;
}

complex<double> **getMultidimensionalHadamardGate(int indexNumber) {
    return generateMultidimensionalHadamardGate(indexNumber);
}

complex<double> **getPhaseShiftGate(double angle) {
    return getUpdatedPhaseShiftQuantumGate(angle);
}

complex<double> **getPauliXGate() {
    complex<double> **pauliXGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliXGateToReturn[i][j] = PAULI_X_QUANTUM_GATE[i][j];
        }
    }

    return pauliXGateToReturn;
}

complex<double> **getPauliYGate() {
    complex<double> **pauliYGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliYGateToReturn[i][j] = PAULI_Y_QUANTUM_GATE[i][j];
        }
    }

    return pauliYGateToReturn;
}

complex<double> **getPauliZGate() {
    complex<double> **pauliZGateToReturn = getAllocatedQuantumGate(ONE_ARGUMENT_GATE_SIZE);

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            pauliZGateToReturn[i][j] = PAULI_Z_QUANTUM_GATE[i][j];
        }
    }

    return pauliZGateToReturn;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions used to show declared quantum gates

/// Used to show single formatted element of quantum gate
/// \param gateElement complex<double>
void showSingleGateElement(complex<double> gateElement) {
    if (imag(gateElement) == 0) {
        cout << real(gateElement) << " ";
    }
    else if (real(gateElement) == 0 && imag(gateElement) == 1) {
        cout << "i ";
    }
    else if (real(gateElement) == 0 && imag(gateElement) == -1) {
        cout << "-i ";
    }
    else if (real(gateElement) == 0) {
        cout << imag(gateElement) << "i ";
    }
    else {
        if (imag(gateElement) > 0) {
            cout << real(gateElement) << "+" << imag(gateElement) << "i ";
        }
        else {
            cout << real(gateElement) << imag(gateElement) << "i ";
        }
    }
}

void showQuantumGate(complex<double> **quantumGate, const int gateSize) {
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            showSingleGateElement(quantumGate[i][j]);
        }
        cout << endl;
    }
}

void showPhaseShiftGateElement(complex<double> gateElement) {
    cout.precision(0);
    if (imag(gateElement) == 0 || round(imag(gateElement)) == 0) {
        cout << fixed << real(gateElement) << " ";
    }
    else if (real(gateElement) == 0 && imag(gateElement) == 1) {
        cout << fixed << "i ";
    }
    else if (real(gateElement) == 0 && imag(gateElement) == -1) {
        cout << fixed <<"-i ";
    }
    else if (real(gateElement) == 0 || round(real(gateElement)) == 0) {
        cout << fixed << imag(gateElement) << "i ";
    }
    else {
        if (imag(gateElement) > 0) {
            cout << fixed << real(gateElement) << "+" << imag(gateElement) << "i ";
        }
        else {
            cout << fixed << real(gateElement) << imag(gateElement) << "i ";
        }
    }
    cout << defaultfloat;
}

void showPhaseShiftQuantumGate(complex<double> **phaseShiftGate, const int gateSize) {
    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            if(i == gateSize-1 && j == gateSize-1) {
                showPhaseShiftGateElement(phaseShiftGate[i][j]);
            }
            else {
                showSingleGateElement(phaseShiftGate[i][j]);
            }
        }
        cout << endl;
    }
}

void showMultidimensionalHadamardGate(complex<double> **hadamardGate, int indexNumber) {
    int gateSize = pow(2, indexNumber);

    for (int i = 0; i < gateSize; i++) {
        for (int j = 0; j < gateSize; j++) {
            showSingleGateElement(hadamardGate[i][j]);
        }
        cout <<  endl;
    }
}