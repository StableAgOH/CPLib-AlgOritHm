#ifndef CPLIB_ALGORITHM_LIB_DS_MONOTONYQUEUE_HPP
#define CPLIB_ALGORITHM_LIB_DS_MONOTONYQUEUE_HPP

#include <deque>
#include <functional>
#include <iterator>
#include <vector>

namespace agoh
{
template<typename C = std::less<>>
class MonotonyQueue
{
private:
    std::vector<int32_t> res;
    C comp;

public:
    template<typename II>
    requires std::input_iterator<II>
    MonotonyQueue(const II first, const II last, const size_t qsize, const int32_t default_value = -1)
    {
        std::deque<int32_t> q;
        int32_t i = 0;
        for(auto it = first; it != last; ++it, i++)
        {
            if(!q.empty() && q.front() + qsize == i) q.pop_front();
            while(!q.empty() && comp(*it, *(first + q.back())))
                q.pop_back();
            q.push_back(i);
            this->res.push_back(i < qsize - 1 ? default_value : q.front());
        }
    }
    auto& get()
    {
        return this->res;
    }
};
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_DS_MONOTONYQUEUE_HPP
