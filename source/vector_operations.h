#include <cassert>
#include <vector>

#ifndef VECTOR_OPERATIONS_H
#define VECTOR_OPERATIONS_H
std::vector<float> &operator+=(std::vector<float> &vec1,
                               const std::vector<float> &vec2);

std::vector<float> operator+(const std::vector<float> &vec1,
                             const std::vector<float> &vec2);

std::vector<float> &operator-=(std::vector<float> &vec1,
                               const std::vector<float> &vec2);

std::vector<float> operator-(const std::vector<float> &vec1,
                             const std::vector<float> &vec2);

std::vector<float> &operator*=(std::vector<float> &vec, const int num);

std::vector<float> operator*(const std::vector<float> &vec, const int num);

std::vector<float> operator*(const int num, const std::vector<float> &vec);

int dot_product(const std::vector<float> vec1, const std::vector<float> vec2);

#endif