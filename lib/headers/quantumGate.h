#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

/// @params - constant sizes of quantum gates representations
const int ONE_ARGUMENT_GATE_SIZE = 2;
const int TWO_ARGUMENTS_GATE_SIZE = 4;
const int THREE_ARGUMENTS_GATE_SIZE = 8;

/// @param - constant size of columns in input qubits
const int QUBIT_COLUMNS_SIZE = 1;

double *makeNotOnQubit(double *qubit);
std::complex<double> *makeSqrtNotOnQubit(double *qubit);
double *makeCnotOnQubit(double *qubit);
double *makeSwapOnQubit(double *qubit);
double *makeFredkinOnQubit(double *qubit);
double *makeToffoliOnQubit(double *qubit);
double *makeHadamardOnQubit(double *qubit);
double *makePhaseShiftOnQubit(double angle, double *qubit);
double *makePauliXOnQubit(double *qubit);
std::complex<double> *makePauliYOnQubit(double *qubit);
double *makePauliZOnQubit(double *qubit);

double **getNotGate();
double **getMultidimensionalHadamardGate(int indexNumber);

void printMultidimensionalHadamardGate(double **hadamardGate, int indexNumber);

#endif //QUANTUMGATES_QUANTUMGATE_H
