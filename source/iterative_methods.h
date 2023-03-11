#include "matrixes.h"

std::vector<double> simple_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double t, const double tolerance);

std::vector<double> jacobi_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0,
                                     const double tolerance);

std::vector<double> gauss_seidel_iteration(const CSRMatrix &A,
                                           const std::vector<double> &b,
                                           const std::vector<double> &x0,
                                           const double tolerance);