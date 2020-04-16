#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

/// @functions
std::complex<double> **getAllocatedMatrix(int firstDimension, int secondDimension);
std::complex<double> **getRandomHermitianMatrix(int dimension);
std::complex<double> **makeConjugateTranspose(std::complex<double> **matrix, const int rows, const int columns);

/// @function - presents matrix elements
void showMatrix(std::complex<double> **matrix, int dimension);

#endif