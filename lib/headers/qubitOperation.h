#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <algorithm>
#include <vector>
#include <complex>

const int ROWS_NUMBER_IN_SINGLE_QUBIT = 2;
const int ROWS_NUMBER_IN_TWO_QUBITS = 4;
const int ROWS_NUMBER_IN_THREE_QUBITS = 8;
const int COLUMN_NUMBER_IN_QUBIT = 1;

std::complex<double> **makeConjugateTransposeOnQubit(std::complex<double> **qubit, const int rows, const int columns);

std::complex<double> **getQubitRepresentation(std::vector<double> baseVector);

void printQubit(std::complex<double> **qubit, const int qubitRows);
void printQubitAfterConjugateTranspose(std::complex<double> **qubit,  const int qubitRows);

#endif //QUANTUMGATES_QUBITOPERATION_H