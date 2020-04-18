#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

/// @params - constant sizes of quantum gates representations
const int ONE_ARGUMENT_GATE_SIZE = 2;
const int TWO_ARGUMENTS_GATE_SIZE = 4;
const int THREE_ARGUMENTS_GATE_SIZE = 8;

/// @function - @returns allocated quantum gate
std::complex<double> **getAllocatedQuantumGate(int dimension);

/// @functions - @returns qubits after quantum gates operations
std::complex<double> **makeNotOnQubit(std::complex<double> **qubit);
std::complex<double> **makeSqrtNotOnQubit(std::complex<double> **qubit);
std::complex<double> **makeCnotOnQubit(std::complex<double> **qubit);
std::complex<double> **makeSwapOnQubit(std::complex<double> **qubit);
std::complex<double> **makeFredkinOnQubit(std::complex<double> **qubit);
std::complex<double> **makeToffoliOnQubit(std::complex<double> **qubit);
std::complex<double> **makeHadamardOnQubit(std::complex<double> **qubit);
std::complex<double> **makeMultidimensionalHadamardOnQubit(std::complex<double> **qubit, int numberOfQubits,
                                                           std::complex<double> **hadamardGate, int indexNumber);
std::complex<double> **makePhaseShiftOnQubit(std::complex<double> **qubit, double angle);
std::complex<double> **makePauliXOnQubit(std::complex<double> **qubit);
std::complex<double> **makePauliYOnQubit(std::complex<double> **qubit);
std::complex<double> **makePauliZOnQubit(std::complex<double> **qubit);

/// @functions - @returns implementations of quantum gates
std::complex<double> **getNotGate();
std::complex<double> **getSqrtNotGate();
std::complex<double> **getCnotGate();
std::complex<double> **getSwapGate();
std::complex<double> **getFredkinGate();
std::complex<double> **getToffoliGate();
std::complex<double> **getHadamardGate();
std::complex<double> **getMultidimensionalHadamardGate(int indexNumber);
std::complex<double> **getPhaseShiftGate(double angle);
std::complex<double> **getPauliXGate();
std::complex<double> **getPauliYGate();
std::complex<double> **getPauliZGate();

/// @functions - presents implementations of quantum gates
void showQuantumGate(std::complex<double> **quantumGate, const int gateSize);
void showMultidimensionalHadamardGate(std::complex<double> **hadamardGate, int indexNumber);

#endif
