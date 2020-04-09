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

void runMatrixOperations() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    int dimension = rand() % 4 + 2;
    setComplexMatrixDimension(dimension);
    cout << "Rows: " << dimension << " " << "Columns: " << dimension << endl;

    complex<double> **originalComplexMatrix = allocateComplexMatrix(dimension);
    generateRandomComplexMatrix(originalComplexMatrix);
    cout << "Original complex matrix: " << endl;
    printHermitianComplexMatrix(originalComplexMatrix, dimension);

    complex<double> **transposedComplexMatrix = transposeComplexMatrix(originalComplexMatrix);
    cout << "Transposed complex matrix: " << endl;
    printHermitianComplexMatrix(transposedComplexMatrix, dimension);

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix);
    cout << "Conjugated complex matrix: " << endl;
    printHermitianComplexMatrix(conjugatedComplexMatrix, dimension);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);
}

double **generateAndNormalizeQubit(int numberOfQubits, double probabilities[]) {
    int arrSize = pow(2, numberOfQubits);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probabilities, arrSize);

    qc.viewProbability();
    qc.normalizeRegister();
    qc.viewProbability();
    qc.viewQubitsInMathExpression();

    return getBaseVectorAsTwoDimensionalArray(qc.getBaseVector());
}

double **generateQubit(int numberOfQubits, double probabilities[]) {
    int arrSize = pow(2, numberOfQubits);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probabilities, arrSize);

    qc.viewProbability();
    qc.viewQubitsInMathExpression();

    return getBaseVectorAsTwoDimensionalArray(qc.getBaseVector());
}

void testNotQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double probabilitiesOfQubit1[] = {0, 1};
    const int numberOfQubits = 1;

    double **qubit0 = generateQubit(numberOfQubits, probabilitiesOfQubit0);
    cout << "Qubit 0 (1 0) before negation:" << endl;
    printQubit(qubit0, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after negation:" << endl;
    printQubit(makeNotOnQubit(qubit0), ROWS_NUMBER_IN_SINGLE_QUBIT);

    double **qubit1 = generateQubit(numberOfQubits, probabilitiesOfQubit1);
    cout << "Qubit 1 (0 1) before negation:" << endl;
    printQubit(qubit1, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 1 (0 1) after negation:" << endl;
    printQubit(makeNotOnQubit(qubit1), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testSqrtNotQuantumGate() {
    double probabilitiesOfQubit0[] = {1.0, 0.0};
    double **singleQubit = generateQubit(1, probabilitiesOfQubit0);

    cout << "Qubit before SQRT(NOT):" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after SQRT(NOT):" << endl;
    printComplexQubit(makeSqrtNotOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testCnotQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 0.0, 0.0, 1.0};
    double **twoQubits = generateQubit(2, probabilitiesOfTwoQubits);

    cout << "Qubit before CNOT:" << endl;
    printQubit(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS);
    cout << "Qubit after CNOT:" << endl;
    printQubit(makeCnotOnQubit(twoQubits), ROWS_NUMBER_IN_TWO_QUBITS);
}

void testSwapQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 1.0, 0.0, 0.0};
    double **twoQubits = generateQubit(2, probabilitiesOfTwoQubits);

    cout << "Qubit before SWAP:" << endl;
    printQubit(twoQubits, ROWS_NUMBER_IN_TWO_QUBITS);
    cout << "Qubit after SWAP:" << endl;
    printQubit(makeSwapOnQubit(twoQubits), ROWS_NUMBER_IN_TWO_QUBITS);
}

void testFredkinQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    double **threeQubits = generateQubit(3, probabilitiesOfThreeQubits);

    cout << "Qubit before FREDKIN:" << endl;
    printQubit(threeQubits, ROWS_NUMBER_IN_THREE_QUBITS);
    cout << "Qubit after FREDKIN:" << endl;
    printQubit(makeFredkinOnQubit(threeQubits), ROWS_NUMBER_IN_THREE_QUBITS);
}

void testToffoliQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    double **threeQubits = generateQubit(3, probabilitiesOfThreeQubits);

    cout << "Qubit before TOFFOLI:" << endl;
    printQubit(threeQubits, ROWS_NUMBER_IN_THREE_QUBITS);
    cout << "Qubit after TOFFOLI:" << endl;
    printQubit(makeToffoliOnQubit(threeQubits), ROWS_NUMBER_IN_THREE_QUBITS);
}

void testHadamardQuantumGate() {
    double probabilitiesOfTwoQubits[] = {1.0, 0.0};
    double **singleQubit = generateQubit(1, probabilitiesOfTwoQubits);

    cout << "Qubit before HADAMARD:" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after HADAMARD:" << endl;
    printQubit(makeHadamardOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPhaseShiftQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 1.0};
    double **singleQubit = generateQubit(1, probabilitiesOfTwoQubits);
    double angle = M_PI;

    cout << "Qubit before PHASE SHIFT:" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after PHASE SHIFT:" << endl;
    printQubit(makePhaseShiftOnQubit(angle, singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliXQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double **singleQubit = generateQubit(1, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI X:" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI X:" << endl;
    printQubit(makePauliXOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliYQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double **singleQubit = generateQubit(1, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI Y:" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI Y:" << endl;
    printComplexQubit(makePauliYOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testPauliZQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double **singleQubit = generateQubit(1, probabilitiesOfQubit0);

    cout << "Qubit 0 (1 0) before PAULI Z:" << endl;
    printQubit(singleQubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit 0 (1 0) after PAULI Z:" << endl;
    printQubit(makePauliZOnQubit(singleQubit), ROWS_NUMBER_IN_SINGLE_QUBIT);
}

void testQubitWithNonCorrectProbabilities() {
    double probabilitiesOfThreeQubits[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};
    double **threeQubits = generateAndNormalizeQubit(3, probabilitiesOfThreeQubits);
}

void testGetMultidimensionalHadamardGate(int indexNumber) {
    double **hadamardGate = getMultidimensionalHadamardGate(indexNumber);
    cout << "Generated Hadamard gate for n = " << indexNumber << " (H" << indexNumber << ")" << endl;
    printMultidimensionalHadamardGate(hadamardGate, indexNumber);
}

void testMultidimensionalHadamardGate(int hadamardIndexNumber, int amountOfQubits, double *probabilities) {
    double **hadamardGate = getMultidimensionalHadamardGate(hadamardIndexNumber);
    double **qubit = generateQubit(amountOfQubits, probabilities);

    cout << "Qubit before multidimensional Hadamard:" << endl;
    printQubit(qubit, ROWS_NUMBER_IN_SINGLE_QUBIT);
    cout << "Qubit after multidimensional Hadamard:" << endl;

    try {
        printQubit(makeMultidimensionalHadamardOnQubit(hadamardGate, hadamardIndexNumber, qubit, amountOfQubits), ROWS_NUMBER_IN_SINGLE_QUBIT);
    }
    catch (const std::string& my_msg){
        cerr << my_msg << endl;
    }
}

void testGetQuantumGates() {
    cout << "NOT gate:" << endl;
    printQuantumGate(getNotGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "SQRT(NOT) gate:" << endl;
    printComplexQuantumGate(getSqrtNotGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "CNOT gate:" << endl;
    printQuantumGate(getCnotGate(), TWO_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "SWAP gate:" << endl;
    printQuantumGate(getSwapGate(), TWO_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "FREDKIN gate:" << endl;
    printQuantumGate(getFredkinGate(), THREE_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "TOFFOLI gate:" << endl;
    printQuantumGate(getToffoliGate(), THREE_ARGUMENTS_GATE_SIZE);
    cout << endl;

    cout << "HADAMARD gate:" << endl;
    printQuantumGate(getHadamardGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "HADAMARD gate for argument 2:" << endl;
    printQuantumGate(getMultidimensionalHadamardGate(2), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PHASE SHIFT gate for PI angle:" << endl;
    printQuantumGate(getPhaseShiftGate(M_PI), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PHASE SHIFT gate for -PI angle:" << endl;
    printQuantumGate(getPhaseShiftGate(-M_PI), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI X gate:" << endl;
    printQuantumGate(getPauliXGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI Y gate:" << endl;
    printComplexQuantumGate(getPauliYGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;

    cout << "PAULI Z gate:" << endl;
    printQuantumGate(getPauliZGate(), ONE_ARGUMENT_GATE_SIZE);
    cout << endl;
}

void testAssemblyOfQuantumGates(double **firstGate, double **secondGate, int gateSize) {
    if (isAssemblyOfGatesGiveIdentityMatrix(firstGate, secondGate, gateSize)) {
        cout << "Multiplied gates are EQUAL with identity matrix" << endl;
    }
    else {
        cout << "Multiplied gates are NOT equal with identity matrix" << endl;
    }
}

int main() {
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
    int amountOfQubits = 1;
    testMultidimensionalHadamardGate(hadamardIndexNumber, amountOfQubits, probabilitiesOfSingleQubit);

    //Test single qubit (0) * H1
    hadamardIndexNumber = 1;
    amountOfQubits = 1;
    testMultidimensionalHadamardGate(hadamardIndexNumber, amountOfQubits, probabilitiesOfSingleQubit);

    //Test two qubits (00) * H2
    hadamardIndexNumber = 2;
    amountOfQubits = 2;
    double probabilitiesOfTwoQubits[] = {1.0, 0.0, 0.0, 0.0};
    testMultidimensionalHadamardGate(hadamardIndexNumber, amountOfQubits, probabilitiesOfTwoQubits);

    //Test three qubits (000) * H3
    hadamardIndexNumber = 3;
    amountOfQubits = 3;
    double probabilitiesOfThreeQubits[] = {1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    testMultidimensionalHadamardGate(hadamardIndexNumber, amountOfQubits, probabilitiesOfThreeQubits);

    //Test get quantum gates
    testGetQuantumGates();

    /// Test assembly of gates (1 is identity matrix)
    /// gate1 * gate2 = 1.
    // NOT gates
    testAssemblyOfQuantumGates(getNotGate(), getNotGate(), ONE_ARGUMENT_GATE_SIZE);

    // Hadamard gates
    testAssemblyOfQuantumGates(getHadamardGate(), getHadamardGate(), ONE_ARGUMENT_GATE_SIZE);

    // F(alfa) and F(-alfa) - for PI value
    testAssemblyOfQuantumGates(getPhaseShiftGate(M_PI), getPhaseShiftGate(-M_PI), ONE_ARGUMENT_GATE_SIZE);

    //runMatrixOperations();
    return 0;
}