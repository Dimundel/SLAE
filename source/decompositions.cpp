#include "decompositions.h"
#include "vector_operations.h"

DenseMatrix HouseholderDecompostion(const DenseMatrix &matrix) {
    DenseMatrix R = matrix;
    for (int i = 0; i < matrix.get_number_of_columns(); ++i) {
        std::vector<float> x(matrix.get_number_of_columns() - i, 0);
        for (int j = i; j < matrix.get_number_of_rows(); ++j) {
            x[j - i] = matrix(j, i);
        }
        std::vector<float> normal = x;
        if (x[0] >= 0) {
            normal[0] += length(x);
        } else {
            normal[0] -= length(x);
        }
        float alpha = dot_product(normal, x);
        float beta = dot_product(normal, normal);
        for (int j = i; j < matrix.get_number_of_columns(); ++j) {
            for (int k = i; k < matrix.get_number_of_rows(); ++k) {
                R.set_item(k, j, R(k, j) - 2 * alpha / beta * normal[k]);
            }
        }
    }
    return R;
}
