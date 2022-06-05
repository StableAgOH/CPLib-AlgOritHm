#include "../lib/graph.hpp"
#include <gtest/gtest.h>
#include <set>

TEST(graphTest, graphTest1)
{
    agoh::Graph<int32_t> g(4);
    g.add_edge(1, 1, 2);
    g.add_edge(1, 2, 3);
    g.add_edge(2, 1, 5);
    g.add_edge(1, 3, 5);
    ASSERT_EQ(g.size(), 4);
    g.for_each_node(0, [](auto&& p) { ASSERT_TRUE(false); });
    std::set<size_t> sv1{1, 2, 3};
    std::set<int32_t> sw1{2, 3, 5};
    std::set<size_t> sx1;
    std::set<int32_t> sy1;
    g.for_each_node(1, [&](auto&& p) {
        sx1.insert(p.first);
        sy1.insert(p.second);
    });
    ASSERT_EQ(sv1, sx1);
    ASSERT_EQ(sw1, sy1);
    std::set<size_t> sv2{1};
    std::set<int32_t> sw2{5};
    std::set<size_t> sx2;
    std::set<int32_t> sy2;
    g.for_each_node(2, [&](auto&& p) {
        sx2.insert(p.first);
        sy2.insert(p.second);
    });
    ASSERT_EQ(sv2, sx2);
    ASSERT_EQ(sw2, sy2);
    g.for_each_node(3, [](auto&& p) { ASSERT_TRUE(false); });
}

TEST(graphTest, graphTest_dijkstra1)
{
    std::vector<uint32_t> vout{0, 2, 4, 3};
    agoh::Graph<uint32_t> g(4);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 1);
    g.add_edge(0, 2, 5);
    g.add_edge(2, 3, 3);
    ASSERT_EQ(agoh::dijkstra(g, 0, 0x3f3f3f3fu), vout);
}

TEST(graphTest, graphTest_dijkstra2)
{
    std::vector<uint32_t> vout{166, 163, 2147483647, 246, 0};
    agoh::Graph<uint32_t> g(5);
    g.add_edge(1, 1, 270);
    g.add_edge(0, 3, 89);
    g.add_edge(1, 0, 3);
    g.add_edge(4, 4, 261);
    g.add_edge(4, 1, 163);
    g.add_edge(4, 4, 275);
    g.add_edge(3, 4, 108);
    g.add_edge(3, 3, 231);
    g.add_edge(2, 3, 213);
    g.add_edge(2, 2, 119);
    g.add_edge(2, 0, 77);
    g.add_edge(2, 0, 6);
    g.add_edge(1, 3, 83);
    g.add_edge(4, 4, 196);
    g.add_edge(4, 4, 94);
    ASSERT_EQ(agoh::dijkstra(g, 4, 2147483647u), vout);
}
