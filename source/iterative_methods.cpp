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
    std::vector<float> x;
    x = x0;
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