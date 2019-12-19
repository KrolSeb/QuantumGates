#include <iostream>
#include <iomanip>
#include <complex>
#include <ctime>

using namespace std;

static int rowsCount;
static int columnsCount;

complex<double> **conjugateComplexMatrix(complex<double> **matrix) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }

    return matrix;
}

void printTransposedComplexMatrix(complex<double> **matrix) {
    int i, j;

    for (i = 0; i < columnsCount; i++) {
        for (j = 0; j < rowsCount; j++) {
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

void printComplexMatrix(complex<double> **matrix) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
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

complex<double> **transposeComplexMatrix(complex<double> **inputMatrix) {
    int i, j;

    //Allocating array for transposed matrix - columns changed with rows
    auto **transposedMatrix = new complex<double> *[columnsCount];
    for (i = 0; i < columnsCount; i++) {
        transposedMatrix[i] = new complex<double>[rowsCount];
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            transposedMatrix[j][i] = inputMatrix[i][j];
        }
    }

    return transposedMatrix;
}

complex<double> **generateRandomComplexMatrix(int rows, int columns) {
    int i, j;

    auto **matrix = new complex<double> *[rows];
    for (i = 0; i < rows; i++) {
        matrix[i] = new complex<double>[columns];
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (rand() % 2 == 0) {
                matrix[i][j] = complex<double>(static_cast<double> (rand() % 20 - 10), static_cast<double> (rand() % 20 - 10));
            }
            else {
                matrix[i][j] = real(complex<double>(static_cast<double> (rand() % 20 - 10), static_cast<double> (rand() % 20 - 10)));
            }
        }
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            if (i == j) {
                matrix[i][j] = matrix[i][j].real(); // diagonal elements must be real
            }
        }
    }

    return matrix;
}

void printTransposedMatrix(int **matrix) {
    int i, j;

    for (i = 0; i < columnsCount; i++) {
        for (j = 0; j < rowsCount; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

void printMatrix(int **matrix) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

int **transposeMatrix(int **matrix) {
    int i, j;

    //Allocating array for transposed matrix - columns changed with rows
    int **transposedMatrix = new int *[columnsCount];
    for (i = 0; i < columnsCount; i++)
        transposedMatrix[i] = new int[rowsCount];

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}

int **generateRandomMatrix(int rows, int columns) {
    int i, j;

    int **matrix = new int *[rows];
    for (i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}


int main() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    rowsCount = columnsCount = rand() % 4 + 2;
    cout << "Rows: " << rowsCount << " " << "Columns: " << columnsCount << endl;

    int **original01Matrix = generateRandomMatrix(rowsCount, columnsCount);
    cout << "Original 01 matrix: " << endl;
    printMatrix(original01Matrix);

    int **transposed01Matrix = transposeMatrix(original01Matrix);
    cout << "Transposed 01 matrix: " << endl;
    printTransposedMatrix(transposed01Matrix);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    complex<double> **originalComplexMatrix = generateRandomComplexMatrix(rowsCount, columnsCount);
    cout << "Original complex matrix: " << endl;
    printComplexMatrix(originalComplexMatrix);

    complex<double> **transposedComplexMatrix = transposeComplexMatrix(originalComplexMatrix);
    cout << "Transposed complex matrix: " << endl;
    printTransposedComplexMatrix(transposedComplexMatrix);

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix);
    cout << "Conjugated complex matrix: " << endl;
    printTransposedComplexMatrix(conjugatedComplexMatrix);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);

    return 0;
}
