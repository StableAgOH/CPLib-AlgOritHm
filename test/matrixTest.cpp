#include "../lib/matrix.hpp"
#include <gtest/gtest.h>

TEST(matrixTest, matrixTest_init)
{
    agoh::Matrix<int32_t> M1(2, 3);
    EXPECT_EQ(M1.row(), 2);
    EXPECT_EQ(M1.col(), 3);
    for(size_t i = 0; i < 2; i++)
        for(size_t j = 0; j < 3; j++)
            EXPECT_EQ(M1(i, j), 0);

    uint32_t a[2][2] = {{1, 2}, {3, 4}};
    agoh::Matrix<uint32_t> M2(2, 2, a);
    EXPECT_EQ(M2.row(), 2);
    EXPECT_EQ(M2.col(), 2);
    for(size_t i = 0; i < 2; i++)
        for(size_t j = 0; j < 2; j++)
            EXPECT_EQ(M2(i, j), a[i][j]);

    std::valarray<std::valarray<int64_t>> v{
        {1, 2},
        {4, 5},
        {7, 8},
    };
    agoh::Matrix<int64_t> M3(v);
    EXPECT_EQ(M3.row(), 3);
    EXPECT_EQ(M3.col(), 2);
    for(size_t i = 0; i < 3; i++)
        for(size_t j = 0; j < 2; j++)
            EXPECT_EQ(M3(i, j), v[i][j]);

    agoh::Matrix M4(M3);
    EXPECT_EQ(M4.row(), 3);
    EXPECT_EQ(M4.col(), 2);
    for(size_t i = 0; i < 3; i++)
        for(size_t j = 0; j < 2; j++)
            EXPECT_EQ(M4(i, j), M3(i, j));

    agoh::Matrix<int32_t> M5{{2, 2}, {3, 3}};
    EXPECT_EQ(M5.row(), 2);
    EXPECT_EQ(M5.col(), 2);
    for(size_t i = 0; i < 2; i++)
        for(size_t j = 0; j < 2; j++)
            EXPECT_EQ(M5(i, j), i + 2);
}
