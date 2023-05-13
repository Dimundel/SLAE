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
    std::vector<std::array<double, 3>> m_data;

public:
    TridiagonalMatrix(const std::vector<std::array<double, 3>> &data);
    int get_size() const;
    double operator()(int i, int j) const;
};

class CSRMatrix {
private:
    std::vector<double> m_values;
    std::vector<int> m_column_indexes, m_row_indexation;

public:
    CSRMatrix(const std::map<std::pair<int, int>, double> &data);
    const std::vector<double> &get_values() const;
    const std::vector<int> &get_column_indexes() const;
    const std::vector<int> &get_row_indexation() const;
    double operator()(int i, int j) const;
    std::vector<double> operator*(const std::vector<double> &column) const;
};

class DenseMatrix {
private:
    std::vector<double> m_data;
    int m_columns, m_rows;

public:
    DenseMatrix(const std::vector<double> &data, const int num_columns);
    DenseMatrix(const int num_rows, const int num_columns);
    int get_number_of_columns() const;
    int get_number_of_rows() const;
    double operator()(int i, int j) const;
    bool operator==(const DenseMatrix &other) const;
    void set_item(int i, int j, double value);
    std::vector<double> get_column(int i) const;
    std::vector<double> get_row(int i) const;
    std::vector<double> operator*(const std::vector<double> &column) const;
};

#endif