#ifndef QUANTUMGATES_QUANTUMGATEOPERATION_H
#define QUANTUMGATES_QUANTUMGATEOPERATION_H
#include <complex>

using namespace std;

/// Used to compose two quantum gates.\n
/// Compose - multiplication of values from two matrices, at the same indexes
/// \param firstGate complex<double>
/// \param secondGate complex<double>
/// \param gateSize int
/// \return composed quantum gates
complex<double> **composeQuantumGates(complex<double> **firstGate, complex<double> **secondGate, int gateSize);

/// Used to get identity matrix for defined size.\n
/// Identity matrix - https://en.wikipedia.org/wiki/Identity_matrix
/// \param gateSize int
/// \return identity matrix
complex<double> **getIdentityMatrix(int gateSize);

/// Function used to check\n
/// if identity matrix are the same as composed gates.
/// \param identityMatrix complex<double>
/// \param composedGates complex<double>
/// \param gateSize int
/// \return true or false
bool isIdentityMatrixAndComposedGatesAreEqual(complex<double> **identityMatrix, complex<double> **composedGates, int gateSize);

/// Function used to check\n
/// if composed gates given identity matrix.
/// \param firstGate complex<double>
/// \param secondGate complex<double>
/// \param gateSize int
/// \return true or false
bool isComposeOfGatesGivesIdentityMatrix(complex<double> **firstGate, complex<double> **secondGate, int gateSize);

/// Function used to check if matrix is unitary.\n
/// Unitary matrix - https://en.wikipedia.org/wiki/Unitary_matrix
/// \param quantumGate complex<double>
/// \param conjugateTransposedQuantumGate complex<double>
/// \param gateSize int
/// \return true or false
bool isMatrixUnitary(complex<double> **quantumGate, complex<double> **conjugateTransposedQuantumGate, int gateSize);

#endif