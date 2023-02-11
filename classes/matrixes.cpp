#include "matrixes.h"

TridiagonalMatrix::TridiagonalMatrix(std::vector<std::array<float, 3>> data) {
    m_data = data;
}

std::vector<float> TridiagonalMatrix::solve(std::vector<float> column) {
    int n = m_data.size() - 1;
    std::vector<float> p_vector{0}, q_vector{0};
    for (int i = 0; i < n + 1; ++i) {
        p_vector.push_back(-1 * m_data[i][2] /
                           (m_data[i][0] * p_vector[i] + m_data[i][1]));
        q_vector.push_back((column[i] - m_data[i][0] * q_vector[i]) /
                           (m_data[i][0] * p_vector[i] + m_data[i][1]));
    }
    std::vector<float> solution(n + 1);
    solution[n] = (column[n] - m_data[n][0] * q_vector[n]) /
                  (m_data[n][0] * p_vector[n] + m_data[n][1]);
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = p_vector[i + 1] * solution[i + 1] + q_vector[i + 1];
    }
    return solution;
}