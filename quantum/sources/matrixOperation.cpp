#include <iostream>
#include <iomanip>
#include <vector>
#include "../headers/matrixOperation.h"

vector2d getPreparedVectorForHermitianMatrix(int dimension) {
    vector2d vector;
    vector.resize(dimension);
    for (int i = 0; i < dimension; i++) {
        vector[i].resize(dimension);
    }

    return vector;
}

vector2d getRandomHermitianMatrix(int dimension) {
    complex<double> number;
    vector2d outputMatrix = getPreparedVectorForHermitianMatrix(dimension);

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            number = complex<double>(static_cast<double> (rand() % 10),static_cast<double> (rand() % 10));
            outputMatrix[i][j] = number;
            outputMatrix[j][i] = conj(number);
            if (i == j) {
                outputMatrix[i][j] = real(outputMatrix[i][j]);
            }
        }
    }

    return outputMatrix;
}

vector2d makeConjugateTranspose(vector2d matrix) {
    vector2d outputMatrix(matrix[0].size(), vector<complex<double>>(matrix.size()));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            outputMatrix[j][i] = conj(matrix[i][j]);
        }
    }

    return outputMatrix;
}

/// Used to show single formatted element of matrix
/// \param element complex<double>
void showSingleMatrixElement(complex<double> element) {
    if (imag(element) == 0) {
        cout << setw(6) << real(element) << " " << setw(4);
    }
    else if (real(element) == 0) {
        cout << setw(6) << imag(element) << "i" << setw(4);
    }
    else {
        if (imag(element) > 0) {
            cout << setw(4) << real(element) << "+" << imag(element) << "i" << setw(6);
        }
        else {
            cout << setw(4) << real(element) << imag(element) << "i" << setw(6);
        }
    }
}

void showMatrix(vector2d matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            showSingleMatrixElement(matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
