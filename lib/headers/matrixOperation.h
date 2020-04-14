#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

std::complex<double> **getRandomHermitianMatrix(int dimension);
std::complex<double> **makeConjugateTranspose(std::complex<double> **matrix, const int rows, const int columns);

void printMatrix(std::complex<double> **matrix, int dimension);

#endif //UNTITLED_LIBRARY_H