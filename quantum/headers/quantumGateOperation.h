#ifndef QUANTUMGATES_QUANTUMGATEOPERATION_H
#define QUANTUMGATES_QUANTUMGATEOPERATION_H
#include <complex>
#include <vector>

using namespace std;
/// Used as alias for declaration of two dimensional vector
typedef vector<vector<complex<double>>> vector2d;

/// Used to compose two quantum gates.\n
/// Compose - multiplication of values from two matrices, at the same indexes
/// \param firstGate vector2d
/// \param secondGate vector2d
/// \return composed quantum gates
vector2d composeQuantumGates(vector2d firstGate, vector2d secondGate);

/// Used to get identity matrix for defined size.\n
/// Identity matrix - https://en.wikipedia.org/wiki/Identity_matrix
/// \param gateSize int
/// \return identity matrix
vector2d getIdentityMatrix(int gateSize);

/// Used to check\n
/// if identity matrix are the same as composed gates.
/// \param identityMatrix vector2d
/// \param composedGates vector2d
/// \return true or false
bool isIdentityMatrixAndComposedGatesAreEqual(vector2d identityMatrix, vector2d composedGates);

/// Used to check\n
/// if composed gates gives identity matrix.
/// \param firstGate vector2d
/// \param secondGate vector2d
/// \return true or false
bool isComposeOfGatesGivesIdentityMatrix(vector2d firstGate, vector2d secondGate);

/// Used to check if matrix is unitary.\n
/// Unitary matrix - https://en.wikipedia.org/wiki/Unitary_matrix
/// \param quantumGate vector2d
/// \param conjugateTransposedQuantumGate vector2d
/// \return true or false
bool isMatrixUnitary(vector2d quantumGate, vector2d conjugateTransposedQuantumGate);

#endif