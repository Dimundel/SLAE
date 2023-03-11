#include "iterative_methods.h"
#include "vector_operations.h"

std::vector<double> simple_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double t, const double tolerance) {
    std::vector<double> x = x0;
    while (length(b - (A * x)) >= tolerance) {
        x = x - t * (A * x - b);
    }
    return x;
}

std::vector<double> jacobi_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double tolerance) {
    std::vector<double> x = x0;
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < b.size(); ++i) {
            double temp = 0;
            for (int j = 0; j < b.size(); ++j) {
                if (i == j) {
                    continue;
                }
                temp += A(i, j) * x[j];
            }
            x[i] = (b[i] - temp) / A(i, i);
        }
    }
    return x;
}

std::vector<double> gauss_seidel_iteration(const CSRMatrix &A,
                                           const std::vector<double> &b,
                                           const std::vector<double> &x0,
                                           const double tolerance) {
    std::vector<double> x = x0;
    std::vector<double> x_next = x0;
    x_next.resize(b.size());
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < b.size(); ++i) {
            x_next[i] = b[i];
            for (int j = 0; j < i; ++j) {
                x_next[i] -= A(i, j) * x_next[j];
            }
            for (int j = i + 1; j < b.size(); ++j) {
                x_next[i] -= A(i, j) * x[j];
            }
            x_next[i] /= A(i, i);
        }
        x = x_next;
    }
    return x;
}