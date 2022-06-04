#ifndef CPLIB_ALGORITHM_LIB_DS_MONOTONYSTACK_HPP
#define CPLIB_ALGORITHM_LIB_DS_MONOTONYSTACK_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <stack>
#include <vector>

namespace agoh
{
template<typename C = std::less<>>
class MonotonyStack
{
private:
    std::vector<int32_t> res;
    C comp;

public:
    template<typename II>
    requires std::input_iterator<II>
    MonotonyStack(const II first, const II last, const int32_t default_value = -1)
    {
        std::stack<int32_t> st;
        for(auto it = first; it != last; ++it)
        {
            while(!st.empty() && !comp(*(first + st.top()), *it))
                st.pop();
            res.push_back(st.empty() ? default_value : st.top());
            st.push(it - first);
        }
    }
    auto& reverse()
    {
        std::reverse(this->res.begin(), this->res.end());
        for(auto&& ele : this->res)
            ele = res.size() - ele - 1;
        return *this;
    }
    auto& get()
    {
        return this->res;
    }
};
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_DS_MONOTONYSTACK_HPP
