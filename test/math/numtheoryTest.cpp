#include "../../lib/math/numtheory.hpp"
#include <gtest/gtest.h>

TEST(numtheoryTest, numtheoryTest_exgcd)
{
    int64_t a = 8, b = 6, x, y;
    int64_t g = std::__gcd(a, b);
    agoh::ex_gcd(a, b, x, y);
    EXPECT_EQ(a * x + b * y, g);
}

TEST(numtheoryTest, numtheoryTest_qpow)
{
    EXPECT_EQ(agoh::qpow(2, 2, 3), 1);
    EXPECT_EQ(agoh::qpow(233, 666, 998244353), 842358828);
    EXPECT_EQ(agoh::qpow(1e18, 1e18, 1e9 + 7), 244417745);
}

TEST(numtheoryTest, numtheoryTest_inv1)
{
    EXPECT_EQ(agoh::inv(2, 998244353), 499122177);
    EXPECT_EQ(agoh::inv(233, 1e9 + 7), 90128756);
    EXPECT_EQ(agoh::inv(1e9, 1e9 + 7), 857142863);
}

TEST(numtheoryTest, numtheoryTest_inv2)
{
    std::vector<int64_t> vin = {233, 666, 1057, 114514, 1919810, 20220924};
    std::vector<int64_t> vans1 = {844009174, 235321867, 759307909, 137043501, 595887626, 141246948};
    std::vector<int64_t> vans2 = {90128756, 812312318, 497634819, 987311602, 724460759, 9174111};
    EXPECT_EQ(agoh::inv(vin, 998244353), vans1);
    EXPECT_EQ(agoh::inv(vin, 1e9 + 7), vans2);
}

TEST(numtheoryTest, numtheoryTest_invn)
{
    std::vector<int64_t> vans{0, 1, 7, 9, 10, 8, 11, 2, 5, 3, 4};
    EXPECT_EQ(agoh::invn(10, 13), vans);
}

TEST(numtheoryTest, numtheoryTest_phi)
{
    EXPECT_EQ(agoh::phi(1), 1);
    EXPECT_EQ(agoh::phi(5), 4);
    EXPECT_EQ(agoh::phi(100), 40);
    EXPECT_EQ(agoh::phi(347), 346);
    EXPECT_EQ(agoh::phi(500), 200);
}

TEST(numtheoryTest, numtheoryTest_exeuler)
{
    EXPECT_EQ(agoh::ex_euler(9, "8", 7), 4);
    EXPECT_EQ(agoh::ex_euler(998244353, "98765472103312450233333333333", 12345), 5333);
    EXPECT_EQ(agoh::ex_euler(12345, "12345678987654321", 12345678), 2699055);
    EXPECT_EQ(agoh::ex_euler(2, "1", 4), 2);
    EXPECT_EQ(agoh::ex_euler(2, "2", 4), 0);
}

TEST(numtheoryTest, numtheoryTest_euler_seive_prime)
{
    std::vector<int32_t> vans{2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                              43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    EXPECT_EQ(agoh::euler_sieve_prime(97), vans);
}
