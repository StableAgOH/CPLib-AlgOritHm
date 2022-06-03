#include "../../lib/ds/SparseTable.hpp"
#include <gtest/gtest.h>

TEST(SparseTableTest, SparseTableTest1)
{
    std::vector<int> vin{9, 3, 1, 7, 5, 6, 0, 8};
    std::vector<int> vans{9, 9, 7, 7, 9, 8, 7, 9};
    std::vector<int> vout;
    agoh::SparseTable<int, std::greater<>> st(vin.begin(), vin.end());
    vout.push_back(st.query(0, 5));
    vout.push_back(st.query(0, 4));
    vout.push_back(st.query(1, 6));
    vout.push_back(st.query(1, 5));
    vout.push_back(st.query(0, 7));
    vout.push_back(st.query(3, 7));
    vout.push_back(st.query(2, 6));
    vout.push_back(st.query(0, 7));
    ASSERT_EQ(vout, vans);
}
