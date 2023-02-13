#include "matrixes.h"
#include <vector>

std::vector<float> solve(const TridiagonalMatrix &matrix, std::vector<float> column) {
    int n = matrix.get_size() - 1;
    std::vector<float> p_vector{0}, q_vector{0};
    for (int i = 0; i < n + 1; ++i) {
        p_vector.push_back(
            -1 * matrix.get_item(i, i + 1) /
            (matrix.get_item(i, i - 1) * p_vector[i] + matrix.get_item(i, i)));
        q_vector.push_back(
            (column[i] - matrix.get_item(i, i - 1) * q_vector[i]) /
            (matrix.get_item(i, i - 1) * p_vector[i] + matrix.get_item(i, i)));
    }
    column[n] =
        (column[n] - matrix.get_item(n, n - 1) * q_vector[n]) /
        (matrix.get_item(n, n - 1) * p_vector[n] + matrix.get_item(n, n));
    for (int i = n - 1; i >= 0; --i) {
        column[i] = p_vector[i + 1] * column[i + 1] + q_vector[i + 1];
    }
    return column;
}