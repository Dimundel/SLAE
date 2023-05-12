#include "matrixes.h"

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

struct DecompositionQR {
    DenseMatrix Q;
    DenseMatrix R;
};

DenseMatrix HouseholderDecompostion(const DenseMatrix &matrix);

std::vector<double> backGauss(const DenseMatrix &A,
                              const std::vector<double> &b);

void Arnoldi_algorithm(const CSRMatrix &A, std::vector<std::vector<double>> &Q,
                       DenseMatrix &HessenbergMatrix, const int n);

#endif