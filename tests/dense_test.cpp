#include "matrixes.h"
#include <gtest/gtest.h>

const DenseMatrix slae1({1, 0, 4, 0, 3, 6, 0, 0, 5}, 3);

TEST(DenseTest, CheckItemGetting) {
    ASSERT_EQ(slae1(1, 1), 3);
    ASSERT_EQ(slae1(2, 0), 0);
    ASSERT_EQ(slae1(10, 2), 0);
}

TEST(DenseTest, CheckMatrixVectorMultiplication) {
    const std::vector<double> column1 = {1, -3, 2};
    const std::vector<double> res1 = {9, 3, 10};
    EXPECT_EQ(slae1 * column1, res1);
    const std::vector<double> column2 = {0, 0, 0};
    const std::vector<double> res2 = {0, 0, 0};
    EXPECT_EQ(slae1 * column2, res2);
}

TEST(DenseTest, CheckRowNumber) {
    ASSERT_EQ(slae1.get_number_of_columns(), 3);
    const DenseMatrix slae2({1, 2, 3, 4, 5, 6, 7}, 2);
    ASSERT_EQ(slae2.get_number_of_rows(), 4);
}

TEST(DenseTest, CheckColumnGetting) {
    const std::vector<double> col1 = {1, 0, 0};
    EXPECT_EQ(slae1.get_column(0), col1);
}

TEST(DenseTest, CheckRowGetting) {
    const std::vector<double> row1 = {0, 3, 6};
    EXPECT_EQ(slae1.get_row(1), row1);
}

TEST(DenseTest, CheckZeroInitialization){
    DenseMatrix matrix(3, 4);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j)
        ASSERT_EQ(matrix(i, j), 0);
    }
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}