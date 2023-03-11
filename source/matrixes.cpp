#include "matrixes.h"

TridiagonalMatrix::TridiagonalMatrix(
    const std::vector<std::array<double, 3>> &data)
    : m_data{data} {}

int TridiagonalMatrix::get_size() const { return m_data.size(); }

double TridiagonalMatrix::operator()(int i, int j) const {
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

CSRMatrix::CSRMatrix(const std::map<std::pair<int, int>, double> &data) {
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

const std::vector<double> &CSRMatrix::get_values() const { return m_values; }
const std::vector<int> &CSRMatrix::get_column_indexes() const {
    return m_column_indexes;
}
const std::vector<int> &CSRMatrix::get_row_indexation() const {
    return m_row_indexation;
}

double CSRMatrix::operator()(int i, int j) const {
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

std::vector<double>
CSRMatrix::operator*(const std::vector<double> &column) const {
    std::vector<double> res;
    res.reserve(m_row_indexation.size() - 1);
    for (int k = 0; k < m_row_indexation.size() - 1; ++k) {
        double temp = 0;
        for (int i = m_row_indexation[k]; i < m_row_indexation[k + 1]; ++i) {
            temp += m_values[i] * column[m_column_indexes[i]];
        }
        res.push_back(temp);
    }
    return res;
}

DenseMatrix::DenseMatrix(const std::vector<double> &data, int columns_num)
    : m_data{data}, m_columns{columns_num}, m_rows{(data.size() + columns_num -
                                                    1) /
                                                   columns_num} {
    m_data.resize(m_columns * m_rows);
}

int DenseMatrix::get_number_of_columns() const { return m_columns; }

int DenseMatrix::get_number_of_rows() const { return m_rows; }

double DenseMatrix::operator()(int i, int j) const {
    if (i * m_columns + j >= m_data.size()) {
        return 0;
    }
    return m_data[i * m_columns + j];
}

bool DenseMatrix::operator==(const DenseMatrix &other) const {
    assert(m_data.size() == other.m_data.size() &&
           "matrixes must be the same size");
    for (int i = 0; i < m_data.size(); ++i) {
        if (m_data[i] != other.m_data[i]) {
            return false;
        }
    }
    return true;
}

void DenseMatrix::set_item(int i, int j, double value) {
    m_data[i * m_columns + j] = value;
}

std::vector<double> DenseMatrix::get_column(int i) const {
    std::vector<double> res;
    res.reserve(m_rows);
    for (int j = 0; j < m_rows; ++j) {
        res.push_back((*this)(j, i));
    }
    return res;
}

std::vector<double> DenseMatrix::get_row(int i) const {
    std::vector<double> res;
    res.reserve(m_columns);
    for (int j = 0; j < m_columns; ++j) {
        res.push_back((*this)(i, j));
    }
    return res;
}

std::vector<double>
DenseMatrix::operator*(const std::vector<double> &column) const {
    assert(m_columns == column.size() &&
           "the matrix's number of columns must be equal to column size");
    double temp;
    std::vector<double> res;
    for (int i = 0; i < m_rows; ++i) {
        temp = 0;
        for (int j = 0; j < m_columns; ++j) {
            temp += (*this)(i, j) * column[j];
        }
        res.push_back(temp);
    }
    return res;
}