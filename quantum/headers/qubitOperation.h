#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <complex>
#include <vector>

/// @params - constant sizes of qubit rows
const int SINGLE_QUBIT_NUMBER_OF_ROWS = 2;
const int TWO_QUBITS_NUMBER_OF_ROWS = 4;
const int THREE_QUBITS_NUMBER_OF_ROWS = 8;

/// @params - constant size of qubit columns
const int QUBIT_NUMBER_OF_COLUMNS = 1;

/// @functions
std::complex<double> **getAllocatedQubit(int rows);
std::complex<double> **makeDotProductOfQubits(std::complex<double> **firstQubit, std::complex<double> **secondQubit, int rows, int columns);
std::complex<double> **getQubitRepresentation(std::vector<double> baseVector);

/// @functions - presents qubits and scalar product results
void showQubit(std::complex<double> **qubit, const int qubitRows);
void showQubitAfterConjugateTranspose(std::complex<double> **qubit, const int qubitRows);
void showDotProduct(std::complex<double> **dotProduct);

#endif