#include <iostream>
#include "headers/qubitOperation.h"
#include "headers/matrixOperation.h"

vector2d getPreparedContainerForQubit(int qubitRows) {
    vector2d vector;
    vector.resize(qubitRows);
    for (int i = 0; i < qubitRows; i++) {
        vector[i].resize(QUBIT_NUMBER_OF_COLUMNS);
    }

    return vector;
}

vector2d getPreparedContainerForDotProduct() {
    vector2d vector;
    vector.resize(QUBIT_NUMBER_OF_COLUMNS);
    for (int i = 0; i < QUBIT_NUMBER_OF_COLUMNS; i++) {
        vector[i].resize(QUBIT_NUMBER_OF_COLUMNS);
    }

    return vector;
}

vector2d makeDotProductOfQubits(vector2d transposedAndConjugatedQubit, vector2d qubit) {
    vector2d dotProduct = getPreparedContainerForDotProduct();

    complex<double> sum = complex<double>(0, 0);
    for (int i = 0; i < qubit.size(); i++) {
        for (int j = 0; j < qubit[i].size(); j++) {
            sum += qubit.at(i).at(j) * transposedAndConjugatedQubit.at(j).at(i);
        }
    }
    dotProduct[0][0] = sum;

    return dotProduct;
}

/// Helper function used to convert qubit as vector to two dimensional vector
/// and change type from double to complex<double>
/// \param baseVector vector<double>
/// \return complex two dimensional vector
vector2d convertBaseVectorTo2dVector(vector<double> baseVector) {
    vector2d complexDoubleVector;

    for (int i = 0; i < baseVector.size(); i++) {
        vector<complex<double>> temp;
        for (int j = 0; j < QUBIT_NUMBER_OF_COLUMNS; j++) {
            temp.push_back(baseVector.at(i));
        }
        complexDoubleVector.push_back(temp);
    }

    return complexDoubleVector;
}

vector2d getQubitRepresentation(vector<double> baseVector) {
    return convertBaseVectorTo2dVector(baseVector);
}

/// Used to show single formatted element of qubit
/// \param element complex<double>
void showSingleQubitElement(complex<double> element) {
    if (imag(element) == 0) {
        cout << real(element) << " ";
    }
    else if (real(element) == 0 && imag(element) == 1) {
        cout << "i ";
    }
    else if (real(element) == 0 && imag(element) == -1) {
        cout << "-i ";
    }
    else if (real(element) == 0) {
        cout << imag(element) << "i ";
    }
    else {
        if (imag(element) > 0) {
            cout << real(element) << "+" << imag(element) << "i ";
        }
        else {
            cout << real(element) << imag(element) << "i ";
        }
    }
}

void showQubit(vector2d qubit) {
    for (int i = 0; i < qubit.size(); i++) {
        for (int j = 0; j < qubit[i].size(); j++) {
            showSingleQubitElement(qubit[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void showDotProduct(vector2d dotProduct) {
    for (int i = 0; i < dotProduct.size(); i++) {
        for (int j = 0; j < dotProduct.size(); j++) {
            showSingleQubitElement(dotProduct[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
