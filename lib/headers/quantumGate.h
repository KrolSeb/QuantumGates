#ifndef QUANTUMGATES_QUANTUMGATE_H
#define QUANTUMGATES_QUANTUMGATE_H

/// @params - constans sizes of quantum gates
const int NOT_GATE_ROWS = 2, NOT_GATE_COLUMNS = 2;

int ** getNotGate();
int ** makeNotOnQubit(int **qubit, const int QUBIT_COLUMNS);

#endif //QUANTUMGATES_QUANTUMGATE_H
