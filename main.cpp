#include <iostream>
#include <complex>
#include <ctime>

using namespace std;

complex<double> **conjugateComplexMatrix(complex<double> **matrix, int rowsCount, int columnsCount) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }

    return matrix;
}

void printTransposedComplexMatrix(complex<double> **matrix, int rowsCount, int columnsCount) {
    int i, j;

    for (i = 0; i < columnsCount; i++) {
        for (j = 0; j < rowsCount; j++) {
            if (i == j || matrix[i][j].imag() == 0.000000) {
                printf("%5.0f\t ", matrix[i][j].real());
            }
            else {
                printf("%3.0f%+.0fi\t ", matrix[i][j].real(), matrix[i][j].imag());
            }
        }
        printf("%s", "\n");
    }
}

void printComplexMatrix(complex<double> **matrix, int rowsCount, int columnsCount) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            if (i == j || matrix[i][j].imag() == 0.000000) {
                printf("%5.0f\t ", matrix[i][j].real());
            }
            else {
                printf("%3.0f%+.0fi\t ", matrix[i][j].real(), matrix[i][j].imag());
            }
        }
        printf("%s", "\n");
    }
}

complex<double> **transposeComplexMatrix(complex<double> **inputMatrix, int rowsCount, int columnsCount) {
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

complex<double> **generateRandomComplexMatrix(int rowsCount, int columnsCount) {
    int i, j;

    auto **matrix = new complex<double> *[rowsCount];
    for (i = 0; i < rowsCount; i++) {
        matrix[i] = new complex<double>[columnsCount];
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
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

void printTransposedMatrix(int **matrix, int rowsCount, int columnsCount) {
    int i, j;

    for (i = 0; i < columnsCount; i++) {
        for (j = 0; j < rowsCount; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("%s", "\n");
    }
}

void printMatrix(int **matrix, int rowsCount, int columnsCount) {
    int i, j;

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("%s", "\n");
    }
}

int **transposeMatrix(int **matrix, int rowsCount, int columnsCount) {
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

int **generateRandomMatrix(int rowsCount, int columnsCount) {
    int i, j;

    int **matrix = new int *[rowsCount];
    for (i = 0; i < rowsCount; i++)
        matrix[i] = new int[columnsCount];

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    return matrix;
}


int main() {
    //TODO: another implementation for generate random values
    srand(static_cast<unsigned int>(time(nullptr)));

    int rowsCount;
    int columnsCount;
    rowsCount = columnsCount = rand() % 4 + 2;

    printf("%s", "Rows: ");
    printf("%d", rowsCount);
    printf("%s", " ");
    printf("%s", "Columns: ");
    printf("%d", columnsCount);
    printf("%s", "\n");

    int **original01Matrix = generateRandomMatrix(rowsCount, columnsCount);
    printf("%s", "Original 01 matrix: ");
    printf("%s", "\n");
    printMatrix(original01Matrix, rowsCount, columnsCount);

    printf("%s", "\n");

    int **transposed01Matrix = transposeMatrix(original01Matrix, rowsCount, columnsCount);
    printf("%s", "Transposed 01 matrix: ");
    printf("%s", "\n");
    printTransposedMatrix(transposed01Matrix, rowsCount, columnsCount);

    delete (original01Matrix);
    delete (transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("%s", "\n");
    complex<double> **originalComplexMatrix = generateRandomComplexMatrix(rowsCount, columnsCount);

    printf("%s", "Original complex matrix: ");
    printf("%s", "\n");
    printComplexMatrix(originalComplexMatrix, rowsCount, columnsCount);

    printf("%s", "\n");
    complex<double> **transposedComplexMatrix = transposeComplexMatrix(originalComplexMatrix, rowsCount, columnsCount);

    printf("%s", "Transposed complex matrix: ");
    printf("%s", "\n");
    printTransposedComplexMatrix(transposedComplexMatrix, rowsCount, columnsCount);

    printf("%s", "\n");

    complex<double> **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix, rowsCount,
                                                                       columnsCount);
    printf("%s", "Conjugated complex matrix: ");
    printf("%s", "\n");
    printTransposedComplexMatrix(conjugatedComplexMatrix, rowsCount, columnsCount);

    delete (originalComplexMatrix);
    delete (conjugatedComplexMatrix);

    return 0;
}
