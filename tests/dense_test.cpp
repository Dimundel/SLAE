#include "matrixes.h"
#include <gtest/gtest.h>

const DenseMatrix slae1({1, 0, 4, 0, 3, 6, 0, 0, 5}, 3);

TEST(DenseTest, CheckItemGetting) {
    ASSERT_EQ(slae1.get_item(1, 1), 3);
    ASSERT_EQ(slae1.get_item(2, 0), 0);
    ASSERT_EQ(slae1.get_item(10, 2), 0);
}

TEST(DenseTest, CheckMatrixVectorMultiplication) {
    const std::vector<float> column1 = {1, -3, 2};
    const std::vector<float> res1 = {9, 3, 10};
    EXPECT_EQ(slae1 * column1, res1);
    const std::vector<float> column2 = {0, 0, 0};
    const std::vector<float> res2 = {0, 0, 0};
    EXPECT_EQ(slae1 * column2, res2);
}

TEST(DenseTest, CheckRowNumber) {
    ASSERT_EQ(slae1.get_number_of_columns(), 3);
    const DenseMatrix slae2({1, 2, 3, 4, 5, 6, 7}, 2);
    ASSERT_EQ(slae2.get_number_of_rows(), 4);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}