#ifndef CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP
#define CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP

#include <array>
#include <cmath>
#include <functional>
#include <stdexcept>

namespace agoh
{
template<typename T = int32_t, typename C = std::less<T>>
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
                f[j][i] = m(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
    }
    /**
     * @param l Left endpoint of the closed range, indexed from 0
     * @param r Right endpoint of the closed range, indexed from 0
     * @return RMQ of [l,r]
     */
    T& query(const size_t l, const size_t r)
    {
        if(l > r) throw std::range_error("The left endpoint of the range cannot be greater than the right endpoint");
        auto k = static_cast<size_t>(log2(static_cast<double_t>(r - l + 1)));
        return m(f[l][k], f[r - (1 << k) + 1][k]);
    }
};
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_DS_SPARSETABLE_HPP
