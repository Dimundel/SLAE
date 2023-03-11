#include "matrixes.h"

#ifndef SOLVERS_H
#define SOLVERS_H

std::vector<double> solve(const TridiagonalMatrix &matrix,
                          const std::vector<double> &column);

#endif