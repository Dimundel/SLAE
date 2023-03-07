#include "iterative_methods.h"
#include "matrixes.h"
#include <gtest/gtest.h>

const CSRMatrix slae1({{{0, 0}, 10},
                       {{0, 1}, 1},
                       {{1, 0}, 1},
                       {{1, 1}, 7},
                       {{2, 1}, 0.1},
                       {{2, 2}, 1}});
std::vector<float> b = {20.0, 30.0, 1.0};
std::vector<float> x0 = {0.0, 0.0, 0.0};
std::vector<float> solution1 = {110.0 / 69, 280.0 / 69, 41.0 / 69};
const float ERROR = 0.001;

TEST(IterativeMethods, CheckSimpleIteration) {
    std::vector<float> res = simple_iteration(slae1, b, x0, 0.001, 10e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckJacobiIteration) {
    std::vector<float> res = jacobi_iteration(slae1, b, x0, 10e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}