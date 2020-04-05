#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <algorithm>
#include <vector>
#include <complex>

const int ROWS_NUMBER_IN_SINGLE_QUBIT = 2;
const int ROWS_NUMBER_IN_TWO_QUBITS = 4;
const int ROWS_NUMBER_IN_THREE_QUBITS = 8;
const int COLUMN_NUMBER_IN_QUBIT = 1;

void printQubit(double *singleQubit, const int qubitRows);
void printComplexQubit(std::complex<double> *qubit, const int qubitRows);
double *getBaseVectorAsArray(std::vector<double> baseVector);

#endif //QUANTUMGATES_QUBITOPERATION_H
