#include "../../lib/ds/MonotonyStack.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(MonotonyStackTest, MonotonyStackTest1)
{
    std::vector<int32_t> vin{1, 4, 2, 3, 5};
    std::vector<int32_t> vans{-1, 0, 0, 2, 3};
    agoh::MonotonyStack mst(vin.begin(), vin.end());
    EXPECT_EQ(mst.get(), vans);
}

TEST(MonotonyStackTest, MonotonyStackTest2)
{
    std::vector<int32_t> vin{1, 4, 2, 3, 5};
    std::vector<int32_t> vans{-1, -1, 1, 1, -1};
    agoh::MonotonyStack<std::greater<>> mst(vin.begin(), vin.end());
    EXPECT_EQ(mst.get(), vans);
}
TEST(MonotonyStackTest, MonotonyStackTest3)
{
    std::vector<int32_t> vin{1, 4, 2, 3, 5};
    std::vector<int32_t> vans{-1, 2, -1, -1, -1};
    auto mst = agoh::MonotonyStack(vin.rbegin(), vin.rend(), 5).reverse();
    EXPECT_EQ(mst.get(), vans);
}
TEST(MonotonyStackTest, MonotonyStackTest4)
{
    std::vector<int32_t> vin{1, 4, 2, 3, 5};
    std::vector<int32_t> vans{1, 4, 3, 4, -1};
    auto mst = agoh::MonotonyStack<std::greater<>>(vin.rbegin(), vin.rend(), 5).reverse();
    EXPECT_EQ(mst.get(), vans);
}
