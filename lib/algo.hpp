#ifndef CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP
#define CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP

#include <iterator>
#include <string>
#include <vector>

namespace agoh
{
int64_t ex_gcd(int64_t a, int64_t b, int64_t& x, int64_t& y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    auto d = ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int64_t qpow(int64_t a, int64_t k, int64_t p)
{
    int64_t res = 1;
    for(; k; k >>= 1, a = a * a % p)
        if(k & 1) res = res * a % p;
    return res;
}

int64_t inv(int64_t a, int64_t p)
{
    int64_t x, y;
    ex_gcd(a, p, x, y);
    return (x % p + p) % p;
}

std::vector<int64_t> invn(size_t n, int64_t p)
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

int64_t ex_euler(int64_t a, const std::string& k, int64_t p)
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

std::vector<int32_t> euler_sieve_prime(size_t n)
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

std::vector<size_t> prefix_function(const std::string& s)
{
    std::vector<size_t> nxt(s.length());
    for(size_t i = 1, j = 0; i < s.length(); i++)
    {
        while(j > 0 && s[j] != s[i])
            j = nxt[j - 1];
        if(s[j] == s[i]) nxt[i] = ++j;
    }
    return nxt;
}

/**
 * Knuth–Morris–Pratt algorithm
 * @param match match string
 * @param pattern pattern string
 * @param split A character that does not appear in match and pattern
 * @return All positions where pattern string appears in match string, indexed from 0
 */
std::vector<size_t> kmp(const std::string& match, const std::string& pattern, char split = '#')
{
    std::vector<size_t> res;
    auto s = pattern + split + match;
    auto nxt = prefix_function(s);
    for(size_t i = 0; i < s.length(); i++)
        if(nxt[i] == pattern.length()) res.push_back(i - (pattern.length() << 1));
    return res;
}
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_ALGO_ALGO_HPP
