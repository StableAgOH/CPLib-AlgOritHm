#ifndef __SPARSE_TABLE_HPP__
#define __SPARSE_TABLE_HPP__
#endif

#include <array>
#include <cassert>
#include <cmath>
#include <functional>
namespace agoh
{
template<typename T = int, typename C = std::less<T>>
class SparseTable
{
private:
    typedef std::array<T, 25> arr;
    std::vector<arr> f;
    C comp;
    T& m(T& a, T& b)
    {
        return comp(a, b) ? a : b;
    }

public:
    template<typename II>
    requires std::input_iterator<II>
    SparseTable(const II first, const II last)
    {
        for(auto it = first; it != last; ++it)
            f.emplace_back(arr{*it});
        for(int i = 1; (1 << i) <= f.size(); i++)
            for(int j = 0; j + (1 << i) - 1 < f.size(); j++)
                f[j][i] = m(f[j][i - 1], f[j + (1 << i - 1)][i - 1]);
    }
    /**
     * @param l Left endpoint of the closed interval, indexed from 0
     * @param r Right endpoint of the close interval, indexed from 0
     * @return The RMQ of [l,r]
     */
    T& query(const size_t l, const size_t r)
    {
        assert(l <= r);
        size_t k = log2(r - l + 1);
        return m(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
} // namespace agoh
