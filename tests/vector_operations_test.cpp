#include "vector_operations.h"
#include <gtest/gtest.h>

const std::vector<double> vec1 = {4, 2, 3, -2};
const std::vector<double> vec2 = {-3, 7, 0, 5};

TEST(VectorOperationsTest, CheckVectorAddition) {
    const std::vector<double> res1 = {1, 9, 3, 3};
    ASSERT_EQ(vec1 + vec2, res1);
    const std::vector<double> res2 = {7, -5, 3, -7};
    ASSERT_EQ(vec1 - vec2, res2);
    std::vector<double> vec3 = {-4, 12, -3, 1};
    const std::vector<double> res3 = {0, 14, 0, -1};
    ASSERT_EQ(vec3 += vec1, res3);
    std::vector<double> vec4 = {-3, 5, -2, -1};
    const std::vector<double> res4 = {0, -2, -2, -6};
    ASSERT_EQ(vec4 -= vec2, res4);
}

TEST(VectorOperationsTest, CheckVectorNumberMultiplication) {
    const std::vector<double> res5 = {12, 6, 9, -6};
    ASSERT_EQ(vec1 * 3, res5);
    const std::vector<double> res6 = {-12, 28, 0, 20};
    ASSERT_EQ(4 * vec2, res6);
    std::vector<double> vec5 = {2, -3, 1, 4};
    const std::vector<double> res7 = {-4, 6, -2, -8};
    ASSERT_EQ(vec5 *= -2, res7);
}

TEST(VectorOperationsTest, CheckVectorDotProduct) {
    EXPECT_EQ(dot_product(vec1, vec2), -8);
}

TEST(VectorOperationsTest, CheckVectorLength) {
    std::vector<double> vec{3, 4, 12};
    EXPECT_EQ(length(vec), 13);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}