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

TEST(algoTest, algoTest_phi)
{
    ASSERT_EQ(agoh::phi(1), 1);
    ASSERT_EQ(agoh::phi(5), 4);
    ASSERT_EQ(agoh::phi(100), 40);
    ASSERT_EQ(agoh::phi(347), 346);
    ASSERT_EQ(agoh::phi(500), 200);
}

TEST(algoTest, algoTest_exeuler)
{
    ASSERT_EQ(agoh::exeuler(9, "8", 7), 4);
    ASSERT_EQ(agoh::exeuler(998244353, "98765472103312450233333333333", 12345), 5333);
    ASSERT_EQ(agoh::exeuler(12345, "12345678987654321", 12345678), 2699055);
    ASSERT_EQ(agoh::exeuler(2, "1", 4), 2);
    ASSERT_EQ(agoh::exeuler(2, "2", 4), 0);
}

TEST(algoTest, algoTest_euler_seive_prime)
{
    std::vector<int32_t> vans{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                              43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    ASSERT_EQ(agoh::euler_seive_prime(97), vans);
}
