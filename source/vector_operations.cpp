#include "vector_operations.h"

std::vector<double> &operator+=(std::vector<double> &vec1,
                                const std::vector<double> &vec2) {
    assert(vec1.size() == vec2.size() && "vectors must be the same size");
    for (int i = 0; i < vec1.size(); ++i) {
        vec1[i] += vec2[i];
    }
    return vec1;
}

std::vector<double> operator+(const std::vector<double> &vec1,
                              const std::vector<double> &vec2) {
    std::vector<double> vec_res(vec1);
    vec_res += vec2;
    return vec_res;
}

std::vector<double> &operator-=(std::vector<double> &vec1,
                                const std::vector<double> &vec2) {
    vec1 += vec2 * (-1);
    return vec1;
}

std::vector<double> operator-(const std::vector<double> &vec1,
                              const std::vector<double> &vec2) {
    std::vector<double> vec_res(vec1);
    vec_res -= vec2;
    return vec_res;
}

std::vector<double> &operator*=(std::vector<double> &vec, const int num) {
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] *= num;
    }
    return vec;
}

std::vector<double> operator*(const std::vector<double> &vec, const int num) {
    std::vector<double> vec_res(vec);
    vec_res *= num;
    return vec_res;
}

std::vector<double> operator*(const int num, const std::vector<double> &vec) {
    return vec * num;
}

double dot_product(const std::vector<double> vec1,
                   const std::vector<double> vec2) {
    assert(vec1.size() == vec2.size() && "vectors must be the same size");
    int res = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        res += vec1[i] * vec2[i];
    }
    return res;
}

double length(const std::vector<double> vec) {
    return std::sqrt(dot_product(vec, vec));
}