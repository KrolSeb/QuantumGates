#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

void printLogicGateRepresentation();
void printMatrix(int **matrix, int dimension);
void printComplexMatrix(std::complex<double> **matrix, int dimension);

int **generateRandom01Matrix(int **matrix);
std::complex<double> **generateRandomComplexMatrix(std::complex<double> **matrix);
std::complex<double> **conjugateComplexMatrix(std::complex<double> **matrix);

#endif //UNTITLED_LIBRARY_H
