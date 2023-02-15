#include "matrixes.h"

TridiagonalMatrix::TridiagonalMatrix(
    const std::vector<std::array<float, 3>> &data) {
    m_data = data;
}

int TridiagonalMatrix::get_size() const { return m_data.size(); }

float TridiagonalMatrix::get_item(int i, int j) const {
    if (j == i - 1) {
        return m_data[i][0];
    } else if (j == i) {
        return m_data[i][1];
    } else if (j == i + 1) {
        return m_data[i][2];
    } else {
        return 0;
    }
}