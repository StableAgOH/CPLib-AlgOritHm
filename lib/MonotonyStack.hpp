#ifndef __MONOTONY_STACK_HPP__
#define __MONOTONY_STACK_HPP__
#endif

#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
namespace agoh
{
template<typename T = int, typename C = std::less_equal<T>>
class MonotonyStack
{
private:
    std::vector<int> res;
    C comp;

public:
    template<typename II>
    requires std::input_iterator<II> MonotonyStack(const II first, const II last, const int default_value = -1)
    {
        std::stack<int> st;
        for(auto it = first; it != last; ++it)
        {
            while(!st.empty() && comp(*it, *(first + st.top())))
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
