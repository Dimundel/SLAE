#include "iterative_methods.h"
#include "matrixes.h"
#include "vector_operations.h"
#include <fstream>
#include <iostream>

void simple_iteration_task2(const CSRMatrix &A, const std::vector<double> &b,
                            const std::vector<double> &x0, const double t,
                            const double tolerance) {
    std::vector<double> x = x0;
    std::ofstream data("data2-2.txt");
    while (length(b - A * x) >= tolerance) {
        x = x + t * (b - A * x);
        data << x[0] / 11 << " " << x[3] / 16.5 << std::endl;
    }
    data.close();
}

void steepest_descent_iteration_task2(const CSRMatrix &A,
                                      const std::vector<double> &b,
                                      const std::vector<double> &x0,
                                      const double tolerance) {
    std::vector<double> x = x0;
    std::vector<double> residual = A * x - b;
    double alpha;
    std::ofstream data("data2-3.txt");
    while (length(residual) > tolerance) {
        alpha = dot_product(residual, residual) /
                (dot_product(residual, A * residual));
        x = x - alpha * residual;
        data << x[0] / 11 << " " << x[3] / 16.5 << std::endl;
        residual = A * x - b;
    }
    data.close();
}

void accelerated_simple_iteration_task2(const CSRMatrix &A,
                                        const std::vector<double> &b,
                                        const std::vector<double> &x0,
                                        const double l, const double L,
                                        const double tolerance) {
    const int order = 8;
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

    std::ofstream data("data2-4.txt");
    std::vector<double> iter_order{1, 8, 4, 5, 2, 7, 3, 6};
    std::vector<double> x = x0;
    while (length(b - A * x) >= tolerance) {
        for (int i = 0; i < order; ++i) {
            x = x + tau_vector[iter_order[i] - 1] * (b - A * x);
            data << x[0] / 11 << " " << x[3] / 16.5 << std::endl;
        }
    }
    data.close();
}

void conjugate_gradients_task2(const CSRMatrix &A,
                                        const std::vector<double> &b,
                                        const std::vector<double> &x0,
                                        const double tolerance) {
    std::vector<double> x = x0;
    std::vector<double> residual = A * x - b;
    std::vector<double> d = residual;
    std::vector<double> residual_next;
    double alpha, beta;
    std::ofstream data("data2-5.txt");
    while (length(residual) > tolerance) {
        alpha = dot_product(residual, residual) / dot_product(d, A * d);
        x -= alpha * d;
        residual_next = residual - alpha * (A * d);
        if (length(d) == 0) {
            break;
        } else {
            beta = dot_product(residual_next, residual_next) /
                   dot_product(residual, residual);
            d = residual_next + beta * d;
        }
        residual = residual_next;
        data << x[0] / 11 << " " << x[3] / 16.5 << std::endl;
    }
    data.close();
}

int main() {
    const CSRMatrix A({{{0, 0}, 22}, {{1, 1}, 24}, {{2, 2}, 28}, {{3, 3}, 33}});
    const std::vector<double> b{1, 1, 1, 1};
    const std::vector<double> c{5, 5, 5, 5};
    const std::vector<double> x0{0, 0, 0, 0};

    conjugate_gradients_task2(A, b, x0, 1e-14);
}