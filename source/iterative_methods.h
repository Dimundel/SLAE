#include "matrixes.h"
#include <cmath>

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

std::vector<double> accelerated_simple_iteration(const CSRMatrix &A,
                                                 const std::vector<double> &b,
                                                 const std::vector<double> &x0,
                                                 const double l, const double L,
                                                 const double tolerance);

std::vector<double> SOR_iteration(const CSRMatrix &A,
                                  const std::vector<double> &b,
                                  const std::vector<double> &x0, const double w,
                                  const double tolerance);

std::vector<double> symmetric_gauss_seidel_iteration(
    const CSRMatrix &A, const std::vector<double> &b,
    const std::vector<double> &x0, const double tolerance);

std::vector<double>
symmetric_gauss_seidel_one_iteration(const CSRMatrix &A,
                                     const std::vector<double> &b,
                                     const std::vector<double> &x0);

std::vector<double> accelerated_symmetric_gauss_seidel_iteration(
    const CSRMatrix &A, const std::vector<double> &b,
    const std::vector<double> &x0, const double rho, const double tolerance);

std::vector<double> steepest_descent_iteration(const CSRMatrix &A,
                                               const std::vector<double> &b,
                                               const std::vector<double> &x0,
                                               const double tolerance);

std::vector<double> conjugate_gradients(const CSRMatrix &A,
                                        const std::vector<double> &b,
                                        const std::vector<double> &x0,
                                        const double tolerance);