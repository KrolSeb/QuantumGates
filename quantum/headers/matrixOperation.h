#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

using namespace std;
typedef vector<vector<complex<double>>> vector2d;

/// Used to generate and get matrix for declared dimension
/// \param dimension int
/// \return allocated matrix
vector2d getPreparedContainerForHermitianMatrix(int dimension);

/// Used to get random hermitian matrix.\n
/// Hermitian matrix - https://pl.wikipedia.org/wiki/Macierz_hermitowska
/// \param dimension int
/// \return allocated matrix
vector2d getRandomHermitianMatrix(int dimension);

/// Used to make conjugate transpose of matrix.\n
/// Conjugate transpose - https://en.wikipedia.org/wiki/Conjugate_transpose#Example
/// \param matrix complex<double>
/// \return conjugate transposed matrix
vector2d makeConjugateTranspose(vector2d matrix);

/// Used to show all elements of matrix
/// \param matrix complex<double>
/// \param dimension int
void showMatrix(vector2d matrix);

#endif