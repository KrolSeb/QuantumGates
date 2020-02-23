#include <iostream>
#include <iomanip>
#include <complex>
#include <ctime>
#include "lib/matrixOperations.cpp"
#include "lib/headers/quantum.h"

using namespace std;
using namespace quantum;

void runMatrixOperations() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    int dimension = rand() % 4 + 2;
    setMatrixDimension(dimension);
    cout << "Rows: " << dimension << " " << "Columns: " << dimension << endl;

    int **original01Matrix = allocateMatrix<int>(dimension);
    generateRandom01Matrix(original01Matrix);
    cout << "Original 01 matrix: " << endl;
    printMatrix(original01Matrix, dimension);

    int **transposed01Matrix = transposeMatrix<int>(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;
    /*
     * Transposed matrix, that we revert columns and rows parameters in function call.
     * In this case it doesn't matter - columns and rows have the same value
     * It's important when matrix have different dimensions.
     */
    printMatrix(transposed01Matrix, dimension);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    complex<double> **originalComplexMatrix = allocateMatrix<complex<double>>(dimension);
    generateRandomComplexMatrix(originalComplexMatrix);
    cout << "Original complex matrix: " << endl;
    printComplexMatrix(originalComplexMatrix, dimension);

    complex<double> **transposedComplexMatrix = transposeMatrix<complex<double>>(originalComplexMatrix);
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

void runQubitOperations() {
    int numberOfQubits = 2;
    double probability[] = {4.0, 0.0, 3.0, 0.0};

    auto arrSize = std::size(probability);
    struct QuantumComputer qc = QuantumComputer(numberOfQubits, probability, arrSize);

    qc.normalizeRegister();
    qc.viewProbability();
    qc.resetState();
    qc.viewProbability();
    qc.viewQubitsInMathExpression();
}

int main() {
    runQubitOperations();
    runMatrixOperations();
    return 0;
}