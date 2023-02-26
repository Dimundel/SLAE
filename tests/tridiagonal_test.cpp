#include "matrixes.h"
#include "solvers.h"
#include <gtest/gtest.h>

const TridiagonalMatrix slae1({{0, -2, 1}, {1, -2, 1}, {1, -2, 1}, {1, -2, 0}});
const TridiagonalMatrix slae2({{0, 2, 3}, {6, 3, 9}, {2, 5, 2}, {4, 3, 0}});

TEST(TridiagonalTest, CheckItemGetting) {
    EXPECT_EQ(slae1.get_item(0, 0), -2);
    EXPECT_EQ(slae1.get_item(2, 0), 0);
}

TEST(TridiagonalTest, CheckSolving) {
    const float ERROR = 0.001;

    std::vector<float> res1 = solve(slae1, {0.04, 0.04, 0.04, 0.04});
    const std::vector<float> solution1{-0.08, -0.12, -0.12, -0.08};
    for (int i = 0; i < res1.size(); ++i) {
        EXPECT_NEAR(res1[i], solution1[i], ERROR);
    }

    std::vector<float> res2 = solve(slae2, {21, 69, 34, 22});
    const std::vector<float> solution2{3, 5, 4, 2};
    for (int i = 0; i < res2.size(); ++i) {
        EXPECT_NEAR(res2[i], solution2[i], ERROR);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}