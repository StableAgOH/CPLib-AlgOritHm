#ifndef CPLIB_ALGORITHM_LIB_ALGO_HPP
#define CPLIB_ALGORITHM_LIB_ALGO_HPP

#include <string>
#include <vector>

namespace agoh
{

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
