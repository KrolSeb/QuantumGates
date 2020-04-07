#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

/// @params - constant sizes of quantum gates representations
const int ONE_ARGUMENT_GATE_SIZE = 2;
const int TWO_ARGUMENTS_GATE_SIZE = 4;
const int THREE_ARGUMENTS_GATE_SIZE = 8;

/// @param - constant size of columns in input qubits
const int QUBIT_COLUMNS_SIZE = 1;

/// @functions - @returns qubits after quantum gates operations
double *makeNotOnQubit(double *qubit);
std::complex<double> *makeSqrtNotOnQubit(double *qubit);
double *makeCnotOnQubit(double *qubit);
double *makeSwapOnQubit(double *qubit);
double *makeFredkinOnQubit(double *qubit);
double *makeToffoliOnQubit(double *qubit);
double *makeHadamardOnQubit(double *qubit);
double *makeMultidimensionalHadamardOnQubit(double **hadamardGate, int indexNumber, double *qubit, int qubitsNumber);
double *makePhaseShiftOnQubit(double angle, double *qubit);
double *makePauliXOnQubit(double *qubit);
std::complex<double> *makePauliYOnQubit(double *qubit);
double *makePauliZOnQubit(double *qubit);

/// @functions - @returns implementations of quantum gates
double **getNotGate();
std::complex<double> **getSqrtNotGate();
double **getCnotGate();
double **getSwapGate();
double **getFredkinGate();
double **getToffoliGate();
double **getHadamardGate();
double **getMultidimensionalHadamardGate(int indexNumber);
double **getPhaseShiftGate(double angle);
double **getPauliXGate();
std::complex<double> **getPauliYGate();
double **getPauliZGate();

/// @functions - presents implementations of quantum gates
void printQuantumGate(double **quantumGate, const int gateSize);
void printComplexQuantumGate(std::complex<double> **quantumGate, const int gateSize);
void printMultidimensionalHadamardGate(double **hadamardGate, int indexNumber);

#endif //QUANTUMGATES_QUANTUMGATE_H
