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
const double ERROR = 1e-10;

TEST(IterativeMethods, CheckSimpleIteration) {
    std::vector<double> res = simple_iteration(slae1, b, x0, 0.17, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckJacobiIteration) {
    std::vector<double> res = jacobi_iteration(slae1, b, x0, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckGaussSeidelIteration) {
    std::vector<double> res = gauss_seidel_iteration(slae1, b, x0, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckAcceleratedSimpleIteration) {
    std::vector<double> res =
        accelerated_simple_iteration(slae1, b, x0, 6.697224362268005353440389,
                                     10.30277563773199464655961, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckSORIteration) {
    std::vector<double> res = SOR_iteration(slae1, b, x0, 1.9, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

TEST(IterativeMethods, CheckSymmetricGaussSeidelIteration) {
    std::vector<double> res = symmetric_gauss_seidel_iteration(slae1, b, x0, 1e-12);
    for (int i = 0; i < res.size(); ++i) {
        EXPECT_NEAR(res[i], solution1[i], ERROR);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}