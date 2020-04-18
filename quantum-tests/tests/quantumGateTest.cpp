#include "gtest/gtest.h"
#include "headers/quantumGate.h"
#include "headers/quantumComputer.h"
#include <headers/qubitOperation.h>
#include <complex>

using namespace std;
using namespace quantum;

const int qubitColumns = 1;

complex<double> **getQubit(int numberOfQubits, double *probabilities) {
    int arraySize = pow(2, numberOfQubits);
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);

    return getQubitRepresentation(quantumComputer.getBaseVector());
}

TEST(quantumGate, testNotForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **qubit = getQubit(numberOfQubits, probabilitiesOfQubit0);
    complex<double> **qubitAfterNot = makeNotOnQubit(qubit);
    complex<double> expectedQubit[2][1] = {{0}, {1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterNot[i][j]);
        }
    }
}

TEST(quantumGate, testNotForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {0, 1};

    complex<double> **qubitAfterNot = makeNotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));
    complex<double> expectedQubit[2][1] = {{1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterNot[i][j]);
        }
    }
}

TEST(quantumGate, testSqrtNotForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **qubitAfterSqrtNot = makeSqrtNotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0));

    complex<double> PLUS_VALUE(0.5, 0.5);
    complex<double> MINUS_VALUE(0.5, -0.5);
    complex<double> expectedQubit[2][1] = {{PLUS_VALUE}, {MINUS_VALUE}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSqrtNot[i][j]);
        }
    }
}

TEST(quantumGate, testSqrtNotForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {0, 1};

    complex<double> **qubitAfterSqrtNot = makeSqrtNotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));

    complex<double> PLUS_VALUE(0.5, 0.5);
    complex<double> MINUS_VALUE(0.5, -0.5);
    complex<double> expectedQubit[2][1] = {{MINUS_VALUE}, {PLUS_VALUE}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSqrtNot[i][j]);
        }
    }
}

TEST(quantumGate, testCnotForQubit00) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit00[] = {1, 0, 0, 0};

    complex<double> **qubitAfterCnot = makeCnotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit00));
    complex<double> expectedQubit[4][1] = {{1}, {0}, {0}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterCnot[i][j]);
        }
    }
}

TEST(quantumGate, testCnotForQubit01) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit01[] = {0, 1, 0, 0};

    complex<double> **qubitAfterCnot = makeCnotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit01));
    complex<double> expectedQubit[4][1] = {{0}, {1}, {0}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterCnot[i][j]);
        }
    }
}

TEST(quantumGate, testCnotForQubit10) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit10[] = {0, 0, 1, 0};

    complex<double> **qubitAfterCnot = makeCnotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit10));
    complex<double> expectedQubit[4][1] = {{0}, {0}, {0}, {1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterCnot[i][j]);
        }
    }
}

TEST(quantumGate, testCnotForQubit11) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit11[] = {0, 0, 0, 1};

    complex<double> **qubitAfterCnot = makeCnotOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit11));
    complex<double> expectedQubit[4][1] = {{0}, {0}, {1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterCnot[i][j]);
        }
    }
}

TEST(quantumGate, testSwapForQubit00) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit00[] = {0, 0, 0, 0};

    complex<double> **qubitAfterSwap = makeSwapOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit00));
    complex<double> expectedQubit[4][1] = {{0}, {0}, {0}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSwap[i][j]);
        }
    }
}

TEST(quantumGate, testSwapForQubit01) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit01[] = {0, 1, 0, 0};

    complex<double> **qubitAfterSwap = makeSwapOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit01));
    complex<double> expectedQubit[4][1] = {{0}, {0}, {1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSwap[i][j]);
        }
    }
}

TEST(quantumGate, testSwapForQubit10) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit10[] = {0, 0, 1, 0};

    complex<double> **qubitAfterSwap = makeSwapOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit10));
    complex<double> expectedQubit[4][1] = {{0}, {1}, {0}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSwap[i][j]);
        }
    }
}

TEST(quantumGate, testSwapForQubit11) {
    int numberOfQubits = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit11[] = {0, 0, 0, 1};

    complex<double> **qubitAfterSwap = makeSwapOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit11));
    complex<double> expectedQubit[4][1] = {{0}, {0}, {0}, {1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterSwap[i][j]);
        }
    }
}

TEST(quantumGate, testFredkinForQubit101) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit101[] = {0, 0, 0, 0, 0, 1, 0, 0};

    complex<double> **qubitAfterFredkin = makeFredkinOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit101));
    complex<double> expectedQubit[8][1] = {{0}, {0}, {0}, {0}, {0}, {0}, {1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterFredkin[i][j]);
        }
    }
}

TEST(quantumGate, testFredkinForQubit110) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit110[] = {0, 0, 0, 0, 0, 0, 1, 0};

    complex<double> **qubitAfterFredkin = makeFredkinOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit110));
    complex<double> expectedQubit[8][1] = {{0}, {0}, {0}, {0}, {0}, {1}, {0}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterFredkin[i][j]);
        }
    }
}

TEST(quantumGate, testToffoliForQubit110) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit110[] = {0, 0, 0, 0, 0, 0, 1, 0};

    complex<double> **qubitAfterToffoli = makeToffoliOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit110));
    complex<double> expectedQubit[8][1] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterToffoli[i][j]);
        }
    }
}

TEST(quantumGate, testToffoliForQubit111) {
    int numberOfQubits = 3;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit111[] = {0, 0, 0, 0, 0, 0, 0, 1};

    complex<double> **qubitAfterToffoli = makeToffoliOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit111));
    complex<double> expectedQubit[8][1] = {{0}, {0}, {0}, {0}, {0}, {0}, {1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterToffoli[i][j]);
        }
    }
}

TEST(quantumGate, testHadamardWalshForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **qubitAfterHadamardWalsh = makeHadamardOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0));
    complex<double> expectedQubit[2][1] = {{0.707107}, {0.707107}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_DOUBLE_EQ(round(real(expectedQubit[i][j])), round(real(qubitAfterHadamardWalsh[i][j])));
        }
    }
}

TEST(quantumGate, testHadamardWalshForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {0, 1};

    complex<double> **qubitAfterHadamardWalsh = makeHadamardOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));
    complex<double> expectedQubit[2][1] = {{0.707107}, {-0.707107}};

    double expectedValue;
    double actualValue;
    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            expectedValue = round(real(expectedQubit[i][j]) * 10000.0 ) / 10000.0;
            actualValue = round(real(qubitAfterHadamardWalsh[i][j]) * 10000.0 ) / 10000.0;
            ASSERT_DOUBLE_EQ(expectedValue, actualValue);
        }
    }
}

TEST(quantumGate, testHadamardN2ForQubit00) {
    int numberOfQubits = 2;
    int indexNumber = 2;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit00[] = {1, 0, 0, 0};

    complex<double> **qubitAfterHadamardN2 = makeMultidimensionalHadamardOnQubit(
            getQubit(numberOfQubits, probabilitiesOfQubit00),
            numberOfQubits, getMultidimensionalHadamardGate(indexNumber), indexNumber);
    complex<double> expectedQubit[4][1] = {{0.5}, {0.5}, {0.5}, {0.5}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_DOUBLE_EQ(real(expectedQubit[i][j]), real(qubitAfterHadamardN2[i][j]));
        }
    }
}

TEST(quantumGate, testPhaseShiftForPiAndQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);

    double angle = M_PI;
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **qubitAfterPhaseShiftPI = makePhaseShiftOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0), angle);
    complex<double> expectedQubit[2][1] = {{1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPhaseShiftPI[i][j]);
        }
    }
}

TEST(quantumGate, testPhaseShiftForPiAndQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);

    double angle = M_PI;
    double probabilitiesOfQubit1[] = {0, 1};

    complex<double> **qubitAfterPhaseShiftPI = makePhaseShiftOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1), angle);
    complex<double> expectedQubit[2][1] = {{0}, {-1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(round(real(expectedQubit[i][j])), round(real(qubitAfterPhaseShiftPI[i][j])));
        }
    }
}

TEST(quantumGate, testPauliXForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {0, 1};

    complex<double> **qubitAfterPauliX = makePauliXOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0));
    complex<double> expectedQubit[2][1] = {{1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPauliX[i][j]);
        }
    }
}

TEST(quantumGate, testPauliXForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {1, 0};

    complex<double> **qubitAfterPauliX = makePauliXOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));
    complex<double> expectedQubit[2][1] = {{0}, {1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPauliX[i][j]);
        }
    }
}

TEST(quantumGate, testPauliYForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit0[] = {0, 1};

    complex<double> **qubitAfterPauliY = makePauliYOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0));
    complex<double> upperValue(0, -1);
    complex<double> expectedQubit[2][1] = {{upperValue}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPauliY[i][j]);
        }
    }
}

TEST(quantumGate, testPauliYForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {1, 0};

    complex<double> **qubitAfterPauliY = makePauliYOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));
    complex<double> lowerValue(0, 1);
    complex<double> expectedQubit[2][1] = {{0}, {lowerValue}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPauliY[i][j]);
        }
    }
}

TEST(quantumGate, testPauliZForQubit0) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);

    double angle = M_PI;
    double probabilitiesOfQubit0[] = {1, 0};

    complex<double> **qubitAfterPauliZ = makePauliZOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit0));
    complex<double> expectedQubit[2][1] = {{1}, {0}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(expectedQubit[i][j], qubitAfterPauliZ[i][j]);
        }
    }
}

TEST(quantumGate, testPauliZForQubit1) {
    int numberOfQubits = 1;
    int qubitRows = pow(2, numberOfQubits);
    double probabilitiesOfQubit1[] = {0, 1};

    complex<double> **qubitAfterPauliZ = makePauliZOnQubit(getQubit(numberOfQubits, probabilitiesOfQubit1));
    complex<double> expectedQubit[2][1] = {{0}, {-1}};

    for (int i = 0; i < qubitRows; i++) {
        for (int j = 0; j < qubitColumns; j++) {
            ASSERT_EQ(round(real(expectedQubit[i][j])), round(real(qubitAfterPauliZ[i][j])));
        }
    }
}