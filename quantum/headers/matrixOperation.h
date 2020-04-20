#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

using namespace std;

/// Used to generate and get matrix for declared dimensions
/// \param firstDimension int
/// \param secondDimension int
/// \return allocated matrix
complex<double> **getAllocatedMatrix(int firstDimension, int secondDimension);

/// Used to get random hermitian matrix.\n
/// Hermitian matrix - https://pl.wikipedia.org/wiki/Macierz_hermitowska
/// \param dimension int
/// \return allocated matrix
complex<double> **getRandomHermitianMatrix(int dimension);

/// Used to make conjugate transpose of matrix.\n
/// Conjugate transpose - https://en.wikipedia.org/wiki/Conjugate_transpose#Example
/// \param matrix complex<double>
/// \param rows int
/// \param columns int
/// \return conjugate transposed matrix
complex<double> **makeConjugateTranspose(complex<double> **matrix, int rows, int columns);

/// Used to show all elements of matrix
/// \param matrix complex<double>
/// \param dimension int
void showMatrix(complex<double> **matrix, int dimension);

#endif