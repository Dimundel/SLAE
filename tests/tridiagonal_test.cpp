#include "matrixes.h"
#include "solvers.h"
#include <gtest/gtest.h>

const float ERROR = 0.001;

const TridiagonalMatrix slae1({{0, -2, 1}, {1, -2, 1}, {1, -2, 1}, {1, -2, 0}});
const std::vector<float> column1{0.04, 0.04, 0.04, 0.04};
const std::vector<float> solution1{-0.08, -0.12, -0.12, -0.08};

const TridiagonalMatrix slae2({{0, 2, 3}, {6, 3, 9}, {2, 5, 2}, {4, 3, 0}});
const std::vector<float> column2{21, 69, 34, 22};
const std::vector<float> solution2{3, 5, 4, 2};

TEST(TridiagonalTest, CheckSolution1) {
    std::vector<float> res = solve(slae1, column1);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(TridiagonalTest, CheckSolution2) {
    std::vector<float> res = solve(slae2, column2);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution2[i], ERROR);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}