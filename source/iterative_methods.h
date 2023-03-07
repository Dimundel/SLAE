#include "matrixes.h"

std::vector<float> simple_iteration(const CSRMatrix &A,
                                    const std::vector<float> &b,
                                    const std::vector<float> &x0, const float t,
                                    const float tolerance);

std::vector<float> jacobi_iteration(const CSRMatrix &A,
                                    const std::vector<float> &b,
                                    const std::vector<float> &x0,
                                    const float tolerance);