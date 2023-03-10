#include "iterative_methods.h"
#include "vector_operations.h"

std::vector<float> simple_iteration(const CSRMatrix &A,
                                    const std::vector<float> &b,
                                    const std::vector<float> &x0, const float t,
                                    const float tolerance) {
    std::vector<float> x = x0;
    while (length(b - (A * x)) >= tolerance) {
        x = x - t * (A * x - b);
    }
    return x;
}

std::vector<float> jacobi_iteration(const CSRMatrix &A,
                                    const std::vector<float> &b,
                                    const std::vector<float> &x0,
                                    const float tolerance) {
    std::vector<float> x = x0;
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < b.size(); ++i) {
            float temp = 0;
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

std::vector<float> gauss_seidel_iteration(const CSRMatrix &A,
                                          const std::vector<float> &b,
                                          const std::vector<float> &x0,
                                          const float tolerance) {
    std::vector<float> x = x0;
    std::vector<float> x_next = x0;
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