#include "iterative_methods.h"
#include "matrixes.h"
#include "vector_operations.h"
#include <fstream>
#include <iostream>

void simple_iteration_task1(const CSRMatrix &A, const std::vector<double> &b,
                            const std::vector<double> &x0, const double t,
                            const int max_count) {

    std::ofstream data("data1-2.txt");
    std::vector<double> x = x0;
    for (int i = 0; i < max_count; ++i) {
        x = x + t * (b - A * x);
        data << i << " " << length(b - A * x) << std::endl;
    }
    data.close();
}

int accelerated_simple_iteration_task3(const CSRMatrix &A,
                                       const std::vector<double> &b,
                                       const std::vector<double> &x0,
                                       const double l, const double L,
                                       double tolerance) {
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

    std::vector<double> iter_order{1, 8, 4, 5, 2, 7, 3, 6};
    std::vector<double> x = x0;
    int j = 0;
    while (length(b - A * x) > tolerance) {
        for (int i = 0; i < order; ++i) {
            x = x + tau_vector[iter_order[i] - 1] * (b - A * x);
            ++j;
        }
    }
    return j;
}

std::vector<double> symmetric_gauss_seidel_iteration_task3(
    const CSRMatrix &A, const std::vector<double> &b,
    const std::vector<double> &x0, const int max_count) {
    std::vector<double> x = x0;
    std::ofstream data("data1-4.txt");
    for (int k = 0; k < max_count; ++k) {
        for (int i = 0; i < b.size(); ++i) {
            x[i] = b[i];
            for (int j = 0; j < b.size(); ++j) {
                if (i == j) {
                    continue;
                }
                x[i] -= A(i, j) * x[j];
            }
            x[i] /= A(i, i);
        }
        for (int i = A.get_row_indexation().size() - 2; i >= 0; --i) {
            x[i] = b[i];
            for (int j = 0; j < b.size(); ++j) {
                if (i == j) {
                    continue;
                }
                x[i] -= A(i, j) * x[j];
            }
            x[i] /= A(i, i);
        }
        data << k << " " << length(b - A * x) << std::endl;
    }
    data.close();
    return x;
}

int main() {
    std::map<std::pair<int, int>, double> nums;
    std::vector<double> b(324, 4);
    std::vector<double> x0(324, 0);
    for (int i = 0; i < 324; ++i) {
        nums.insert({{i, i}, 12});
    }
    for (int i = 0; i < 162; ++i) {
        nums.insert({{i, i + 162}, 1});
        nums.insert({{i + 162, i}, 1});
        nums.insert({{i + 162, i}, 1});
        nums.insert({{i, i + 162}, 1});
    }
    CSRMatrix A(nums);
    std::ofstream data("data1-5.txt");
    for (double L = 10.0; L < 50.0; L += 0.1) {
        data << L << " "
             << accelerated_simple_iteration_task3(A, b, x0, 4.000008328, L,
                                                   1e-14)
             << std::endl;
    }
}