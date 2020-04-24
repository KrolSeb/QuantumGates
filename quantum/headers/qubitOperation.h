#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <complex>
#include <vector>

using namespace std;
/// Used as alias for declaration of two dimensional vector
typedef vector<vector<complex<double>>> vector2d;

/// \param - constant single qubit rows
const int SINGLE_QUBIT_NUMBER_OF_ROWS = 2;
/// \param - constant two qubits rows
const int TWO_QUBITS_NUMBER_OF_ROWS = 4;
/// \param - constant three qubits rows
const int THREE_QUBITS_NUMBER_OF_ROWS = 8;

/// \param - constant qubit column
const int QUBIT_NUMBER_OF_COLUMNS = 1;

/// Used to get defined qubit for declared dimension
/// \param qubitRows int
/// \return allocated qubit
vector2d getPreparedContainerForQubit(int qubitRows);

/// Used to make dot product of two qubits.\n
/// Dot product - https://en.wikipedia.org/wiki/Dot_product#Algebraic_definition
/// \param firstQubit vector2d
/// \param secondQubit vector2d
/// \return dot product of qubits
vector2d makeDotProductOfQubits(vector2d firstQubit, vector2d secondQubit);

/// Used to get qubit as complex type 2D array
/// \param baseVector vector<double>
/// \return qubit
vector2d getQubitRepresentation(vector<double> baseVector);

/// Used to show all elements of qubit (2D array)
/// \param qubit vector2d
void showQubit(vector2d qubit);

/// Used to show dot product
/// \param dotProduct vector2d
void showDotProduct(vector2d dotProduct);

#endif
