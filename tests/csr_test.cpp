#include "matrixes.h"
#include <gtest/gtest.h>

const CSRMatrix
    slae1({{{0, 0}, 1}, {{0, 1}, 2}, {{2, 2}, 6}, {{1, 1}, 4}, {{2, 1}, 2}});
const CSRMatrix slae2({{{2, 3}, 11},
                       {{1, 2}, 4},
                       {{0, 1}, 2},
                       {{2, 1}, 1},
                       {{0, 3}, 3},
                       {{0, 0}, 1}});
const CSRMatrix
    slae3({{{0, 0}, 2}, {{0, 1}, 3}, {{0, 2}, -1}, {{2, 1}, 2}, {{2, 2}, 4}});

TEST(CSRTest, CheckValueInitializaion) {
    const std::vector<double> values1 = {1, 2, 4, 2, 6};
    ASSERT_EQ(slae1.get_values(), values1);
    const std::vector<double> values2 = {1, 2, 3, 4, 1, 11};
    ASSERT_EQ(slae2.get_values(), values2);
    const std::vector<double> values3 = {2, 3, -1, 2, 4};
    ASSERT_EQ(slae3.get_values(), values3);
}

TEST(CSRTest, CheckColumnIndexesInitialization) {
    const std::vector<int> column_indexes1 = {0, 1, 1, 1, 2};
    ASSERT_EQ(slae1.get_column_indexes(), column_indexes1);
    const std::vector<int> column_indexes2 = {0, 1, 3, 2, 1, 3};
    ASSERT_EQ(slae2.get_column_indexes(), column_indexes2);
    const std::vector<int> column_indexes3 = {0, 1, 2, 1, 2};
    ASSERT_EQ(slae3.get_column_indexes(), column_indexes3);
}

TEST(CSRTest, CheckRowIndexationInitialization) {
    const std::vector<int> row_indexation1 = {0, 2, 3, 5};
    ASSERT_EQ(slae1.get_row_indexation(), row_indexation1);
    const std::vector<int> row_indexation2 = {0, 3, 4, 6};
    ASSERT_EQ(slae2.get_row_indexation(), row_indexation2);
    const std::vector<int> row_indexation3 = {0, 3, 3, 5};
    ASSERT_EQ(slae3.get_row_indexation(), row_indexation3);
}

TEST(CSRTest, CheckItemGetting) {
    EXPECT_EQ(slae1(1, 1), 4);
    EXPECT_EQ(slae1(1, 0), 0);
    EXPECT_EQ(slae2(2, 3), 11);
    EXPECT_EQ(slae2(9, 8), 0);
}

TEST(CSRTest, CheckMatrixVectorMultiplication) {
    const std::vector<double> column1 = {1, 0, 3};
    const std::vector<double> res1 = {1, 0, 18};
    EXPECT_EQ(slae1 * column1, res1);
    const std::vector<double> column2 = {-2, 3, 0, -1, 2};
    const std::vector<double> res2 = {1, 0, -8};
    EXPECT_EQ(slae2 * column2, res2);
    const std::vector<double> column3 = {2, 7, 1};
    const std::vector<double> res3 = {24, 0, 18};
    EXPECT_EQ(slae3 * column3, res3);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}