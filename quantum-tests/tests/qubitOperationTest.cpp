#include "gtest/gtest.h"
#include "headers/quantumComputer.h"
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"
#include <complex>

using namespace std;
using namespace quantum;

const int qubitColumns = 1;

complex<double> **prepareQubit(int numberOfQubits, double *probabilities) {
    int arraySize = pow(2, numberOfQubits);
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);

    return getQubitRepresentation(quantumComputer.getBaseVector());
}

TEST(qubitOperation, testCalculatingDotProductOfSingleQubit) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **singleQubit = prepareQubit(numberOfQubits, probabilitiesOfQubit0);
    complex<double> **transposedAndConjugatedQubit = makeConjugateTranspose(singleQubit, SINGLE_QUBIT_NUMBER_OF_ROWS, QUBIT_NUMBER_OF_COLUMNS);

    complex<double> **dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, singleQubit, SINGLE_QUBIT_NUMBER_OF_ROWS, QUBIT_NUMBER_OF_COLUMNS);
    complex<double> expectedQubit[1][1] = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}

TEST(qubitOperation, testCalculatingDotProductOfTwoQubits) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit00[] = {1, 0, 0, 0};

    complex<double> **twoQubits = prepareQubit(numberOfQubits, probabilitiesOfQubit00);
    complex<double> **transposedAndConjugatedQubit = makeConjugateTranspose(twoQubits, TWO_QUBITS_NUMBER_OF_ROWS, TWO_QUBITS_NUMBER_OF_ROWS);

    complex<double> **dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, twoQubits, TWO_QUBITS_NUMBER_OF_ROWS, QUBIT_NUMBER_OF_COLUMNS);
    complex<double> expectedQubit[1][1] = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}

TEST(qubitOperation, testCalculatingDotProductOfThreeQubits) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit111[] = {0, 0, 0, 0, 0, 0, 0, 1};

    complex<double> **threeQubits = prepareQubit(numberOfQubits, probabilitiesOfQubit111);
    complex<double> **transposedAndConjugatedQubit = makeConjugateTranspose(threeQubits, THREE_QUBITS_NUMBER_OF_ROWS, THREE_QUBITS_NUMBER_OF_ROWS);

    complex<double> **dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, threeQubits, THREE_QUBITS_NUMBER_OF_ROWS, QUBIT_NUMBER_OF_COLUMNS);
    complex<double> expectedQubit[1][1] = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}