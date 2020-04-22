#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H
#include <complex>
#include <vector>

using namespace std;
typedef vector<vector<complex<double>>> vector2d;

/// \param - size of one argument quantum gates
const int ONE_ARGUMENT_GATE_SIZE = 2;
/// \param - size of two argument quantum gates
const int TWO_ARGUMENTS_GATE_SIZE = 4;
/// \param - size of three argument quantum gates
const int THREE_ARGUMENTS_GATE_SIZE = 8;

/// Used to generate and get quantum gate for declared dimensions
/// \param dimension int
vector2d getPreparedContainerForQuantumGate(int dimension);

/// Used to make NOT quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeNotOnQubit(vector2d qubit);

/// Used to make SQRT(NOT) quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeSqrtNotOnQubit(vector2d);

/// Used to make CNOT quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeCnotOnQubit(vector2d qubit);

/// Used to make SWAP quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeSwapOnQubit(vector2d qubit);

/// Used to make FREDKIN quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeFredkinOnQubit(vector2d qubit);

/// Used to make TOFFOLI quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeToffoliOnQubit(vector2d qubit);

/// Used to make HADAMARD quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makeHadamardOnQubit(vector2d qubit);

/// Used to make multidimensional HADAMARD quantum gate on qubit
/// \param qubit complex<double>
/// \param hadamardGate complex<double>
/// \param indexNumber int
/// \return updated qubit
vector2d makeMultidimensionalHadamardOnQubit(vector2d qubit, vector2d hadamardGate, int indexNumber);

/// Used to make PHASE SHIFT quantum gate on qubit
/// \param qubit complex<double>
/// \param angle double - angle as value eg. PI or -PI
/// \return updated qubit
vector2d makePhaseShiftOnQubit(vector2d qubit, double angle);

/// Used to make PAULI X quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makePauliXOnQubit(vector2d qubit);

/// Used to make PAULI Y quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makePauliYOnQubit(vector2d qubit);

/// Used to make PAULI Z quantum gate on qubit
/// \param qubit complex<double>
/// \return updated qubit
vector2d makePauliZOnQubit(vector2d qubit);


/// Used to get NOT quantum gate
/// \return NOT quantum gate
vector2d getNotGate();

/// Used to get SQRT(NOT) quantum gate
/// \return SQRT(NOT) quantum gate
vector2d getSqrtNotGate();

/// Used to get CNOT quantum gate
/// \return CNOT quantum gate
vector2d getCnotGate();

/// Used to get SWAP quantum gate
/// \return SWAP quantum gate
vector2d getSwapGate();

/// Used to get FREDKIN quantum gate
/// \return FREDKIN quantum gate
vector2d getFredkinGate();

/// Used to get TOFFOLI quantum gate
/// \return TOFFOLI quantum gate
vector2d getToffoliGate();

/// Used to get HADAMARD quantum gate
/// \return HADAMARD quantum gate
vector2d getHadamardGate();

/// Used to get multidimensional HADAMARD quantum gate
/// \param indexNumber int
/// \return multidimensional HADAMARD quantum gate
vector2d getMultidimensionalHadamardGate(int indexNumber);

/// Used to get PHASE SHIFT quantum gate
/// \param angle double - angle as value eg. PI or -PI
/// \return PHASE SHIFT quantum gate
vector2d getPhaseShiftGate(double angle);

/// Used to get PAULI X quantum gate
/// \return PAULI X quantum gate
vector2d getPauliXGate();

/// Used to get PAULI Y quantum gate
/// \return PAULI Y quantum gate
vector2d getPauliYGate();

/// Used to get PAULI Z quantum gate
/// \return PAULI Z quantum gate
vector2d getPauliZGate();


/// Used to show all elements of quantum gate
/// \param quantumGate complex<double>
/// \param gateSize const int
void showQuantumGate(vector2d quantumGate);

/// Used to show all elements of PHASE SHIFT quantum gate
/// \param phaseShiftGate complex<double>
/// \param gateSize const int
void showPhaseShiftQuantumGate(vector2d phaseShiftGate);

#endif
