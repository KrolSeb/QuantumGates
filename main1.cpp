#include <iostream>
#include <iomanip>
#include <complex>
#include <ctime>
#include "lib/matrixOperations.cpp"
using namespace std;


void executeCommands() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    int matrixDimension = rand() % 4 + 2;
    setMatrixDimension(matrixDimension);
    cout << "Rows: " << matrixDimension << " " << "Columns: " << matrixDimension << endl;

    int **original01Matrix = allocateMatrix<int>(matrixDimension);
    generateRandom01Matrix(original01Matrix);
    cout << "Original 01 matrix: " << endl;
    printMatrix(original01Matrix, matrixDimension);

    int **transposed01Matrix = transposeMatrix<int>(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;
    /*
     * Transposed matrix, that we revert columns and rows parameters in function call.
     * In this case it doesn't matter - columns and rows have the same value
     * It's important when matrix have different dimensions.
     */
    printMatrix(transposed01Matrix, matrixDimension);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    complex<double> **originalComplexMatrix = allocateMatrix<complex<double>>(matrixDimension);
    generateRandomComplexMatrix(originalComplexMatrix);
    cout << "Original complex matrix: " << endl;
    printComplexMatrix(originalComplexMatrix, matrixDimension);

    complex<double> **transposedComplexMatrix = transposeMatrix<complex<double>>(originalComplexMatrix);
    cout << "Transposed complex matrix: " << endl;
    printComplexMatrix(transposedComplexMatrix, matrixDimension);

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix);
    cout << "Conjugated complex matrix: " << endl;
    printComplexMatrix(conjugatedComplexMatrix, matrixDimension);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "CNOT representation:" << endl;
    printLogicGateRepresentation();

    //TODO: matrix multiplication feature - quantum gate * qubit
}

int main() {
    executeCommands();
    return 0;
}