#include "../lib/algo.hpp"
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

TEST(algoTest, algoTest_kmp_nxt1)
{
    std::vector<size_t> vans{0, 0, 1};
    ASSERT_EQ(agoh::kmp_next("aba"), vans);
}

TEST(algoTest, algoTest_kmp_nxt2)
{
    std::vector<size_t> vans{0, 1, 2, 3, 4};
    ASSERT_EQ(agoh::kmp_next("aaaaa"), vans);
}

TEST(algoTest, algoTest_kmp1)
{
    std::vector<size_t> vans{0, 2};
    ASSERT_EQ(agoh::kmp("abababc", "aba"), vans);
}

TEST(algoTest, algoTest_kmp2)
{
    std::vector<size_t> vans{
        2,    119,  220,  323,  423,  530,  636,  736,  836,  941,  1043, 1155, 1255, 1368, 1470, 1581,
        1688, 1791, 1892, 2028, 2134, 2238, 2338, 2439, 2543, 2643, 2743, 2843, 2944, 3046, 3147, 3247,
        3347, 3458, 3559, 3659, 3762, 3862, 3971, 4075, 4200, 4300, 4405, 4507, 4607, 4709, 4809, 4915,
        5018, 5119, 5222, 5331, 5434, 5534, 5634, 5737, 5849, 5961, 6063, 6176, 6277, 6380, 6481, 6592,
        6695, 6799, 6906, 7013, 7113, 7221, 7324, 7424, 7530, 7646, 7756, 7856, 7959, 8059, 8177, 8281,
        8399, 8499, 8601, 8703, 8807, 8907, 9007, 9108, 9208, 9309, 9409, 9513, 9613, 9719, 9820,
    };
    for(auto&& i : vans)
        --i;
    ASSERT_EQ(
        agoh::kmp(
            "BABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBCCBB"
            "CACBBCCCCAABABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBA"
            "CBCBCCBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBC"
            "CCCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAB"
            "BCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBBAACCAA"
            "BBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCACBCBBA"
            "BBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCAC"
            "ABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBA"
            "ACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABCABABBCCACABABBAA"
            "CBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCACABBCCACABABBAACBAC"
            "CBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCABCBACAAACABBCCACABABB"
            "AACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBAC"
            "CBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCBBBACCCABAAABBCCACABAB"
            "BAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBAABBCCACABABBAAC"
            "BACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBACCBCBCABBABBCCACABA"
            "BBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCACABCBBABBCCACAB"
            "ABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCBABBCCACABABB"
            "AACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABBCCACABABBAACBA"
            "CCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABCBACCCBBAABBCACBAABA"
            "BCBACACAACAABABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBB"
            "ACBCBCCCCBCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBB"
            "ACBCBCCACABABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBAC"
            "BCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCB"
            "ABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBACCAB"
            "BCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACA"
            "BABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAA"
            "CBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCB"
            "ABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABBCCACABABBAACBACCBABCCA"
            "CCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBAABBCCACABABBAACBACCBABCCACCCB"
            "AACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABBCCACABABBAACBACCBABCCACCCBAACBC"
            "ABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACC"
            "BACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABA"
            "CCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABCABACACAAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCB"
            "ACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABA"
            "CCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCA"
            "CACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACAC"
            "ABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBC"
            "CCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAAABCCBBBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABC"
            "BBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABACABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBB"
            "CCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCACACACBACAACBCCBABABBCCBBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCB"
            "ACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABAC"
            "CACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBCBCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACC"
            "ACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCA"
            "CACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABC"
            "BBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCC"
            "CACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCA"
            "CBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCA"
            "CBCBBCAACBABCAACBBCACCCBBACBCBCCACBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBC"
            "BBCAACBABCAACBBCACCCBBACBCBCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAA"
            "CBABCAACBBCACCCBBACBCBCCBAAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBA"
            "BCAACBBCACCCBBACBCBCCAABAACBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAA"
            "CBABCAACBBCACCCBBACBCBCCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBA"
            "BCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACB"
            "BCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCC"
            "BBACBCBCCCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBA"
            "CBCBCCCACCCACCBAAAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCA"
            "CCCBBACBCBCCBAAABACBBABCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCA"
            "ACBBCACCCBBACBCBCCBBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBB"
            "CACCCBBACBCBCCCCAABABCBBCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBA"
            "BCAACBBCACCCBBACBCBCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAAC"
            "BBCACCCBBACBCBCCCABABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBC"
            "ACCCBBACBCBCCBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCB"
            "BACBCBCCAACAACABBBCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBC"
            "ACCCBBACBCBCCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACC"
            "CBBACBCBCCBCCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCB"
            "BACBCBCCBBACBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCC"
            "BBACBCBCCACBCABAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACC"
            "CBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACB"
            "CBCCCAABBCACABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBA"
            "CBCBCCBBBABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBC"
            "BCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAAC"
            "BCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCB"
            "ABBBCACAABABCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBB"
            "ACBCBCCABCACBBACCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCAC"
            "CCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBAC"
            "BCBCCCCAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCB"
            "CCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAACA"
            "CCAABBAACBCBBCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCB"
            "BACBCBCCABCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBA"
            "CBCBCCBABACBACCACCCCBCBCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCA"
            "ACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCA"
            "CCCBBACBCBCCBCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCB"
            "BACBCBCCAAABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACB"
            "CBCCBBCCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCB"
            "CCABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBC"
            "CACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABBCCACAB"
            "ABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAAC"
            "BACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCAABBCCACABABBAACBACCB"
            "ABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCAC"
            "CCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBABBABBCCACABABBAACBACCBABCCACCC"
            "BAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCABBCCACABABBAACBACCBABCCACCCBAACBC"
            "ABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCCACCCABBCCACABABBAACBACCBABCCACCCBAACBC"
            "ABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCBABBCCACABABBAACBACCBABCCACCCBAACBCABAAC"
            "CBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCCCBCBCAACCBABCABABABCBABABCABCCBBCCCBBCBACBCAC"
            "ACCCABACBCBBBACCAAABCCBBBCCCACBCBBBB",
            "ABBCCACABABBAACBACCBABCCACCCBAACBCABAACCBACABACCACCACACABCBBCCCACCCACBCBBCAACBABCAACBBCACCCBBACBCBCC"),
        vans);
}