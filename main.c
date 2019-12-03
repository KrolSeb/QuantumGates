#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <complex.h>
#include <math.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wimplicit-function-declaration"

float complex **conjugateComplexMatrix(float complex **matrix, int rowsCount, int columnsCount) {
    int i, j;
    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            matrix[i][j] = conj(matrix[i][j]);
        }
    }

    return matrix;
}

void printTransposedComplexMatrix(float complex **matrix, int rowsCount, int columnsCount) {
    int i, j;
    for (i = 0; i < columnsCount; i++) {
        for (j = 0; j < rowsCount; j++) {
            if (i == j) {
                printf("%5.0f\t ", creal(matrix[i][j]));
            }
            else if (cimag(matrix[i][j]) == 0.000000) {
                printf("%5.0f\t ", creal(matrix[i][j]));
            }
            else {
                printf("%3.0f%+.0fi\t ", creal(matrix[i][j]), cimag(matrix[i][j]));
            }
        }
        printf("%s", "\n");
    }
}

void printComplexMatrix(float complex **matrix, int rowsCount, int columnsCount) {
    int i, j;
    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            if (i == j) {
                printf("%5.0f\t ", creal(matrix[i][j]));
            }
            else if (cimag(matrix[i][j]) == 0.000000) {
                printf("%5.0f\t ", creal(matrix[i][j]));
            }
            else {
                printf("%3.0f%+.0fi\t ", creal(matrix[i][j]), cimag(matrix[i][j]));
            }
        }
        printf("%s", "\n");
    }
}

float complex **transposeComplexMatrix(float complex **inputMatrix, int rowsCount, int columnsCount) {
    int i, j;

    //Allocating array for transposed matrix - columns changed with rows
    float complex **transposedMatrix = malloc(columnsCount * sizeof(float complex *));
    for (i = 0; i < columnsCount; i++) {
        transposedMatrix[i] = malloc(rowsCount * sizeof(float complex));
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            transposedMatrix[j][i] = inputMatrix[i][j];
        }
    }

    return transposedMatrix;
}

float complex **generateRandomComplexMatrix(int rowsCount, int columnsCount) {
    int i, j;

    float complex **matrix = malloc(rowsCount * sizeof(float complex *));
    for (i = 0; i < rowsCount; i++) {
        matrix[i] = malloc(columnsCount * sizeof(float complex));
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            if (random() % 2 == 0){
                matrix[i][j] = CMPLXF(random() % 20 - 10, (random() % 20 - 10));
            }
            else {
                matrix[i][j] = creal(CMPLXF(random() % 20 - 10, 0));
            }
        }
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            if (i == j) {
                matrix[i][j] = creal(matrix[i][j]); // diagonal elements must be real
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

int **transposeMatrix(int **inputMatrix, int rowsCount, int columnsCount) {
    int i, j;

    //Allocating array for transposed matrix - columns changed with rows
    int **transposedMatrix = malloc(columnsCount * sizeof(int *));
    for (i = 0; i < columnsCount; i++) {
        transposedMatrix[i] = malloc(rowsCount * sizeof(int));
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            transposedMatrix[j][i] = inputMatrix[i][j];
        }
    }

    return transposedMatrix;
}

int **generateRandomMatrix(int rowsCount, int columnsCount) {
    int i, j;

    int **matrix = malloc(rowsCount * sizeof(int *));
    for (i = 0; i < rowsCount; i++) {
        matrix[i] = malloc(columnsCount * sizeof(int));
    }

    for (i = 0; i < rowsCount; i++) {
        for (j = 0; j < columnsCount; j++) {
            matrix[i][j] = random() % 2;
        }
    }

    return matrix;
}

int main() {
    srand(time(NULL));
    int rowsCount;
    int columnsCount;
    rowsCount = columnsCount = random() % 4 + 2;

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

    free(original01Matrix);
    free(transposed01Matrix);

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("%s", "\n");
    float complex **originalComplexMatrix = generateRandomComplexMatrix(rowsCount, columnsCount);
    printf("%s", "Original complex matrix: ");
    printf("%s", "\n");
    printComplexMatrix(originalComplexMatrix, rowsCount, columnsCount);

    printf("%s", "\n");

    float complex **transposedComplexMatrix = transposeComplexMatrix(originalComplexMatrix, rowsCount, columnsCount);
    printf("%s", "Transposed complex matrix: ");
    printf("%s", "\n");
    printTransposedComplexMatrix(transposedComplexMatrix, rowsCount, columnsCount);

    printf("%s", "\n");

    float complex **conjugatedComplexMatrix = conjugateComplexMatrix(transposedComplexMatrix, rowsCount, columnsCount);
    printf("%s", "Conjugated complex matrix: ");
    printf("%s", "\n");
    printTransposedComplexMatrix(conjugatedComplexMatrix, rowsCount, columnsCount);

    free(originalComplexMatrix);
    free(conjugatedComplexMatrix);

    return 0;
}

#pragma clang diagnostic pop