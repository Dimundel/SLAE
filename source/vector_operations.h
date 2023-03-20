#include <cassert>
#include <cmath>
#include <vector>

#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H
std::vector<double> &operator+=(std::vector<double> &vec1,
                                const std::vector<double> &vec2);

std::vector<double> operator+(const std::vector<double> &vec1,
                              const std::vector<double> &vec2);

std::vector<double> &operator-=(std::vector<double> &vec1,
                                const std::vector<double> &vec2);

std::vector<double> operator-(const std::vector<double> &vec1,
                              const std::vector<double> &vec2);

std::vector<double> &operator*=(std::vector<double> &vec, const int num);

std::vector<double> operator*(const std::vector<double> &vec, const int num);

std::vector<double> operator*(const int num, const std::vector<double> &vec);

double dot_product(const std::vector<double> &vec1,
                   const std::vector<double> &vec2);

double length(const std::vector<double> &vec);

#endif