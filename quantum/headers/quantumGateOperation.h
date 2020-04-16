#ifndef QUANTUMGATES_QUANTUMGATEOPERATION_H
#define QUANTUMGATES_QUANTUMGATEOPERATION_H
#include <complex>

/// @functions
bool isComposeOfGatesGivesIdentityMatrix(std::complex<double> **firstGate, std::complex<double> **secondGate, int gateSize);
bool isMatrixUnitary(std::complex<double> **quantumGate, std::complex<double> **conjugateTransposedQuantumGate, int gateSize);

#endif
