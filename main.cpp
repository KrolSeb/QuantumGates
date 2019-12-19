#include <iostream>
#include <iomanip>
#include <complex>
#include <ctime>

using namespace std;
int matrixDimension;

template <typename T>
T **allocateMatrix(int dimension) {
    T **matrix = new T*[dimension];
    for (int i = 0; i < dimension; i++) {
        matrix[i] = new T[dimension];
    }

    return matrix;
}

int **generateRandom01Matrix(int **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}

complex<double> **generateRandomComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            if (rand() % 2 == 0) {
                matrix[i][j] = complex<double>(static_cast<double> (rand() % 20 - 10), static_cast<double> (rand() % 20 - 10));
            }
            else {
                matrix[i][j] = real(complex<double>(static_cast<double> (rand() % 20 - 10), static_cast<double> (rand() % 20 - 10)));
            }

            if (i == j) {
                matrix[i][j] = real(matrix[i][j]);
            }
        }
    }

    return matrix;
}

template <typename T>
T **transposeMatrix(T **matrix) {
    //Allocating array for transposed matrix - columns changed with rows
    T **transposedMatrix = allocateMatrix<T>(matrixDimension);

    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

complex<double> **conjugateComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < matrixDimension; i++) {
        for (int j = 0; j < matrixDimension; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printComplexMatrix(complex<double> **matrix, int dimension) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (i == j || matrix[i][j].imag() == 0.000000) {
                cout << setw(8) << real(matrix[i][j]);
            }
            else {
                if (imag(matrix[i][j]) > 0) {
                    cout << setw(5) << real(matrix[i][j]) << "+" << imag(matrix[i][j]) << "i";
                }
                else {
                    cout << setw(5) << real(matrix[i][j]) << imag(matrix[i][j]) << "i";
                }
            }
        }
        cout << endl;
    }

    cout << endl;
}


int main() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    matrixDimension = rand() % 4 + 2;
    cout << "Rows: " << matrixDimension << " " << "Columns: " << matrixDimension << endl;

    int **original01Matrix = allocateMatrix<int>(matrixDimension);
    generateRandom01Matrix(original01Matrix);
    cout << "Original 01 matrix: " << endl;
    printMatrix(original01Matrix, matrixDimension);

    int **transposed01Matrix = transposeMatrix<int>(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;

    /* Transposed matrix, that we revert columns and rows parameters in function call.
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

    return 0;
}
