#include "../../lib/algo/algo.hpp"
#include <algorithm>
#include <gtest/gtest.h>

TEST(algoTest, algoTest_exgcd)
{
    int64_t a = 8, b = 6, x, y;
    int64_t g = std::__gcd(a, b);
    agoh::exgcd(a, b, x, y);
    ASSERT_EQ(a * x + b * y, g);
}

TEST(algoTest, algoTest_qpow)
{
    ASSERT_EQ(agoh::qpow(2, 2, 3), 1);
    ASSERT_EQ(agoh::qpow(233, 666, 998244353), 842358828);
    ASSERT_EQ(agoh::qpow(1e18, 1e18, 1e9 + 7), 244417745);
}

TEST(algoTest, algoTest_inv)
{
    ASSERT_EQ(agoh::inv(2, 998244353), 499122177);
    ASSERT_EQ(agoh::inv(233, 1e9 + 7), 90128756);
    ASSERT_EQ(agoh::inv(1e9, 1e9 + 7), 857142863);
}

TEST(algoTest, algoTest_invn)
{
    std::vector<int64_t> vans{0, 1, 7, 9, 10, 8, 11, 2, 5, 3, 4};
    ASSERT_EQ(agoh::invn(10, 13), vans);
}
