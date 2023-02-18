#include "matrixes.h"
#include <gtest/gtest.h>

const CSRMatrix
    slae1({{{0, 0}, 1}, {{0, 1}, 2}, {{2, 2}, 6}, {{1, 1}, 4}, {{2, 1}, 2}});
const std::vector<float> values1 = {1, 2, 4, 2, 6};
const std::vector<int> column_indexes1 = {0, 1, 1, 1, 2};
const std::vector<int> row_indexation1 = {0, 2, 3, 5};

const CSRMatrix slae2({{{2, 3}, 11},
                       {{1, 2}, 4},
                       {{0, 1}, 2},
                       {{2, 1}, 1},
                       {{0, 3}, 3},
                       {{0, 0}, 1}});
const std::vector<float> values2 = {1, 2, 3, 4, 1, 11};
const std::vector<int> column_indexes2 = {0, 1, 3, 2, 1, 3};
const std::vector<int> row_indexation2 = {0, 3, 4, 6};

TEST(CSRTest, CheckValueInitializaion) {
    ASSERT_EQ(slae1.get_values(), values1);
    ASSERT_EQ(slae2.get_values(), values2);
}

TEST(CSRTest, CheckColumnIndexesInitialization) {
    ASSERT_EQ(slae1.get_column_indexes(), column_indexes1);
    ASSERT_EQ(slae2.get_column_indexes(), column_indexes2);
}

TEST(CSRTest, CheckRowIndexationInitialization) {
    ASSERT_EQ(slae1.get_row_indexation(), row_indexation1);
    ASSERT_EQ(slae2.get_row_indexation(), row_indexation2);
}

TEST(CSRTest, CheckItemGetting) {
    ASSERT_EQ(slae1.get_item(1, 1), 4);
    ASSERT_EQ(slae1.get_item(1, 0), 0);
    ASSERT_EQ(slae2.get_item(2, 3), 11);
    ASSERT_EQ(slae2.get_item(9, 8), 0);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}