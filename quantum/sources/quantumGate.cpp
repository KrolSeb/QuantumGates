#include <iostream>
#include "headers/quantumGate.h"
#include "headers/qubitOperation.h"

/// @param - NOT quantum gate matrix representation
const vector2d NOT_QUANTUM_GATE = {{0, 1},
                                   {1, 0}};

/// @params - SQRT(NOT) quantum gate matrix representation
const double FACTOR_SQRT_NOT_GATE = 0.5;
const complex<double> complexOneAndOne(1, 1);
const complex<double> complexOneAndMinusOne(1, -1);
const vector2d SQRT_NOT_QUANTUM_GATE = {{FACTOR_SQRT_NOT_GATE * complexOneAndOne,      FACTOR_SQRT_NOT_GATE * complexOneAndMinusOne},
                                        {FACTOR_SQRT_NOT_GATE * complexOneAndMinusOne, FACTOR_SQRT_NOT_GATE * complexOneAndOne}};

/// @param - CNOT quantum gate matrix representation
const vector2d CNOT_QUANTUM_GATE = {{1, 0, 0, 0},
                                    {0, 1, 0, 0},
                                    {0, 0, 0, 1},
                                    {0, 0, 1, 0}};

/// @param - SWAP quantum gate matrix representation
const vector2d SWAP_QUANTUM_GATE = {{1, 0, 0, 0},
                                    {0, 0, 1, 0},
                                    {0, 1, 0, 0},
                                    {0, 0, 0, 1}};

/// @param - FREDKIN(CSWAP) quantum gate matrix representation
const vector2d FREDKIN_QUANTUM_GATE = {{1, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 1, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 1, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 1, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 1, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 1, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 1}};

/// @param - TOFFOLI(CCNOT) quantum gate matrix representation
const vector2d TOFFOLI_QUANTUM_GATE = {{1, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 1, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 1, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 1, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 1, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 1, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 1},
                                       {0, 0, 0, 0, 0, 0, 1, 0}};

/// @params - HADAMARD quantum gate matrix representation
const double FACTOR_HADAMARD_GATE = 1 / sqrt(2);
const vector2d HADAMARD_QUANTUM_GATE = {{FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * 1},
                                        {FACTOR_HADAMARD_GATE * 1, FACTOR_HADAMARD_GATE * -1}};

/// @params - PHASE SHIFT quantum gate matrix representation
const double EULER = exp(1.0);
const complex<double> I_COMPLEX_VALUE(0, 1);
const vector2d PHASE_SHIFT_QUANTUM_GATE = {{1, 0},
                                           {0, EULER}};

/// @param - PAULI X(NOT) quantum gate matrix representation
const vector2d PAULI_X_QUANTUM_GATE = {{0, 1},
                                       {1, 0}};

/// @param - PAULI Y quantum gate matrix representation
const complex<double> MINUS_I_COMPLEX_VALUE(0, -1);
const vector2d PAULI_Y_QUANTUM_GATE = {{0, MINUS_I_COMPLEX_VALUE},
                                       {I_COMPLEX_VALUE, 0}};

/// @param - PAULI Z(PHASE SHIFT for PI argument) quantum gate matrix representation
const vector2d PAULI_Z_QUANTUM_GATE = {{1, 0},
                                       {0, -1}};

vector2d getPreparedContainerForQuantumGate(int dimension) {
    vector2d vector;
    vector.resize(dimension);
    for (int i = 0; i < dimension; i++) {
        vector[i].resize(dimension);
    }

    return vector;
}

vector2d multiplyQuantumGateAndQubit(vector2d outputQubit, vector2d quantumGate, vector2d qubit) {
    for (int i = 0; i < qubit.size(); i++) {
        for (int j = 0; j < qubit[0].size(); j++) {
            for (int k = 0; k < qubit.size(); k++) {
                outputQubit[i][j] += quantumGate[i][k] * qubit[k][j];
            }
        }
    }

    return outputQubit;
}

vector2d makeNotOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, NOT_QUANTUM_GATE, qubit);
}

vector2d makeSqrtNotOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, SQRT_NOT_QUANTUM_GATE, qubit);
}

vector2d makeCnotOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(TWO_QUBITS_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, CNOT_QUANTUM_GATE, qubit);
}

vector2d makeSwapOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(TWO_QUBITS_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, SWAP_QUANTUM_GATE, qubit);
}

vector2d makeFredkinOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(THREE_QUBITS_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, FREDKIN_QUANTUM_GATE, qubit);
}

vector2d makeToffoliOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(THREE_QUBITS_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, TOFFOLI_QUANTUM_GATE, qubit);
}

vector2d makeHadamardOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, HADAMARD_QUANTUM_GATE, qubit);
}

/// Helper function used to set correct form of PHASE SHIFT quantum gate
/// Updating phase shift quantum gates elements via Euler's formula - e^ix
/// \param phaseShiftQuantumGate vector2d
/// \param angle double
void setPhaseShiftAngle(vector2d &phaseShiftQuantumGate, double angle) {
    int lastIndex = phaseShiftQuantumGate.size() - 1;
    phaseShiftQuantumGate = PHASE_SHIFT_QUANTUM_GATE;
    phaseShiftQuantumGate[lastIndex][lastIndex] = exp(I_COMPLEX_VALUE * angle);
}

/// Helper function used to return updated PHASE SHIFT quantum gate
/// \param angle double
/// \return phase shift quantum gate
vector2d getUpdatedPhaseShiftQuantumGate(double angle) {
    vector2d phaseShiftQuantumGate = getPreparedContainerForQuantumGate(SINGLE_QUBIT_NUMBER_OF_ROWS);
    setPhaseShiftAngle(phaseShiftQuantumGate, angle);
    return phaseShiftQuantumGate;
}

vector2d makePhaseShiftOnQubit(vector2d qubit, double angle) {
    vector2d phaseShiftQuantumGate = getUpdatedPhaseShiftQuantumGate(angle);
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);

    return multiplyQuantumGateAndQubit(outputQubit, phaseShiftQuantumGate, qubit);
}

vector2d makePauliXOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, PAULI_X_QUANTUM_GATE, qubit);
}

vector2d makePauliYOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, PAULI_Y_QUANTUM_GATE, qubit);
}

vector2d makePauliZOnQubit(vector2d qubit) {
    vector2d outputQubit = getPreparedContainerForQubit(SINGLE_QUBIT_NUMBER_OF_ROWS);
    return multiplyQuantumGateAndQubit(outputQubit, PAULI_Z_QUANTUM_GATE, qubit);
}

/// Helper function used to Hadamard gate elements and factor value multiplication - eg. 1/sqrt(2) * 1 or -1
/// \param hadamardGate vector2d
/// \param indexNumber int
void multiplyHadamardGateByFactor(vector2d &hadamardGate, int indexNumber) {
    double factorValue = pow((1/sqrt(2)), indexNumber);

    for (int i = 0; i < hadamardGate.size(); i++) {
        for (int j = 0; j < hadamardGate.size(); j++) {
            hadamardGate[i][j] = hadamardGate[i][j] * factorValue;
        }
    }
}

/// Helper function used to set Hadamard gate values
/// \param hadamardGate vector2d
/// \param indexNumber int
void setHadamardGateValues(vector2d &hadamardGate, int indexNumber) {
    for (int i = 1; i < hadamardGate.size(); i += i) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                hadamardGate[j + i][k]   =  hadamardGate[j][k];
                hadamardGate[j][k + i]   =  hadamardGate[j][k];
                hadamardGate[j + i][k + i] = hadamardGate[j][k] * -1.0;
            }
        }
    }

    multiplyHadamardGateByFactor(hadamardGate, indexNumber);
}

/// Helper function used to generation of Hadamard gate for index argument
/// Hadamard H0 definition - hadamardGate[0][0] = 1;
/// \param indexNumber int
/// \return multidimensional Hadamard gate
vector2d generateMultidimensionalHadamardGate(int indexNumber) {
    int gateSize = pow(2, indexNumber);
    vector2d hadamardGate = getPreparedContainerForQuantumGate(gateSize);
    hadamardGate[0][0] = 1;

    if (indexNumber > 0) {
        setHadamardGateValues(hadamardGate, indexNumber);
    }

    return hadamardGate;
}

vector2d makeMultidimensionalHadamardOnQubit(vector2d qubit, vector2d hadamardGate, int indexNumber) {
    if (indexNumber == 0) {
        return qubit;
    }

    if (qubit.size() != hadamardGate.size()) {
        string error = string("Incorrect qubit rows and quantum gate sizes!");
        throw error;
    }

    int gateSize = pow(2, indexNumber);
    vector2d outputQubit = getPreparedContainerForQubit(gateSize);

    return multiplyQuantumGateAndQubit(outputQubit, hadamardGate, qubit);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Functions used to return declared quantum gates

vector2d getNotGate() {
    return NOT_QUANTUM_GATE;
}

vector2d getSqrtNotGate() {
    return SQRT_NOT_QUANTUM_GATE;
}

vector2d getCnotGate() {
    return CNOT_QUANTUM_GATE;
}

vector2d getSwapGate() {
    return SWAP_QUANTUM_GATE;
}

vector2d getFredkinGate() {
    return FREDKIN_QUANTUM_GATE;
}

vector2d getToffoliGate() {
    return TOFFOLI_QUANTUM_GATE;
}

vector2d getHadamardGate() {
    return HADAMARD_QUANTUM_GATE;
}

vector2d getMultidimensionalHadamardGate(int indexNumber) {
    return generateMultidimensionalHadamardGate(indexNumber);
}

vector2d getPhaseShiftGate(double angle) {
    return getUpdatedPhaseShiftQuantumGate(angle);
}

vector2d getPauliXGate() {
    return PAULI_X_QUANTUM_GATE;
}

vector2d getPauliYGate() {
    return PAULI_Y_QUANTUM_GATE;
}

vector2d getPauliZGate() {
    return PAULI_Z_QUANTUM_GATE;
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

void showQuantumGate(vector2d quantumGate) {
    for (int i = 0; i < quantumGate.size(); i++) {
        for (int j = 0; j < quantumGate[i].size(); j++) {
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

void showPhaseShiftQuantumGate(vector2d phaseShiftGate) {
    for (int i = 0; i < phaseShiftGate.size(); i++) {
        for (int j = 0; j < phaseShiftGate[i].size(); j++) {
            if(i == phaseShiftGate.size() - 1 && j == phaseShiftGate.size() - 1) {
                showPhaseShiftGateElement(phaseShiftGate[i][j]);
            }
            else {
                showSingleGateElement(phaseShiftGate[i][j]);
            }
        }
        cout << endl;
    }
}
