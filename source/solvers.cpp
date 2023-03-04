#include "matrixes.h"
#include <vector>

std::vector<float> solve(const TridiagonalMatrix &matrix, const std::vector<float> &column) {
    int n = matrix.get_size() - 1;
    std::vector<float> p_vector{0}, q_vector{0};
    p_vector.reserve(matrix.get_size());
    q_vector.reserve(matrix.get_size());
    for (int i = 0; i < n + 1; ++i) {
        p_vector.push_back(
            -1 * matrix(i, i + 1) /
            (matrix(i, i - 1) * p_vector[i] + matrix(i, i)));
        q_vector.push_back(
            (column[i] - matrix(i, i - 1) * q_vector[i]) /
            (matrix(i, i - 1) * p_vector[i] + matrix(i, i)));
    }
    std::vector<float> solution(n+1);
    solution[n] =
        (column[n] - matrix(n, n - 1) * q_vector[n]) /
        (matrix(n, n - 1) * p_vector[n] + matrix(n, n));
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = p_vector[i + 1] * solution[i + 1] + q_vector[i + 1];
    }
    return solution;
}