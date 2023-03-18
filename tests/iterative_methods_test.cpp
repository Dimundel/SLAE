#include "iterative_methods.h"
#include "matrixes.h"
#include <gtest/gtest.h>

const CSRMatrix slae1({{{0, 0}, 10},
                       {{0, 1}, 1},
                       {{1, 0}, 1},
                       {{1, 1}, 7},
                       {{2, 1}, 0.1},
                       {{2, 2}, 1}});
std::vector<double> b = {20, 30, 1};
std::vector<double> x0 = {0, 0, 0};
std::vector<double> solution1 = {110.0 / 69.0, 280.0 / 69.0, 41.0 / 69.0};
const double ERROR = 1e-5;

// TEST(IterativeMethods, CheckSimpleIteration) {
//     std::vector<double> res = simple_iteration(slae1, b, x0, 0.16, 10e-12);
//     for (int i = 0; i < res.size(); ++i) {
//         EXPECT_NEAR(res[i], solution1[i], ERROR);
//     }
// }

TEST(IterativeMethods, CheckJacobiIteration) {
    std::vector<double> res = jacobi_iteration(slae1, b, x0, 1e-20);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckGaussSeidelIteration) {
    std::vector<double> res = gauss_seidel_iteration(slae1, b, x0, 10e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}