#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

/// @params - constant sizes of quantum gates representations
const int ONE_ARGUMENT_GATE_SIZE = 2;
const int TWO_ARGUMENTS_GATE_SIZE = 4;
const int THREE_ARGUMENTS_GATE_SIZE = 8;

double *makeNotOnQubit(double *qubit, const int QUBIT_COLUMNS);
double *makeCnotOnQubit(double *qubit, const int QUBIT_COLUMNS);
double *makeSwapOnQubit(double *qubit, const int QUBIT_COLUMNS);
double *makeFredkinOnQubit(double *qubit, const int QUBIT_COLUMNS);
double *makeToffoliOnQubit(double *qubit, const int QUBIT_COLUMNS);

double **getNotGate();
std::complex<double> **multiplySqrtNotScalarByMatrix();
std::complex<double> **multiplyHadamardScalarByMatrix();

#endif //QUANTUMGATES_QUANTUMGATE_H
