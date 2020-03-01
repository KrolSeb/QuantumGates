#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

/// @params - constans sizes of quantum gates
const int NOT_GATE_ROWS = 2, NOT_GATE_COLUMNS = 2;

/// @functions
int **getNotGate();
int **makeNotOnQubit(int **qubit, const int QUBIT_COLUMNS);
std::complex<double> **multiplySqrtNotScalarByMatrix();
std::complex<double> **multiplyHadamardScalarByMatrix();


#endif //QUANTUMGATES_QUANTUMGATE_H
