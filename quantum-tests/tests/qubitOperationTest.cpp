#include "gtest/gtest.h"
#include "headers/quantumComputer.h"
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"
#include <complex>

using namespace std;
using namespace quantum;

const int qubitColumns = 1;

vector2d prepareQubit(int numberOfQubits, double *probabilities) {
    int arraySize = pow(2, numberOfQubits);
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);

    return getQubitRepresentation(quantumComputer.getBaseVector());
}

TEST(qubitOperation, testCalculatingDotProductOfSingleQubit) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {1, 0};

    vector2d singleQubit = prepareQubit(numberOfQubits, probabilitiesOfQubit0);
    vector2d transposedAndConjugatedQubit = makeConjugateTranspose(singleQubit);

    vector2d dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, singleQubit);
    vector2d expectedQubit = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}

TEST(qubitOperation, testCalculatingDotProductOfTwoQubits) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit00[] = {1, 0, 0, 0};

    vector2d twoQubits = prepareQubit(numberOfQubits, probabilitiesOfQubit00);
    vector2d transposedAndConjugatedQubit = makeConjugateTranspose(twoQubits);

    vector2d dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, twoQubits);
    vector2d expectedQubit = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}

TEST(qubitOperation, testCalculatingDotProductOfThreeQubits) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit111[] = {0, 0, 0, 0, 0, 0, 0, 1};

    vector2d threeQubits = prepareQubit(numberOfQubits, probabilitiesOfQubit111);
    vector2d transposedAndConjugatedQubit = makeConjugateTranspose(threeQubits);

    vector2d dotProduct = makeDotProductOfQubits(transposedAndConjugatedQubit, threeQubits);
    vector2d expectedQubit = {{1}};

    ASSERT_EQ(expectedQubit[0][0], dotProduct[0][0]);
}