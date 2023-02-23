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
    m_values.reserve(data.size());
    m_column_indexes.reserve(data.size());
    m_row_indexation.reserve(data.size());
    m_row_indexation.push_back(0);
    int row_indexation = 0;
    for (auto it = data.cbegin(); it != data.end(); ++it) {
        m_values.push_back(it->second);
        m_column_indexes.push_back(it->first.second);
        ++row_indexation;
        for (int i = it->first.first; i < std::next(it, 1)->first.first; ++i) {
            m_row_indexation.push_back(row_indexation);
            if (std::next(it, 1) == data.cend()) {
                break;
            }
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
float CSRMatrix::get_item(int i, int j) const {
    if (i + 1 >= m_column_indexes.size()) {
        return 0;
    }
    for (int k = m_row_indexation[i]; k <= m_row_indexation[i + 1]; ++k) {
        if (m_column_indexes[k] == j) {
            return m_values[k];
        }
    }
    return 0;
}

std::vector<float>
CSRMatrix::operator*(const std::vector<float> &column) const {
    std::vector<float> res;
    res.reserve(m_row_indexation.size() - 1);
    for (int k = 0; k < m_row_indexation.size() - 1; ++k) {
        float temp = 0;
        for (int i = m_row_indexation[k]; i < m_row_indexation[k + 1]; ++i) {
            temp += m_values[i] * column[m_column_indexes[i]];
        }
        res.push_back(temp);
    }
    return res;
}

DenseMatrix::DenseMatrix(const std::vector<float> &data, int m) {
    m_data = data;
    m_columns = m;
}

float DenseMatrix::get_item(int i, int j) const {
    if (i * m_columns + j >= m_data.size()) {
        return 0;
    }
    return m_data[i * m_columns + j];
}

std::vector<float> DenseMatrix::operator*(const std::vector<float> &column) const {
    assert(m_columns == column.size() &&
           "the matrix's number of columns must be equal to column size");
    int rows = (m_data.size() + (m_columns - 1)) / m_columns;
    float temp;
    std::vector<float> res;
    for(int i = 0; i < rows; ++i){
        temp = 0;
        for(int j = 0; j < m_columns; ++j){
            temp += get_item(i, j) * column[j];
        }
        res.push_back(temp);
    }
    return res;
}