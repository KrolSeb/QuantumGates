#include "headers/quantumComputer.h"
#include <cmath>
#include <iostream>
#include <vector>


quantum::QuantumComputer::QuantumComputer(int regSize, double probability[], int arrSize) {
    this->registerSize = regSize;
    this->baseVectorsCount = 0;
    this->isNormalize = false;
    this->isMeasured = false;

    validateArraySize(arrSize, regSize);

    for (int i = 0; i < arrSize; i++) {
        baseVector.push_back(probability[i]);
    }

    validateProbability();
    countNonZeroBaseVector();
}

void quantum::QuantumComputer::countNonZeroBaseVector() {
    for (auto x: this->baseVector) {
        if ((double) x != 0.0) {
            this->baseVectorsCount++;
        }
    }
}

void quantum::QuantumComputer::resetState() {
    std::vector<double>::iterator it;
    for (it = this->baseVector.begin(); it < this->baseVector.end(); it++) {
        *it = 0.0;
    }
    this->baseVector.at(0) = 1;
}

int integerToBinary(int num) {
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    return (num % 2) + 10 * integerToBinary(num / 2);
}

void quantum::QuantumComputer::viewProbability() {
    std::cout << "\nVector with probabilities {";
    for (auto x: this->baseVector) {
        printf("[%.4f]", x);
    }
    std::cout << "}";
}

void quantum::QuantumComputer::viewQubitsInMathExpression() {
    if (!this->isNormalize) {
        std::cout
                << "Base Vector is not in normalize state. To view qubit you should normalize it before.  Use .normalize() function for that"
                << std::endl;
    }
    else {
        printf("\nQubit in expression: \n");
        int i = 0;
        for (auto x: this->baseVector) {
            if (x != 0) {
                int binary = integerToBinary(i);
//                    std::string binaryStringValue = std::to_string(binary);  TODO: Refactor printing of qubit in expression  for register(2) -> |00> not |0>
                if (x == 1.00) {
                    if (binary == 0) {
                        std::string tmp = "";
                        for (int j = 0; j < this->registerSize; j++) {
                            tmp += "0";
                        }
                        std::cout << "|" << tmp << ">";
                    }
                    else {
                        printf("|%d> ", binary);
                    }
                }
                else {
                    if (binary == 0) {
                        std::string tmp = "";
                        for (int j = 0; j < this->registerSize; j++) {
                            tmp += "0";
                        }
                        std::cout << "|" << tmp << ">";
                    }
                    else {
                        printf("%.4f |%d> ", x, binary);
                    }
                }
            }

            i++;
        }
        std::cout << std::endl;
    }
}

void quantum::QuantumComputer::validateArraySize(int arrSize, int regSize) {
    if (regSize < 1) {
        printf("\n[ERROR] Register size cannot be less than 1");
        exit(1);
    }

    if (arrSize != pow(2, regSize)) {
        printf("\n[ERROR] Invalid Register arr with []Probability");
        exit(1);
    }
}

void quantum::QuantumComputer::validateProbability() {
    double result = 0.0;

    for (auto x: this->baseVector) {
        result += pow(sqrt(fabs(x)), 2);
    }

    if (result != 1.0) {
        printf("\n[ERROR] Probability should be equal 1, u can normalize vector use .normalize() function for that");
        this->isNormalize = false;
    }
    else {
        this->isNormalize = true;
    }

}

void quantum::QuantumComputer::normalizeRegister() {
    /* Dopytać Łukasza, jak to działa na przykładzie
     * i czy na czymś się wzorował, jak to implementował, czy to po prostu jego koncepcja.
     * Kiedy normalizacja musi być robiona, tzn. czy tylko
     * przy sumie prawdopodobieństw != 1, czy też gdy jest wszystko ok.
    */
    double vectorLength = 0.0;
    //std::cout << std::endl;

    for (auto x: this->baseVector) {
        //std::cout << x << " ";
        vectorLength += pow(x, 2);
        //std::cout << vectorLength << " ";
    }

    vectorLength = sqrt(vectorLength);
    //std::cout << vectorLength << std::endl;
    std::vector<double>::iterator it;

    for (it = this->baseVector.begin(); it < this->baseVector.end(); it++) {
        //std::cout <<*it << " ";
        *it = *it / vectorLength;
        //std::cout <<*it << " ";
    }

    this->isNormalize = true;

}

// TODO:  DO IT
void quantum::QuantumComputer::QuantumComputer::measure() {
    if (this->isMeasured) {
        std::cout << "U cannot measure collapsed qubit" << std::endl;
        return;
    }
    std::cout << "[Here will be function to measure register!]" << std::endl;

    this->isMeasured = true;
}

std::vector<double> quantum::QuantumComputer::QuantumComputer::getBaseVector() {
    return baseVector;
}