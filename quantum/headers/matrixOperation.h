#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

/// Used to generate and get matrix for declared dimensions
/// \param first matrix dimension
/// \param second matrix dimension
/// \return allocated matrix
complex<double> **getAllocatedMatrix(int firstDimension, int secondDimension);

/// Used to get random hermitian matrix.\n
/// Hermitian matrix - https://pl.wikipedia.org/wiki/Macierz_hermitowska
/// \param dimension of matrix
/// \return allocated matrix
complex<double> **getRandomHermitianMatrix(int dimension);

/// Used to make conjugate transpose of matrix.\n
/// Conjugate transpose - https://en.wikipedia.org/wiki/Conjugate_transpose#Example
/// \param matrix
/// \param rows of matrix
/// \param columns of matrix
/// \return conjugate transposed matrix
complex<double> **makeConjugateTranspose(complex<double> **matrix, const int rows, const int columns);

/// Used to show all elements of matrix
/// \param matrix
/// \param dimension of matrix
void showMatrix(complex<double> **matrix, int dimension);

/// Used to show single formatted element of matrix
/// \param element of matrix
void showSingleMatrixElement(complex<double> element);

#endif