#include "vector_operations.h"
#include <gtest/gtest.h>

const std::vector<float> vec1 = {4, 2, 3, -2};
const std::vector<float> vec2 = {-3, 7, 0, 5};
std::vector<float> vec3 = {-4, 12, -3, 1};
std::vector<float> vec4 = {-3, 5, -2, -1};
std::vector<float> vec5 = {2, -3, 1, 4};
const std::vector<float> res1 = {1, 9, 3, 3};
const std::vector<float> res2 = {7, -5, 3, -7};
const std::vector<float> res3 = {0, 14, 0, -1};
const std::vector<float> res4 = {0, -2, -2, -6};
const std::vector<float> res5 = {12, 6, 9, -6};
const std::vector<float> res6 = {-4, 6, -2, -8};
const std::vector<float> res7 = {-12, 28, 0, 20};

TEST(VectorOperationsTest, CheckVectorAddition) {
    ASSERT_EQ(vec1 + vec2, res1);
    ASSERT_EQ(vec1 - vec2, res2);
    ASSERT_EQ(vec3 += vec1, res3);
    ASSERT_EQ(vec4 -= vec2, res4);
}

TEST(VectorOperationTest, CheckVectorNumberMultiplication) {
    ASSERT_EQ(vec1 * 3, res5);
    ASSERT_EQ(4 * vec2, res7);
    ASSERT_EQ(vec5 *= -2, res6);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}