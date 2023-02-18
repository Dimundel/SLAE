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

CSRMatrix::CSRMatrix(const std::map<std::pair<int, int>, float> &data) {
    m_row_indexation.push_back(0);
    int row_indexation = 0;
    for (auto it = data.cbegin(); it != data.end(); ++it) {
        m_values.push_back(it->second);
        m_column_indexes.push_back(it->first.second);
        ++row_indexation;
        if (std::next(it, 1)->first.first != it->first.first) {
            m_row_indexation.push_back(row_indexation);
        }
    }
}

const std::vector<float> &CSRMatrix::get_values() const { return m_values; }
const std::vector<int> &CSRMatrix::get_column_indexes() const {
    return m_column_indexes;
}
const std::vector<int> &CSRMatrix::get_row_indexation() const {
    return m_row_indexation;
}