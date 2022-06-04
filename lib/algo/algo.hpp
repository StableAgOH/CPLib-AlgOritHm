#ifndef CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP
#define CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP

#include <iterator>
#include <string>
#include <vector>

namespace agoh
{
int64_t exgcd(int64_t a, int64_t b, int64_t& x, int64_t& y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    auto d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int64_t qpow(int64_t a, int64_t k, int32_t p)
{
    int64_t res = 1;
    for(; k; k >>= 1, a = a * a % p)
        if(k & 1) res = res * a % p;
    return res;
}

int64_t inv(int64_t a, int32_t p)
{
    int64_t x, y;
    exgcd(a, p, x, y);
    return (x % p + p) % p;
}

std::vector<int64_t> invn(size_t n, int32_t p)
{
    std::vector<int64_t> inv(n + 1);
    inv[1] = 1;
    for(size_t i = 2; i <= n; i++)
        inv[i] = (p - p / static_cast<int64_t>(i)) * inv[p % i] % p;
    return inv;
}

int64_t phi(int64_t x)
{
    auto res = x;
    for(int64_t i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            res = res / i * (i - 1);
            while(x % i == 0)
                x /= i;
        }
    }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

int32_t exeuler(int64_t a, std::string k, int32_t p)
{
    auto phip = phi(p);
    int64_t t = 0;
    bool flag = false;
    for(auto c : k)
    {
        t = t * 10 + c - '0';
        if(t > phip)
        {
            t %= phip;
            flag = true;
        }
    }
    if(flag) t += phip;
    return qpow(a, t, p);
}

std::vector<int32_t> euler_seive_prime(size_t n)
{
    std::vector<bool> vis(n + 1);
    std::vector<int32_t> pri;
    for(int32_t i = 2; i <= n; i++)
    {
        if(!vis[i]) pri.push_back(i);
        for(auto j : pri)
        {
            if(int64_t(i) * j > n) break;
            vis[i * j] = true;
            if(i % j == 0) break;
        }
    }
    return pri;
}
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP
