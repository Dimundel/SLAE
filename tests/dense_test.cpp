#include "matrixes.h"
#include <gtest/gtest.h>

const DenseMatrix slae1({1, 0, 4, 0, 3, 6, 0, 0, 5}, 3);

TEST(DenseMatrix, CheckItemGetting) {
    ASSERT_EQ(slae1.get_item(1, 1), 3);
    ASSERT_EQ(slae1.get_item(2, 0), 0);
    ASSERT_EQ(slae1.get_item(10, 2), 0);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}