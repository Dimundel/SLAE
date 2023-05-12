#include "algorithms.h"
#include "vector_operations.h"

DenseMatrix HouseholderDecompostion(const DenseMatrix &matrix) {
    DenseMatrix R = matrix;
    for (int i = 0; i < matrix.get_number_of_columns(); ++i) {
        std::vector<double> x(matrix.get_number_of_columns() - i, 0);
        for (int j = i; j < matrix.get_number_of_rows(); ++j) {
            x[j - i] = matrix(j, i);
        }
        std::vector<double> normal = x;
        if (x[0] >= 0) {
            normal[0] += length(x);
        } else {
            normal[0] -= length(x);
        }
        double alpha = dot_product(normal, x);
        double beta = dot_product(normal, normal);
        for (int j = i; j < matrix.get_number_of_columns(); ++j) {
            for (int k = i; k < matrix.get_number_of_rows(); ++k) {
                R.set_item(k, j, R(k, j) - 2 * alpha / beta * normal[k]);
            }
        }
    }
    return R;
}

std::vector<double> backGauss(const DenseMatrix &A,
                              const std::vector<double> &b) {
    std::vector<double> res = b;
    const int n = b.size();
    res[n - 1] = A(n - 1, n);
    for (int i = n - 2; i >= 0; --i) {
        res[i] = A(i, n);
        for (int j = i + 1; j < n; ++j) {
            res[j] = res[j] - res[i] * A(i, j);
        }
    }
    return res;
}

void Arnoldi_algorithm(const CSRMatrix &A, std::vector<std::vector<double>> &Q,
                       DenseMatrix &HessenbergMatrix, const int n) {
    std::vector<double> v_0 = A * Q[n];
    double h;
    for (int i = 0; i < n; ++i) {
        h = dot_product(v_0, Q[i]);
        v_0 -= h * Q[i];
        HessenbergMatrix.set_item(i, n, h);
    }
    h = length(v_0);
    HessenbergMatrix.set_item(n + 1, n, h);
    v_0 *= 1.0 / h;
}
