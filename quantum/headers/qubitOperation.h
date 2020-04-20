#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <complex>
#include <vector>

using namespace std;

/// \param - constant single qubit rows
const int SINGLE_QUBIT_NUMBER_OF_ROWS = 2;
/// \param - constant two qubits rows
const int TWO_QUBITS_NUMBER_OF_ROWS = 4;
/// \param - constant three qubits rows
const int THREE_QUBITS_NUMBER_OF_ROWS = 8;

/// \param - constant qubit column
const int QUBIT_NUMBER_OF_COLUMNS = 1;

/// Used to get allocated qubit
/// \param rows int
/// \return allocated qubit
complex<double> **getAllocatedQubit(int rows);

/// Used to make dot product of two qubits.\n
/// Dot product - https://en.wikipedia.org/wiki/Dot_product#Algebraic_definition
/// \param firstQubit complex<double>
/// \param secondQubit complex<double>
/// \param rows int
/// \param columns int
/// \return dot product of qubits
complex<double> **makeDotProductOfQubits(complex<double> **firstQubit, complex<double> **secondQubit, int rows, int columns);

/// Used to get qubit as complex type 2D array
/// \param baseVector vector<double>
/// \return qubit
complex<double> **getQubitRepresentation(vector<double> baseVector);

/// Used to show all elements of qubit (2D array)
/// \param qubit complex<double>
/// \param qubitRows const int
void showQubit(complex<double> **qubit, const int qubitRows);

/// Used to show qubit after conjugate transpose (reversed columns and rows number)
/// \param qubit complex<double>
/// \param qubitRows const int
void showQubitAfterConjugateTranspose(complex<double> **qubit, const int qubitRows);

/// Used to show dot product
/// \param dotProduct complex<double>
void showDotProduct(complex<double> **dotProduct);

#endif