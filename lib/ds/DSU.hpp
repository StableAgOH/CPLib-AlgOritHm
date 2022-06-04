//
// Created by AgOH on 2022/6/4.
//

#ifndef CPLIB_ALGORITHM_LIB_DS_DSU_HPP
#define CPLIB_ALGORITHM_LIB_DS_DSU_HPP

#include <numeric>
#include <vector>

namespace agoh
{
class DSU
{
private:
    std::vector<size_t> fa;

public:
    explicit DSU(const size_t n)
    {
        this->fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
    }
    size_t find(const size_t x)
    {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    bool merge(const size_t x, const size_t y)
    {
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
