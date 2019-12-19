#include <iostream>
#include <iomanip>
#include <complex>
#include <ctime>

using namespace std;
int rowsCount;
int columnsCount;

template <typename T>
T **allocateMatrix(int rows, int columns) {
    T **matrix = new T*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new T[columns];
    }

    return matrix;
}

int **generateRandom01Matrix(int **matrix) {
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}

complex<double> **generateRandomComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
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
    T **transposedMatrix = allocateMatrix<T>(rowsCount, columnsCount);

    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

complex<double> **conjugateComplexMatrix(complex<double> **matrix) {
    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < columnsCount; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void printComplexMatrix(complex<double> **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
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

    rowsCount = columnsCount = rand() % 4 + 2;
    cout << "Rows: " << rowsCount << " " << "Columns: " << columnsCount << endl;

    int **original01Matrix = allocateMatrix<int>(rowsCount, columnsCount);
    generateRandom01Matrix(original01Matrix);
    cout << "Original 01 matrix: " << endl;
    printMatrix(original01Matrix, rowsCount, columnsCount);

    int **transposed01Matrix = transposeMatrix<int>(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;

    /* Transposed matrix, that we revert columns and rows parameters in function call.
     * In this case it doesn't matter - columns and rows have the same value
     * It's important when matrix have different dimensions.
     */
    printMatrix(transposed01Matrix, columnsCount, rowsCount);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    complex<double> **originalComplexMatrix = allocateMatrix<complex<double>>(rowsCount, columnsCount);
    generateRandomComplexMatrix(originalComplexMatrix);
    cout << "Original complex matrix: " << endl;
    printComplexMatrix(originalComplexMatrix, rowsCount, columnsCount);

    complex<double> **transposedComplexMatrix = transposeMatrix<complex<double>>(originalComplexMatrix);
    cout << "Transposed complex matrix: " << endl;
    printComplexMatrix(transposedComplexMatrix, columnsCount, rowsCount);

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix);
    cout << "Conjugated complex matrix: " << endl;
    printComplexMatrix(conjugatedComplexMatrix, columnsCount, rowsCount);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);

    return 0;
}
