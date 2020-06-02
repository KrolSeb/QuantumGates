#include "gtest/gtest.h"
#include "headers/quantumComputer.h"
#include <complex>

using namespace std;
using namespace quantum;

/// Test to check that normalization of base vector works properly for incorrect probabilities
TEST(quantumComputer, isSumOfProbabilitiesAfterNormalizationEqualOne) {
    int numberOfQubits = 3;
    int arraySize = pow(2, numberOfQubits);
    double probabilities[] = {4.0, 0.0, 3.0, 0.0, 4.0, 0.0, 3.0, 0.0};

    /// Definition of structure
    /// Method validateProbability() is launched and when (sum of probabilities are != 1)
    /// normalizeRegister and resetState methods should executed (correction of probabilities)
    struct QuantumComputer quantumComputer = QuantumComputer(numberOfQubits, probabilities, arraySize);

    /// Show probabilities after normalization
    quantumComputer.viewProbabilityForBaseVector();

    /// Sum of probabilities after correction (it should be 1)
    double result = 0.0;
    for (auto x: quantumComputer.baseVector) {
        result += pow(sqrt(fabs(x)), 2);
    }

    ASSERT_EQ(1.0, result);
}
