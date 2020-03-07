#include <iostream>
#include <complex>
#include <ctime>
#include "lib/headers/numericMatrix.h"
#include "lib/headers/complexMatrix.h"
#include "lib/headers/quantumComputer.h"
#include "lib/headers/qubitOperation.h"
#include "lib/headers/quantumGate.h"

using namespace std;
using namespace quantum;

void runMatrixOperations() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    int dimension = rand() % 4 + 2;
    setNumericMatrixDimension(dimension);
    setComplexMatrixDimension(dimension);
    cout << "Rows: " << dimension << " " << "Columns: " << dimension << endl;

    int **original01Matrix = allocateNumericMatrix(dimension);
    generateRandomNumericMatrix(original01Matrix);
    cout << "Original 01 matrix: " << endl;
    printNumericMatrix(original01Matrix, dimension);

    int **transposed01Matrix = transposeNumericMatrix(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;
    /*
     * Transposed matrix, that we revert columns and rows parameters in function call.
     * In this case it doesn't matter - columns and rows have the same value
     * It's important when matrix have different dimensions.
     */
    printNumericMatrix(transposed01Matrix, dimension);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

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

double *generateAndNormalizeQubit(int numberOfQubits, double probabilities[]) {
    int arrSize = pow(2, numberOfQubits);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probabilities, arrSize);

    qc.viewProbability();
    qc.normalizeRegister();
    qc.viewProbability();
    qc.viewQubitsInMathExpression();

    return getBaseVectorAsArray(qc.getBaseVector());
}

double *generateQubit(int numberOfQubits, double probabilities[]) {
    int arrSize = pow(2, numberOfQubits);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probabilities, arrSize);

    qc.viewProbability();
    qc.viewQubitsInMathExpression();

    return getBaseVectorAsArray(qc.getBaseVector());
}

void testNotQuantumGate() {
    double probabilitiesOfQubit0[] = {1, 0};
    double probabilitiesOfQubit1[] = {0, 1};

    double *qubit0 = generateQubit(1, probabilitiesOfQubit0);
    cout << "Qubit 0 (1 0) before negation:" << endl;
    printSingleQubit(qubit0);
    cout << "Qubit 0 (1 0) after negation:" << endl;
    printSingleQubit(makeNotOnQubit(qubit0, QUBIT_COLUMNS));

    double *qubit1 = generateQubit(1, probabilitiesOfQubit1);
    cout << "Qubit 1 (0 1) before negation:" << endl;
    printSingleQubit(qubit1);
    cout << "Qubit 1 (0 1) after negation:" << endl;
    printSingleQubit(makeNotOnQubit(qubit1, QUBIT_COLUMNS));
}

void testSqrtNotQuantumGate() {
    double probabilitiesOfTwoQubits[] = {1.0, 0.0};
    double *singleQubit = generateQubit(1, probabilitiesOfTwoQubits);

    cout << "Qubit before SQRT(NOT):" << endl;
    printSingleQubit(singleQubit);
    cout << "Qubit after SQRT(NOT):" << endl;
    printSingleComplexQubit(makeSqrtNotOnQubit(singleQubit, QUBIT_COLUMNS));
}

void testCnotQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 0.0, 0.0, 1.0};
    double *twoQubits = generateQubit(2, probabilitiesOfTwoQubits);

    cout << "Qubit before CNOT:" << endl;
    printTwoQubits(twoQubits);
    cout << "Qubit after CNOT:" << endl;
    printTwoQubits(makeCnotOnQubit(twoQubits, QUBIT_COLUMNS));
}

void testSwapQuantumGate() {
    double probabilitiesOfTwoQubits[] = {0.0, 1.0, 0.0, 0.0};
    double *twoQubits = generateQubit(2, probabilitiesOfTwoQubits);

    cout << "Qubit before SWAP:" << endl;
    printTwoQubits(twoQubits);
    cout << "Qubit after SWAP:" << endl;
    printTwoQubits(makeSwapOnQubit(twoQubits, QUBIT_COLUMNS));
}

void testFredkinQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    double *threeQubits = generateQubit(3, probabilitiesOfThreeQubits);

    cout << "Qubit before FREDKIN:" << endl;
    printThreeQubits(threeQubits);
    cout << "Qubit after FREDKIN:" << endl;
    printThreeQubits(makeFredkinOnQubit(threeQubits, QUBIT_COLUMNS));
}

void testToffoliQuantumGate() {
    double probabilitiesOfThreeQubits[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
    double *threeQubits = generateQubit(3, probabilitiesOfThreeQubits);

    cout << "Qubit before TOFFOLI:" << endl;
    printThreeQubits(threeQubits);
    cout << "Qubit after TOFFOLI:" << endl;
    printThreeQubits(makeToffoliOnQubit(threeQubits, QUBIT_COLUMNS));
}

void testQubitWithNonCorrectProbabilities() {
    double probabilitiesOfThreeQubits[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};
    double *threeQubits = generateAndNormalizeQubit(3, probabilitiesOfThreeQubits);
}

int main() {
    testNotQuantumGate();
    testSqrtNotQuantumGate();
    testCnotQuantumGate();
    testSwapQuantumGate();
    testFredkinQuantumGate();
    testToffoliQuantumGate();

    //runMatrixOperations();
    return 0;
}