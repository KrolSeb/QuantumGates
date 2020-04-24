#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <complex>

using namespace std;
/// Used as alias for declaration of two dimensional vector
typedef vector<vector<complex<double>>> vector2d;

/// Used to get defined vector for declared dimension
/// \param dimension int
/// \return defined matrix as two dimensional vector
vector2d getPreparedVectorForHermitianMatrix(int dimension);

/// Used to get random hermitian matrix.\n
/// Hermitian matrix - https://pl.wikipedia.org/wiki/Macierz_hermitowska
/// \param dimension int
/// \return hermitian matrix as two dimensional vector
vector2d getRandomHermitianMatrix(int dimension);

/// Used to make conjugate transpose of matrix.\n
/// Conjugate transpose - https://en.wikipedia.org/wiki/Conjugate_transpose#Example
/// \param matrix vector2d
/// \return conjugate transposed matrix as two dimensional vector
vector2d makeConjugateTranspose(vector2d matrix);

/// Used to show all elements of matrix
/// \param matrix vector2d
/// \param dimension int
void showMatrix(vector2d matrix);

#endif