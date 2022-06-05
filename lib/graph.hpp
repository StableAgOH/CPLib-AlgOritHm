#ifndef CPLIB_ALGORITHM_LIB_GRAPH_HPP
#define CPLIB_ALGORITHM_LIB_GRAPH_HPP

#include "ds/DSU.hpp"
#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace agoh
{
template<typename T>
requires std::integral<T>
class Graph
{
public:
    typedef uint32_t node_type;
    typedef std::pair<node_type, T> neighbor_type;
    typedef std::tuple<T, node_type, node_type> edge_type;

protected:
    size_t n;
    std::vector<std::vector<neighbor_type>> G;

public:
    explicit Graph(size_t n) : n(n)
    {
        G.resize(n);
    }
    [[nodiscard]] size_t size() const
    {
        return n;
    }
    virtual void add_edge(node_type u, node_type v, T w)
    {
        if(u < 0 || u >= n || v < 0 || v >= n) throw std::out_of_range("Illegal node id");
        G[u].emplace_back(v, w);
    }
    void for_each_neighbor(node_type u, std::function<void(neighbor_type)>&& f) const
    {
        if(u < 0 || u >= n) throw std::out_of_range("Illegal node id");
        std::for_each(G[u].begin(), G[u].end(), f);
    }
    std::vector<edge_type> get_edges() const
    {
        std::vector<edge_type> edges;
        for(node_type i = 0; i < n; i++)
            for_each_neighbor(i, [i, &edges](auto&& p) { edges.emplace_back(p.second, i, p.first); });
        return edges;
    }
};

template<typename T>
requires std::integral<T>
class UndirectedGraph : public Graph<T>
{
public:
    using Graph<T>::Graph;
    void add_edge(typename Graph<T>::node_type u, typename Graph<T>::node_type v, T w)
    {
        Graph<T>::add_edge(u, v, w);
        Graph<T>::add_edge(v, u, w);
    }
};

template<typename T>
requires std::unsigned_integral<T>
std::vector<T> dijkstra(const Graph<T>& g, typename Graph<T>::node_type start, T inf)
{
    typedef std::pair<T, typename Graph<T>::node_type> pii;
    std::vector<T> dis(g.size(), inf);
    std::vector<bool> vis(g.size());
    std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
    dis[start] = T();
    pq.emplace(T(), start);
    while(!pq.empty())
    {
        auto u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        if(dis[u] == inf) continue;
        g.for_each_neighbor(u, [&](auto&& p) {
            auto [v, w] = p;
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.emplace(dis[v], v);
            }
        });
    }
    return dis;
}

template<typename T>
auto kruskal(const UndirectedGraph<T>& g)
{
    auto edges = g.get_edges();
    std::sort(edges.begin(), edges.end());
    DSU dsu(g.size());
    auto cnt = g.size();
    T sum = T();
    for(auto [w, u, v] : edges)
    {
        if(dsu.merge(u, v))
        {
            --cnt;
            sum += w;
        }
    }
    return std::pair<T, bool>(sum, cnt == 1);
}
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_GRAPH_HPP
