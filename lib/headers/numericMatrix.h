#ifndef QUANTUMGATES_NUMERICMATRIX_H
#define QUANTUMGATES_NUMERICMATRIX_H
using namespace std;

void setNumericMatrixDimension(int dimension);
int **allocateNumericMatrix(int dimension);
int **generateRandomNumericMatrix(int **matrix);
int **transposeNumericMatrix(int **matrix);
void printNumericMatrix(int **matrix, int dimension);

#endif //QUANTUMGATES_NUMERICMATRIX_H
