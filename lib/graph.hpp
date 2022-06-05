#ifndef CPLIB_ALGORITHM_LIB_GRAPH_HPP
#define CPLIB_ALGORITHM_LIB_GRAPH_HPP

#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace agoh
{
template<typename T>
requires std::integral<T>
class Graph
{
private:
    size_t n;
    std::vector<std::vector<std::pair<size_t, T>>> G;

public:
    explicit Graph(size_t n) : n(n)
    {
        this->G.resize(n);
    }
    [[nodiscard]] size_t size() const
    {
        return this->n;
    }
    void add_edge(size_t u, size_t v, T w)
    {
        this->G[u].emplace_back(v, w);
    }
    void for_each_node(size_t u, std::function<void(std::pair<size_t, T>)>&& f) const
    {
        std::for_each(G[u].begin(), G[u].end(), f);
    }
};

template<typename T>
requires std::unsigned_integral<T>
std::vector<T> dijkstra(const Graph<T>& g, size_t start, T inf)
{
    typedef std::pair<T, size_t> pii;
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
        g.for_each_node(u, [&](auto&& p) {
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
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_GRAPH_HPP
