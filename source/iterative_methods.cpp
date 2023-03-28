#include "iterative_methods.h"
#include "vector_operations.h"

std::vector<double> simple_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double t, const double tolerance) {
    std::vector<double> x = x0;
    while (length(b - A * x) >= tolerance) {
        x = x + t * (b - A * x);
    }
    return x;
}

std::vector<double> jacobi_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double tolerance) {
    std::vector<double> x = x0;
    std::vector<double> x_next(b.size());
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < b.size(); ++i) {
            double temp = b[i];
            for (int j = 0; j < b.size(); ++j) {
                if (i == j) {
                    continue;
                }
                temp -= A(i, j) * x[j];
            }
            x_next[i] = temp / A(i, i);
        }
        x = x_next;
    }
    return x;
}

std::vector<double> gauss_seidel_iteration(const CSRMatrix &A,
                                           const std::vector<double> &b,
                                           const std::vector<double> &x0,
                                           const double tolerance) {
    std::vector<double> x = x0;
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < b.size(); ++i) {
            x[i] = b[i];
            for (int j = 0; j < i; ++j) {
                x[i] -= A(i, j) * x[j];
            }
            for (int j = i + 1; j < b.size(); ++j) {
                x[i] -= A(i, j) * x[j];
            }
            x[i] /= A(i, i);
        }
    }
    return x;
}

std::vector<double> accelerated_simple_iteration(const CSRMatrix &A,
                                                 const std::vector<double> &b,
                                                 const std::vector<double> &x0,
                                                 const double l, const double L,
                                                 const double tolerance) {
    const int order = 16;
    double cosB = std::cos(M_PI / (2 * order));
    double sinB = std::sin(M_PI / (2 * order));
    const double cosA = std::cos(M_PI / order);
    const double sinA = std::sin(M_PI / order);
    const double half_sum = (L + l) / 2;
    const double half_diff = (L - l) / 2;
    std::vector<double> tau_vector;
    tau_vector.reserve(order);
    tau_vector.push_back(1 / (half_sum + half_diff * cosB));

    double cosB_next;
    double sinB_next;

    for (int j = 1; j <= order; ++j) {
        cosB_next = cosA * cosB - sinA * sinB;
        sinB_next = cosA * sinB + sinA * cosB;
        cosB = cosB_next;
        sinB = sinB_next;
        tau_vector.push_back(1 / (half_sum + half_diff * cosB));
    }

    std::vector<double> iter_order{1, 16, 8, 9,  4, 13, 5, 12,
                                   2, 15, 7, 10, 3, 14, 6, 11};
    std::vector<double> x = x0;
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < order; ++i) {
            x = x + tau_vector[iter_order[i] - 1] * (b - A * x);
        }
    }
    return x;
}