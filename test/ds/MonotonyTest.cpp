#include "../../lib/ds/MonotonyStack.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(MonotonyStackTest, MonotonyStackTest1)
{
    std::vector<int> vin{1, 4, 2, 3, 5};
    std::vector<int> vans{1, 4, 3, 4, -1};
    auto mst = agoh::MonotonyStack<int, std::greater_equal<>>(vin.rbegin(), vin.rend(), 5).reverse();
    ASSERT_EQ(mst.get(), vans);
}
