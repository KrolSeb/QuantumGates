#ifndef QUANTUMGATES_QUBITOPERATION_H
#define QUANTUMGATES_QUBITOPERATION_H
#include <algorithm>
#include <vector>

const int SINGLE_QUBIT_ROWS = 2;
const int TWO_QUBIT_ROWS = 4;
const int THREE_QUBIT_ROWS = 8;
const int QUBIT_COLUMNS = 1;

void printSingleQubit(double *singleQubit);
void printTwoQubits(double *qubits);
void printThreeQubits(double *qubits);
double *getBaseVectorAsArray(std::vector<double> baseVector);

#endif //QUANTUMGATES_QUBITOPERATION_H
