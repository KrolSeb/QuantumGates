#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>

using namespace std;

/// \param - size of one argument quantum gates
const int ONE_ARGUMENT_GATE_SIZE = 2;
/// \param - size of two argument quantum gates
const int TWO_ARGUMENTS_GATE_SIZE = 4;
/// \param - size of three argument quantum gates
const int THREE_ARGUMENTS_GATE_SIZE = 8;

/// Used to generate and get quantum gate for declared dimensions
/// \param dimension int
complex<double> **getAllocatedQuantumGate(int dimension);

/// Used to make NOT quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeNotOnQubit(complex<double> **qubit);

/// Used to make SQRT(NOT) quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeSqrtNotOnQubit(complex<double> **qubit);

/// Used to make CNOT quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeCnotOnQubit(complex<double> **qubit);

/// Used to make SWAP quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeSwapOnQubit(complex<double> **qubit);

/// Used to make FREDKIN quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeFredkinOnQubit(complex<double> **qubit);

/// Used to make TOFFOLI quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeToffoliOnQubit(complex<double> **qubit);

/// Used to make HADAMARD quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makeHadamardOnQubit(complex<double> **qubit);

/// Used to make multidimensional HADAMARD quantum gate on qubit
/// \param qubit complex<double>
/// \param numberOfQubits int
/// \param hadamardGate complex<double>
/// \param indexNumber int
/// \return updated qubit
complex<double> **makeMultidimensionalHadamardOnQubit(complex<double> **qubit, int numberOfQubits,
                                                      complex<double> **hadamardGate, int indexNumber);

/// Used to make PHASE SHIFT quantum gate on qubit
/// \param qubit complex<double>
/// \param angle double - angle as value eg. PI or -PI
/// \return updated qubit
complex<double> **makePhaseShiftOnQubit(complex<double> **qubit, double angle);

/// Used to make PAULI X quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makePauliXOnQubit(complex<double> **qubit);

/// Used to make PAULI Y quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makePauliYOnQubit(complex<double> **qubit);

/// Used to make PAULI Z quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
complex<double> **makePauliZOnQubit(complex<double> **qubit);


/// Used to get NOT quantum gate
/// \return NOT quantum gate
complex<double> **getNotGate();

/// Used to get SQRT(NOT) quantum gate
/// \return SQRT(NOT) quantum gate
complex<double> **getSqrtNotGate();

/// Used to get CNOT quantum gate
/// \return CNOT quantum gate
complex<double> **getCnotGate();

/// Used to get SWAP quantum gate
/// \return SWAP quantum gate
complex<double> **getSwapGate();

/// Used to get FREDKIN quantum gate
/// \return FREDKIN quantum gate
complex<double> **getFredkinGate();

/// Used to get TOFFOLI quantum gate
/// \return TOFFOLI quantum gate
complex<double> **getToffoliGate();

/// Used to get HADAMARD quantum gate
/// \return HADAMARD quantum gate
complex<double> **getHadamardGate();

/// Used to get multidimensional HADAMARD quantum gate
/// \param indexNumber int
/// \return multidimensional HADAMARD quantum gate
complex<double> **getMultidimensionalHadamardGate(int indexNumber);

/// Used to get PHASE SHIFT quantum gate
/// \param angle double - angle as value eg. PI or -PI
/// \return PHASE SHIFT quantum gate
complex<double> **getPhaseShiftGate(double angle);

/// Used to get PAULI X quantum gate
/// \return PAULI X quantum gate
complex<double> **getPauliXGate();

/// Used to get PAULI Y quantum gate
/// \return PAULI Y quantum gate
complex<double> **getPauliYGate();

/// Used to get PAULI Z quantum gate
/// \return PAULI Z quantum gate
complex<double> **getPauliZGate();

/// Used to show all elements of quantum gate
/// \param quantumGate complex<double>
/// \param gateSize const int
void showQuantumGate(complex<double> **quantumGate, const int gateSize);

/// Used to show all elements of PHASE SHIFT quantum gate
/// \param phaseShiftGate complex<double>
/// \param gateSize const int
void showPhaseShiftQuantumGate(complex<double> **phaseShiftGate, const int gateSize);

/// Used to show all elements of multidimensional HADAMARD quantum gate
/// \param hadamardGate complex<double>
/// \param indexNumber int
void showMultidimensionalHadamardGate(complex<double> **hadamardGate, int indexNumber);

#endif
