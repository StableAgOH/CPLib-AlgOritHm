//
// Created by AgOH on 2022/6/4.
//

#ifndef CPLIB_ALGORITHM_LIB_DS_DSU_HPP
#define CPLIB_ALGORITHM_LIB_DS_DSU_HPP

#include <numeric>
#include <stdexcept>
#include <vector>

namespace agoh
{
class DSU
{
private:
    size_t n;
    std::vector<size_t> fa;

public:
    explicit DSU(const size_t n) : n(n)
    {
        this->fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
    }
    size_t find(const size_t x)
    {
        if(x >= n) throw std::out_of_range("Illegal set id");
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(const size_t x, const size_t y)
    {
        if(x >= n || y >= n) throw std::out_of_range("Illegal set id");
        auto fx = find(x), fy = find(y);
        if(fx != fy)
        {
            fa[fx] = fy;
            return true;
        }
        else return false;
    }
};
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_DS_DSU_HPP
