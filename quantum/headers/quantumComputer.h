#ifndef UNTITLED_QUANTUM_H
#define UNTITLED_QUANTUM_H
#include <vector>

using namespace std;

namespace quantum {
    /// QuantumComputer structure
    struct QuantumComputer {
        int registerSize;
        int baseVectorsCount;
        bool isNormalize;
        bool isMeasured;
        vector<double> baseVector;

        /// QuantumComputer constructor
        /// \param registerSize int
        /// \param probabilities double[]
        /// \param arraysize int
        QuantumComputer(int regSize, double probabilities[], int arrSize);

        /// Used to count elements of vector\n
        /// where element not equal zero
        void countNonZeroBaseVector();

        /// Used to reset state of base vector\n
        /// First element of vector is set to one, other elements are set to 0
        void resetState();

        /// Used to show probabilities of base vector
        void viewProbabilityForBaseVector();

        /// Used to show values in base vector
        void viewValuesInBaseVector();

        /// Used to show qubit/s in Dirac notation\n
        /// eg. for qubit 0 - |0>
        void viewQubitsInDiracNotation();

        /// Used to check register size and array size from input
        /// \param arraySize int
        /// \param registerSize int
        static void validateArraySize(int arrSize, int regSize);

        /// Used to check probabilities of base vector\n
        /// If sum of square probabilities is not equal one, normalizeRegister() and resetState() is executed
        void validateProbability();

        /// Used to normalize probabilities of base vector (register)
        void normalizeRegister();

        /// Used to measure probabilities of base vector (not implemented yet)
        void measure();

        /// Used to extend register by defined number of qubits(size)
        void extendRegister(int size);

        /// Used to replace value in existing register
        void setValueInRegister(int arrayIndex, double value);

        /// Used to display all information about qubit
        void displayInfo();

        /// Used to get created base vector
        /// \return base vector
        vector<double> getBaseVector();
    };
}

#endif