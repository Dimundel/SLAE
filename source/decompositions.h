#include "matrixes.h"

#ifndef DECOMPOSITIONS_H
#define DECOMPOSITIONS_H

struct DecompositionQR {
    DenseMatrix Q;
    DenseMatrix R;
};

DenseMatrix HouseholderDecompostion(const DenseMatrix &matrix);

#endif