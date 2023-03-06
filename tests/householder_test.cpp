#include "decompositions.h"
#include "matrixes.h"
#include <gtest/gtest.h>

TEST(HouseholderTest, CheckMatrixR) {
    DenseMatrix slae1({12, -51, 4, 6, 167, -68, -4, 24, -41}, 3);
    slae1 = HouseholderDecompostion(slae1);
    DenseMatrix res1({14, 21, -14, 0, 175, -70, 0, 0, -35}, 3);
    EXPECT_EQ(slae1(0, 0), res1(0, 0));
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}