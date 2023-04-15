#include "iterative_methods.h"
#include "vector_operations.h"
#include <fstream>
#include <vector>

void simple_iteration_task3(const CSRMatrix &A, const std::vector<double> &b,
                            const std::vector<double> &x0) {
    std::ofstream file("data3");
    int count;
    std::vector<double> x;
    for (double t = 0.01; t < 5; t += 0.01) {
        count = 0;
        x = x0;
        while (length(b - A * x) >= 1e-12) {
            x = x + t * (b - A * x);
            ++count;
        }
        file << t << " " << count << std::endl;
    }
}

void simple_iteration_task4(const CSRMatrix &A, const std::vector<double> &b,
                            const std::vector<double> &x0, const double t) {
    std::ofstream file("data4_simple_iterative");
    std::vector<double> x = x0;
    for (int count = 1; count <= 10000; ++count) {
        x = x + t * (b - A * x);
        file << count << " " << std::log(length(b - A * x)) << std::endl;
    }
}

void jacobi_iteration_task4(const CSRMatrix &A, const std::vector<double> &b,
                            const std::vector<double> &x0) {
    std::ofstream file("data4_jacobi");
    std::vector<double> x = x0;
    std::vector<double> x_next(b.size());
    for (int count = 1; count <= 10000; ++count) {
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
        file << count << " " << std::log(length(b - A * x)) << std::endl;
    }
}

void gauss_seidel_iteration_task4(const CSRMatrix &A,
                                  const std::vector<double> &b,
                                  const std::vector<double> &x0) {
    std::ofstream file("data4_gauss_seidel");
    std::vector<double> x = x0;
    for (int count = 1; count <= 10000; ++count) {
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
        file << count << " " << std::log(length(b - A * x)) << std::endl;
    }
}

int main() {
    CSRMatrix A({{{0, 0}, 10},
                 {{0, 1}, 1},
                 {{1, 0}, 1},
                 {{1, 1}, 7},
                 {{2, 1}, 0.1},
                 {{2, 2}, 1}});
    std::vector<double> x0 = {0, 0, 0};
    std::vector<double> b = {20, 30, 1};
    simple_iteration_task3(A, b, x0);

    CSRMatrix A2({{{0, 0}, 12},
                  {{0, 1}, 17},
                  {{0, 2}, 3},
                  {{1, 0}, 17},
                  {{1, 1}, 15825},
                  {{1, 2}, 28},
                  {{2, 0}, 3},
                  {{2, 1}, 28},
                  {{2, 2}, 238}});
    std::vector<double> x02 = {1, 1, 1};
    std::vector<double> b2 = {1, 2, 3};
    simple_iteration_task4(A2, b2, x02, 0.00012);
    jacobi_iteration_task4(A2, b2, x02);
    gauss_seidel_iteration_task4(A2, b2, x02);
}