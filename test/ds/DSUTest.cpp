#include "../../lib/ds/DSU.hpp"
#include <gtest/gtest.h>
#include <vector>

char eq(size_t x, size_t y)
{
    return x == y ? 'Y' : 'N';
}

TEST(DSUTest, DSUTest1)
{
    std::vector<char> vans{'N', 'Y', 'N', 'Y'};
    std::vector<char> vout;
    agoh::DSU dsu(4);
    vout.push_back(eq(dsu.find(0), dsu.find(1)));
    dsu.merge(0, 1);
    vout.push_back(eq(dsu.find(0), dsu.find(1)));
    dsu.merge(2, 3);
    vout.push_back(eq(dsu.find(0), dsu.find(3)));
    dsu.merge(1, 2);
    vout.push_back(eq(dsu.find(0), dsu.find(3)));
    ASSERT_EQ(vout, vans);
}
