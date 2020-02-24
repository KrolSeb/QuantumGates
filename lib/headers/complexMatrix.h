#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>
using namespace std;

void setComplexMatrixDimension(int dimension);
complex<double> **allocateComplexMatrix(int dimension);
complex<double> **generateRandomComplexMatrix(complex<double> **matrix);
complex<double> **transposeComplexMatrix(complex<double> **matrix);
complex<double> **conjugateComplexMatrix(complex<double> **matrix);
void printComplexMatrix(complex<double> **matrix, int dimension);

#endif //UNTITLED_LIBRARY_H
