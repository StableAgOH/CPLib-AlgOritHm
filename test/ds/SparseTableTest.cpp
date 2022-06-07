#include "../../lib/ds/SparseTable.hpp"
#include <gtest/gtest.h>

TEST(SparseTableTest, SparseTableTest1)
{
    std::vector<int32_t> vin{1, 2, 3};
    std::vector<int32_t> vans{1, 2, 3, 1, 2, 1, 1};
    std::vector<int32_t> vout;
    agoh::SparseTable<int32_t> st(vin.begin(), vin.end());
    vout.push_back(st.query(0, 0));
    vout.push_back(st.query(1, 1));
    vout.push_back(st.query(2, 2));
    vout.push_back(st.query(0, 1));
    vout.push_back(st.query(1, 2));
    vout.push_back(st.query(0, 2));
    vout.push_back(st.query(0, 2));
    EXPECT_EQ(vout, vans);
}

TEST(SparseTableTest, SparseTableTest2)
{
    std::vector<int32_t> vin{1, 2, 3};
    std::vector<int32_t> vans{1, 2, 3, 2, 3, 3, 3};
    std::vector<int32_t> vout;
    agoh::SparseTable<int32_t, std::greater<>> st(vin.begin(), vin.end());
    vout.push_back(st.query(0, 0));
    vout.push_back(st.query(1, 1));
    vout.push_back(st.query(2, 2));
    vout.push_back(st.query(0, 1));
    vout.push_back(st.query(1, 2));
    vout.push_back(st.query(0, 2));
    vout.push_back(st.query(0, 2));
    EXPECT_EQ(vout, vans);
}

const int64_t e16 = int64_t(3e16);
const int64_t e17 = int64_t(2e17);
const int64_t e18 = int64_t(1e18);

TEST(SparseTableTest, SparseTableTest3)
{
    std::vector<int64_t> vin{e16, e17, e18};
    std::vector<int64_t> vans{e16, e17, e18, e16, e17, e16, e16};
    std::vector<int64_t> vout;
    agoh::SparseTable<int64_t> st(vin.begin(), vin.end());
    vout.push_back(st.query(0, 0));
    vout.push_back(st.query(1, 1));
    vout.push_back(st.query(2, 2));
    vout.push_back(st.query(0, 1));
    vout.push_back(st.query(1, 2));
    vout.push_back(st.query(0, 2));
    vout.push_back(st.query(0, 2));
    EXPECT_EQ(vout, vans);
}

TEST(SparseTableTest, SparseTableTest4)
{
    std::vector<int64_t> vin{e16, e17, e18};
    std::vector<int64_t> vans{e16, e17, e18, e17, e18, e18, e18};
    std::vector<int64_t> vout;
    agoh::SparseTable<int64_t, std::greater<>> st(vin.begin(), vin.end());
    vout.push_back(st.query(0, 0));
    vout.push_back(st.query(1, 1));
    vout.push_back(st.query(2, 2));
    vout.push_back(st.query(0, 1));
    vout.push_back(st.query(1, 2));
    vout.push_back(st.query(0, 2));
    vout.push_back(st.query(0, 2));
    EXPECT_EQ(vout, vans);
}
