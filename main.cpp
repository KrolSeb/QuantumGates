#include <iostream>
#include <complex>
#include <ctime>
#include "lib/headers/qubitOperation.h"
#include "lib/headers/quantumComputer.h"
#include "lib/headers/quantumGate.h"
#include "lib/headers/quantumGateOperation.h"
#include "lib/headers/matrixOperation.h"

using namespace std;
using namespace quantum;

void testMatrixOperations() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Test of generation random hermitian matrix" << endl;
    int dimension = rand() % 4 + 2;
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

void testNotQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double probabilitiesOfQubit1[] = {0, 1};
    const int numberOfQubits = 1;

    complex<double> **qubit0 = generateQubit(numberOfQubits, probabilitiesOfQubit0);
    cout << "Qubit 0 (1 0) before negation:" << endl;
    showQubit(qubit0, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after negation:" << endl;
    showQubit(makeNotOnQubit(qubit0), ROWS_NUMBER_IN_SINGLE_QUBIT);

    complex<double> **qubit1 = generateQubit(numberOfQubits, probabilitiesOfQubit1);
    cout << "Qubit 1 (0 1) before negation:" << endl;
    showQubit(qubit1, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 1 (0 1) after negation:" << endl;
    showQubit(makeNotOnQubit(qubit1), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testSqrtNotQuantumGate() {
    double probabilitiesOfQubit0[] = {1.0, 0.0};
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfQubit0);

    cout << "Qubit before SQRT(NOT):" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after SQRT(NOT):" << endl;
    showQubit(makeSqrtNotOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testCnotQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 0.0, 0.0, 1.0};
    const int numberOfQubits = 2;
    complex<double> **twoQubits = generateQubit(numberOfQubits, probabilitiesOfTwoQubits);

    cout << "Qubit before CNOT:" << endl;
    showQubit(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS);
    cout << "Qubit after CNOT:" << endl;
    showQubit(makeCnotOnQubit(twoQubits), ROWS_NUMBER_IN_TWO_QUBITS);
}

void testSwapQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 1.0, 0.0, 0.0};
    const int numberOfQubits = 2;
    complex<double> **twoQubits = generateQubit(numberOfQubits, probabilitiesOfTwoQubits);

    cout << "Qubit before SWAP:" << endl;
    showQubit(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS);
    cout << "Qubit after SWAP:" << endl;
    showQubit(makeSwapOnQubit(twoQubits), ROWS_NUMBER_IN_TWO_QUBITS);
}

void testFredkinQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    const int numberOfQubits = 3;
    complex<double> **threeQubits = generateQubit(numberOfQubits, probabilitiesOfThreeQubits);

    cout << "Qubit before FREDKIN:" << endl;
    showQubit(threeQubits, ROWS_NUMBER_IN_THREE_QUBITS);
    cout << "Qubit after FREDKIN:" << endl;
    showQubit(makeFredkinOnQubit(threeQubits), ROWS_NUMBER_IN_THREE_QUBITS);
}

void testToffoliQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    const int numberOfQubits = 3;
    complex<double> **threeQubits = generateQubit(numberOfQubits, probabilitiesOfThreeQubits);

    cout << "Qubit before TOFFOLI:" << endl;
    showQubit(threeQubits, ROWS_NUMBER_IN_THREE_QUBITS);
    cout << "Qubit after TOFFOLI:" << endl;
    showQubit(makeToffoliOnQubit(threeQubits), ROWS_NUMBER_IN_THREE_QUBITS);
}

void testHadamardQuantumGate() {
    double probabilitiesOfTwoQubits[] = {1.0, 0.0};
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfTwoQubits);

    cout << "Qubit before HADAMARD:" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after HADAMARD:" << endl;
    showQubit(makeHadamardOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPhaseShiftQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 1.0};
    double angle = M_PI;
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfTwoQubits);

    cout << "Qubit before PHASE SHIFT:" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after PHASE SHIFT:" << endl;
    showQubit(makePhaseShiftOnQubit(singleQubit, angle), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliXQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI X:" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI X:" << endl;
    showQubit(makePauliXOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliYQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI Y:" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI Y:" << endl;
    showQubit(makePauliYOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliZQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    const int numberOfQubits = 1;
    complex<double> **singleQubit = generateQubit(numberOfQubits, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI Z:" << endl;
    showQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI Z:" << endl;
    showQubit(makePauliZOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testQubitWithNonCorrectProbabilities() {
    double probabilitiesOfThreeQubits[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};
    const int numberOfQubits = 3;
    complex<double> **threeQubits = generateQubit(numberOfQubits, probabilitiesOfThreeQubits);
    showQubit(threeQubits, ROWS_NUMBER_IN_THREE_QUBITS);
}

void testGetMultidimensionalHadamardGate(int indexNumber) {
    complex<double> **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    cout << "Generated Hadamard gate for n = " << indexNumber << " (H" << indexNumber << ")" << endl;
    showMultidimensionalHadamardGate(hadamardGate, indexNumber);
    cout << endl;
}

void testMultidimensionalHadamardGate(int hadamardIndexNumber, int numberOfQubits, double *probabilities) {
    complex<double> **hadamardGate = getMultidimensionalHadamardGate(hadamardIndexNumber);
    complex<double> **qubit = generateQubit(numberOfQubits, probabilities);

    cout << "Qubit before multidimensional Hadamard:" << endl;
    showQubit(qubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after multidimensional Hadamard:" << endl;

    try {
        showQubit(makeMultidimensionalHadamardOnQubit(qubit, numberOfQubits, hadamardGate, hadamardIndexNumber),
                  ROWS_NUMBER_IN_SINGLE_QUBIT);
    }
    catch (const std::string& my_msg){
        cerr << my_msg << endl;
    }
}

void testGetQuantumGates() {
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

    const int numberOfQubits = 2;
    cout << "HADAMARD gate for argument 2:" << endl;
    showQuantumGate(getMultidimensionalHadamardGate(numberOfQubits), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PHASE SHIFT gate for PI angle:" << endl;
    showQuantumGate(getPhaseShiftGate(M_PI), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PHASE SHIFT gate for -PI angle:" << endl;
    showQuantumGate(getPhaseShiftGate(-M_PI), ONE_ARGUMENT_GATE_SIZE);
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

void testComposeOfQuantumGates(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    if (isComposeOfGatesGivesIdentityMatrix(firstGate, secondGate, gateSize)) {
        cout << "Multiplied gates are EQUAL with identity matrix" << endl;
    }
    else {
        cout << "Multiplied gates are NOT equal with identity matrix" << endl;
    }
    cout << endl;
}

void testMakeScalarProductOfQubits(int numberOfQubits, double *probabilities) {
    complex<double> **twoQubits = generateQubit(numberOfQubits, probabilities);
    cout << "Original qubit: " << endl;
    showQubit(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS);

    cout << "Qubit after transposition and conjugation: " << endl;
    complex<double> **transposedAndConjugatedQubit = makeConjugateTranspose(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS,
                                                                            COLUMN_NUMBER_IN_QUBIT);
    showQubitAfterConjugateTranspose(transposedAndConjugatedQubit, ROWS_NUMBER_IN_TWO_QUBITS);

    cout << "Reverted qubit to original state: " << endl;
    //Reverse of qubit - swapped columns and rows parameters is necessary to get original qubit
    complex<double> **originalQubit = makeConjugateTranspose(transposedAndConjugatedQubit, COLUMN_NUMBER_IN_QUBIT,
                                                             ROWS_NUMBER_IN_TWO_QUBITS);
    showQubit(originalQubit, ROWS_NUMBER_IN_TWO_QUBITS);

    cout << "Scalar product of two qubits: " << endl;
    complex<double> **scalarProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, originalQubit,
                                                             ROWS_NUMBER_IN_TWO_QUBITS, COLUMN_NUMBER_IN_QUBIT);
    showScalarProduct(scalarProduct);
}

void testIsMatrixUnitary(complex<double> **firstGate, complex<double> **secondGate, int gateSize) {
    if (isMatrixUnitary(firstGate, secondGate, gateSize)) {
        cout << "Matrix is UNITARY" << endl;
    }
    else {
        cout << "Matrix is NOT unitary" << endl;
    }
}

complex<double> **getNotUnitaryMatrix() {
    complex<double> **matrixWithZeroDeterminant = new complex<double>*[ONE_ARGUMENT_GATE_SIZE];
    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        matrixWithZeroDeterminant[i] = new complex<double>[ONE_ARGUMENT_GATE_SIZE];
    }

    for (int i = 0; i < ONE_ARGUMENT_GATE_SIZE; i++) {
        for (int j = 0; j < ONE_ARGUMENT_GATE_SIZE; j++) {
            matrixWithZeroDeterminant[i][j] = complex<double>(0,0);
        }
    }

    return matrixWithZeroDeterminant;
}

int main() {
    testMatrixOperations();

    testNotQuantumGate();
    testSqrtNotQuantumGate();
    testCnotQuantumGate();
    testSwapQuantumGate();
    testFredkinQuantumGate();
    testToffoliQuantumGate();
    testHadamardQuantumGate();
    testPhaseShiftQuantumGate();
    testPauliXQuantumGate();
    testPauliYQuantumGate();
    testPauliZQuantumGate();

    //Test single qubit (0) * H0
    double probabilitiesOfSingleQubit[] = {1.0, 0.0};
    int hadamardIndexNumber = 0;
    int numberOfQubits = 1;
    testGetMultidimensionalHadamardGate(hadamardIndexNumber);
    testMultidimensionalHadamardGate(hadamardIndexNumber, numberOfQubits, probabilitiesOfSingleQubit);

    //Test single qubit (0) * H1
    hadamardIndexNumber = 1;
    numberOfQubits = 1;
    testGetMultidimensionalHadamardGate(hadamardIndexNumber);
    testMultidimensionalHadamardGate(hadamardIndexNumber, numberOfQubits, probabilitiesOfSingleQubit);

    //Test two qubits (00) * H2
    hadamardIndexNumber = 2;
    numberOfQubits = 2;
    double probabilitiesOfTwoQubits[] = {1.0, 0.0, 0.0, 0.0};
    testGetMultidimensionalHadamardGate(hadamardIndexNumber);
    testMultidimensionalHadamardGate(hadamardIndexNumber, numberOfQubits, probabilitiesOfTwoQubits);

    //Test three qubits (000) * H3
    hadamardIndexNumber = 3;
    numberOfQubits = 3;
    double probabilitiesOfThreeQubits[] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    testGetMultidimensionalHadamardGate(hadamardIndexNumber);
    testMultidimensionalHadamardGate(hadamardIndexNumber, numberOfQubits, probabilitiesOfThreeQubits);

    //Test get quantum gates
    testGetQuantumGates();

    /// Test compose of quantum gates (1 is identity matrix)
    /// gate1 * gate2 = 1.
    // NOT gates
    testComposeOfQuantumGates(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE);

    // Hadamard gates
    testComposeOfQuantumGates(getHadamardGate(), getHadamardGate(), ONE_ARGUMENT_GATE_SIZE);

    // F(alfa) and F(-alfa) - for PI value
    testComposeOfQuantumGates(getPhaseShiftGate(M_PI), getPhaseShiftGate(-M_PI), ONE_ARGUMENT_GATE_SIZE);

    // Test scalar product of qubits
    numberOfQubits = 2;
    testMakeScalarProductOfQubits(numberOfQubits, probabilitiesOfTwoQubits);

    // Test unitary of matrix
    testIsMatrixUnitary(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE);
    testIsMatrixUnitary(getSwapGate(), getSwapGate(), TWO_ARGUMENTS_GATE_SIZE);

    // Test matrix is not unitary
    complex<double> **notUnitaryMatrix = getNotUnitaryMatrix();
    testIsMatrixUnitary(notUnitaryMatrix, notUnitaryMatrix, ONE_ARGUMENT_GATE_SIZE);

    testQubitWithNonCorrectProbabilities();
    return 0;
}