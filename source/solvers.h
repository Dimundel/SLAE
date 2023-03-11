#include "matrixes.h"

#ifndef SOLVERS_H
#define SOLVERS_H

std::vector<float> solve(const TridiagonalMatrix &matrix,
                         const std::vector<float> &column);

#endif