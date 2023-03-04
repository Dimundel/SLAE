#include <array>
#include <cassert>
#include <cmath>
#include <iterator>
#include <map>
#include <vector>

#ifndef MATRIXES_H
#define MATRIXES_H

class TridiagonalMatrix {
private:
    std::vector<std::array<float, 3>> m_data;

public:
    TridiagonalMatrix(const std::vector<std::array<float, 3>> &data);
    int get_size() const;
    float operator()(int i, int j) const;
};

class CSRMatrix {
private:
    std::vector<float> m_values;
    std::vector<int> m_column_indexes, m_row_indexation;

public:
    CSRMatrix(const std::map<std::pair<int, int>, float> &data);
    const std::vector<float> &get_values() const;
    const std::vector<int> &get_column_indexes() const;
    const std::vector<int> &get_row_indexation() const;
    float operator()(int i, int j) const;
    std::vector<float> operator*(const std::vector<float> &column) const;
};

class DenseMatrix {
private:
    std::vector<float> m_data;
    int m_columns, m_rows;

public:
    DenseMatrix(const std::vector<float> &data, int m);
    int get_number_of_columns() const;
    int get_number_of_rows() const;
    float operator()(int i, int j) const;
    void set_item(int i, int j, float value);
    std::vector<float> get_column(int i) const;
    std::vector<float> get_row(int i) const;
    std::vector<float> operator*(const std::vector<float> &column) const;
};

#endif