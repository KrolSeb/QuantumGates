#include <iostream>
#include <complex>
#include <ctime>
#include "lib/headers/quantumComputer.h"
#include "lib/headers/numericMatrix.h"
#include "lib/headers/complexMatrix.h"
#include "lib/headers/quantumGate.h"
#include "lib/headers/temporaryQubit.h"

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
    printComplexMatrix(originalComplexMatrix, dimension);

    complex<double> **transposedComplexMatrix = transposeComplexMatrix(originalComplexMatrix);
    cout << "Transposed complex matrix: " << endl;
    printComplexMatrix(transposedComplexMatrix, dimension);

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix);
    cout << "Conjugated complex matrix: " << endl;
    printComplexMatrix(conjugatedComplexMatrix, dimension);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "CNOT representation:" << endl;
    printLogicGateRepresentation();

    //TODO: matrix multiplication feature - quantum gate * qubit
}

/*
void generateSingleQubit() {
    int numberOfQubits = 1;
    double probability[] = {1.0, 0.0};

    auto arrSize = std::size(probability);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probability, arrSize);

    qc.viewProbability();
    qc.viewQubitsInMathExpression();
}

void generateTwoQubits() {
    int numberOfQubits = 2;
    double probability[] = {0.00, 0.50, 0.50, 0.00};

    auto arrSize = std::size(probability);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probability, arrSize);

    qc.viewProbability();
    qc.viewQubitsInMathExpression();
}
*/

void runQubitOperations() {
    getQubit0();
    getQubit1();
}

int main() {
    runQubitOperations();
    runMatrixOperations();
    return 0;
}