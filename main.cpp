#include <iostream>
#include <complex>
#include <ctime>
#include "headers/qubitOperation.h"
#include "headers/quantumComputer.h"
#include "headers/quantumGate.h"
#include "headers/quantumGateOperation.h"
#include "headers/matrixOperation.h"

using namespace std;
using namespace quantum;

void generateHermitianMatrix(int dimension) {
    cout << "Test of generation random hermitian matrix" << endl;
    cout << "Rows and Columns size: " << dimension << endl;

    complex<double> **originalMatrix = getRandomHermitianMatrix(dimension);
    cout << "Original matrix: " << endl;
    showMatrix(originalMatrix, dimension);

    complex<double> **transposedAndConjugatedMatrix = makeConjugateTranspose(originalMatrix, dimension, dimension);
    cout << "Matrix after conjugate transpose: " << endl;
    showMatrix(transposedAndConjugatedMatrix, dimension);

    delete (originalMatrix);
    delete (transposedAndConjugatedMatrix);
}

complex<double> **generateQubit(int numberOfQubits, double *probabilities) {
    int arraySize = pow(2, numberOfQubits);
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);
    quantumComputer.viewProbability();
    quantumComputer.viewQubitsInMathExpression();

    return getQubitRepresentation(quantumComputer.getBaseVector());
}

void performNotGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before NOT:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit after NOT:" << endl;
    showQubit(makeNotOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performSqrtNotGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before SQRT(NOT):" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit after SQRT(NOT):" << endl;
    showQubit(makeSqrtNotOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performCnotGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before CNOT:" << endl;
    showQubit(qubit, TWO_QUBITS_NUMBER_OF_ROWS);
    cout << "Qubit after CNOT:" << endl;
    showQubit(makeCnotOnQubit(qubit), TWO_QUBITS_NUMBER_OF_ROWS);
}

void performSwapGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before SWAP:" << endl;
    showQubit(qubit, TWO_QUBITS_NUMBER_OF_ROWS);
    cout << "Qubit after SWAP:" << endl;
    showQubit(makeSwapOnQubit(qubit), TWO_QUBITS_NUMBER_OF_ROWS);
}

void performFredkinGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before FREDKIN:" << endl;
    showQubit(qubit, THREE_QUBITS_NUMBER_OF_ROWS);
    cout << "Qubit after FREDKIN:" << endl;
    showQubit(makeFredkinOnQubit(qubit), THREE_QUBITS_NUMBER_OF_ROWS);
}

void performToffoliGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before TOFFOLI:" << endl;
    showQubit(qubit, THREE_QUBITS_NUMBER_OF_ROWS);
    cout << "Qubit after TOFFOLI:" << endl;
    showQubit(makeToffoliOnQubit(qubit), THREE_QUBITS_NUMBER_OF_ROWS);
}

void performHadamardGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before HADAMARD:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit after HADAMARD:" << endl;
    showQubit(makeHadamardOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performPhaseShiftGateOnQubit(int numberOfQubits, double *probabilities, double angle) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before PHASE SHIFT:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit after PHASE SHIFT:" << endl;
    showQubit(makePhaseShiftOnQubit(qubit, angle), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performPauliXGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit 0 (1 0) before PAULI X:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit 0 (1 0) after PAULI X:" << endl;
    showQubit(makePauliXOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performPauliYGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit 0 (1 0) before PAULI Y:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit 0 (1 0) after PAULI Y:" << endl;
    showQubit(makePauliYOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void performPauliZGateOnQubit(int numberOfQubits, double *probabilities) {
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit 0 (1 0) before PAULI Z:" << endl;
    showQubit(qubit, SINGLE_QUBIT_NUMBER_OF_ROWS);
    cout << "Qubit 0 (1 0) after PAULI Z:" << endl;
    showQubit(makePauliZOnQubit(qubit), SINGLE_QUBIT_NUMBER_OF_ROWS);
}

void getHadamardGateForIndexNumber(int indexNumber) {
    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    cout << "Generated Hadamard gate for n = " << indexNumber << " (H" << indexNumber << ")" << endl;
    showMultidimensionalHadamardGate(hadamardGate, indexNumber);
    cout << endl;
}

void performHadamardGateForIndexNumberOnQubit(int hadamardIndexNumber, int numberOfQubits, double *probabilities) {
    complex<double> **hadamardGate = getMultidimensionalHadamardGate(hadamardIndexNumber);
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);
    int qubitRows = pow(2, numberOfQubits);

    cout << "Qubit before multidimensional Hadamard:" << endl;
    showQubit(qubit, qubitRows);
    cout << "Qubit after multidimensional Hadamard:" << endl;

    try {
        showQubit(makeMultidimensionalHadamardOnQubit(qubit, numberOfQubits, hadamardGate, hadamardIndexNumber), qubitRows);
    }
    catch (const std::string& my_msg){
        cerr << my_msg << endl;
    }
}

void getQuantumGates() {
    cout << "Quantum gates" << endl;

    cout << "NOT gate:" << endl;
    showQuantumGate(getNotGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "SQRT(NOT) gate:" << endl;
    showQuantumGate(getSqrtNotGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "CNOT gate:" << endl;
    showQuantumGate(getCnotGate(), TWO_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "SWAP gate:" << endl;
    showQuantumGate(getSwapGate(), TWO_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "FREDKIN gate:" << endl;
    showQuantumGate(getFredkinGate(), THREE_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "TOFFOLI gate:" << endl;
    showQuantumGate(getToffoliGate(), THREE_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "HADAMARD gate:" << endl;
    showQuantumGate(getHadamardGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PHASE SHIFT gate for PI angle:" << endl;
    showPhaseShiftQuantumGate(getPhaseShiftGate(M_PI), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI X gate:" << endl;
    showQuantumGate(getPauliXGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI Y gate:" << endl;
    showQuantumGate(getPauliYGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI Z gate:" << endl;
    showQuantumGate(getPauliZGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;
}

void performComposeOfQuantumGates(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    if (isComposeOfGatesGivesIdentityMatrix(firstGate, secondGate, gateSize)) {
        cout << "Multiplied gates are EQUAL with identity matrix" << endl;
    }
    else {
        cout << "Multiplied gates are NOT equal with identity matrix" << endl;
    }
    cout << endl;
}

void performDotProductOfQubits(int numberOfQubits, double *probabilities) {
    complex<double> **twoQubits = generateQubit(numberOfQubits, probabilities);
    cout << "Original qubit: " << endl;
    showQubit(twoQubits, TWO_QUBITS_NUMBER_OF_ROWS);

    cout << "Qubit after transposition and conjugation: " << endl;
    complex<double> **transposedAndConjugatedQubit = makeConjugateTranspose(twoQubits, TWO_QUBITS_NUMBER_OF_ROWS,
                                                                            QUBIT_NUMBER_OF_COLUMNS);
    showQubitAfterConjugateTranspose(transposedAndConjugatedQubit, TWO_QUBITS_NUMBER_OF_ROWS);

    cout << "Reverted qubit to original state: " << endl;
    complex<double> **originalQubit = makeConjugateTranspose(transposedAndConjugatedQubit, QUBIT_NUMBER_OF_COLUMNS,
                                                             TWO_QUBITS_NUMBER_OF_ROWS);
    showQubit(originalQubit, TWO_QUBITS_NUMBER_OF_ROWS);

    cout << "Dot product of two qubits: " << endl;
    complex<double> **dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, originalQubit,
                                                          TWO_QUBITS_NUMBER_OF_ROWS, QUBIT_NUMBER_OF_COLUMNS);
    showDotProduct(dotProduct);
}

void performCheckIsMatrixUnitary(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    if (isMatrixUnitary(firstGate, secondGate, gateSize)) {
        cout << "Matrix is UNITARY" << endl;
    }
    else {
        cout << "Matrix is NOT unitary" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    double probabilitiesOfQubit0[] = {1, 0};
    double probabilitiesOfQubit1[] = {0, 1};
    double probabilitiesOfQubits00[] = {1.0, 0.0, 0.0, 0.0};
    double probabilitiesOfQubits01[] = {0.0, 1.0, 0.0, 0.0};
    double probabilitiesOfQubits11[] = {0.0, 0.0, 0.0, 1.0};
    double probabilitiesOfQubits000[] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double probabilitiesOfQubits101[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    double probabilitiesOfQubits111[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0};
    double incorrectProbabilitiesOfThreeQubits[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};

    /// Generating of hermitian matrix for random number from range 2-6
    int dimension = rand() % 4 + 2;
    generateHermitianMatrix(dimension);

    /// Performing NOT and SQRT(NOT) gates on qubit 0
    int numberOfQubits = 1;
    performNotGateOnQubit(numberOfQubits, probabilitiesOfQubit0);
    performSqrtNotGateOnQubit(numberOfQubits, probabilitiesOfQubit0);

    /// Performing CNOT and SWAP gates on two qubits
    numberOfQubits = 2;
    performCnotGateOnQubit(numberOfQubits, probabilitiesOfQubits11);
    performSwapGateOnQubit(numberOfQubits, probabilitiesOfQubits01);

    /// Performing FREDKIN and TOFFOLI gates on qubit 000
    numberOfQubits = 3;
    performFredkinGateOnQubit(numberOfQubits, probabilitiesOfQubits101);
    performToffoliGateOnQubit(numberOfQubits, probabilitiesOfQubits111);

    /// Performing HADAMARD gate on qubit 0
    numberOfQubits = 1;
    performHadamardGateOnQubit(numberOfQubits, probabilitiesOfQubit0);

    /// Performing PHASE SHIFT gate on qubit 0
    double piAngle = M_PI;
    performPhaseShiftGateOnQubit(numberOfQubits, probabilitiesOfQubit0, piAngle);

    /// Performing PAULI X,Y,Z gates on qubit 0
    performPauliXGateOnQubit(numberOfQubits, probabilitiesOfQubit0);
    performPauliYGateOnQubit(numberOfQubits, probabilitiesOfQubit0);
    performPauliZGateOnQubit(numberOfQubits, probabilitiesOfQubit0);

    /// Performing H0 gate on qubit 0
    int hadamardIndexNumber = 0;
    numberOfQubits = 1;
    getHadamardGateForIndexNumber(hadamardIndexNumber);
    performHadamardGateForIndexNumberOnQubit(hadamardIndexNumber, numberOfQubits, probabilitiesOfQubit0);

    /// Performing H1 gate on qubit 0
    hadamardIndexNumber = 1;
    numberOfQubits = 1;
    getHadamardGateForIndexNumber(hadamardIndexNumber);
    performHadamardGateForIndexNumberOnQubit(hadamardIndexNumber, numberOfQubits, probabilitiesOfQubit0);

    /// Performing H2 gate on qubit 00
    hadamardIndexNumber = 2;
    numberOfQubits = 2;
    getHadamardGateForIndexNumber(hadamardIndexNumber);
    performHadamardGateForIndexNumberOnQubit(hadamardIndexNumber, numberOfQubits, probabilitiesOfQubits00);

    /// Performing H3 gate on qubit 000
    hadamardIndexNumber = 3;
    numberOfQubits = 3;
    getHadamardGateForIndexNumber(hadamardIndexNumber);
    performHadamardGateForIndexNumberOnQubit(hadamardIndexNumber, numberOfQubits, probabilitiesOfQubits000);

    /// Getting all constant defined quantum gates
    getQuantumGates();

    /// Composing of quantum gates - gate1 * gate2 = 1 (1 is identity matrix)
    /// Composing of NOT gates
    performComposeOfQuantumGates(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE);

    /// Composing of HADAMARD gates
    performComposeOfQuantumGates(getHadamardGate(), getHadamardGate(), ONE_ARGUMENT_GATE_SIZE);

    /// Composing of PHASE SHIFT gates for F(alfa) and F(-alfa), where alfa = PI
    performComposeOfQuantumGates(getPhaseShiftGate(piAngle), getPhaseShiftGate(-piAngle), ONE_ARGUMENT_GATE_SIZE);

    /// Performing dot product of qubits
    numberOfQubits = 2;
    performDotProductOfQubits(numberOfQubits, probabilitiesOfQubits00);

    /// Performing matrix unitary state check
    performCheckIsMatrixUnitary(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE);
    performCheckIsMatrixUnitary(getSwapGate(), getSwapGate(), TWO_ARGUMENTS_GATE_SIZE);

    return 0;
}