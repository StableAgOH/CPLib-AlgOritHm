#ifndef CPLIB_ALGORITHM_LIB_FRACTION_HPP
#define CPLIB_ALGORITHM_LIB_FRACTION_HPP

#include <cmath>
#include <cstdint>
#include <numeric>
#include <string>

namespace agoh
{
class Fraction
{
private:
    int64_t numerator, denominator;

    void reduct()
    {
        auto g = std::gcd(this->numerator, this->denominator);
        this->numerator /= g;
        this->denominator /= g;
    }

public:
    Fraction() : numerator(0), denominator(1)
    {
    }
    Fraction(int64_t num) : numerator(num), denominator(1)
    {
    }
    Fraction(int64_t numerator, int64_t denominator)
        : numerator(((denominator > 0) ? 1 : -1) * numerator), denominator(std::abs(denominator))
    {
        reduct();
    }
    auto get_numerator() const
    {
        return numerator;
    }
    auto get_denominator() const
    {
        return denominator;
    }
    auto operator-() const
    {
        return Fraction(-numerator, denominator);
    }
    auto operator+=(const Fraction& f)
    {
        auto g = std::gcd(denominator, f.denominator);
        numerator = f.denominator / g * numerator + denominator / g * f.numerator;
        denominator = denominator / g * f.denominator;
        reduct();
        return *this;
    }
    auto operator-=(const Fraction& f)
    {
        auto g = std::gcd(denominator, f.denominator);
        numerator = f.denominator / g * numerator - denominator / g * f.numerator;
        denominator = denominator / g * f.denominator;
        reduct();
        return *this;
    }
    auto operator*=(const Fraction& f)
    {
        auto g1 = std::gcd(numerator, f.denominator);
        auto g2 = std::gcd(denominator, f.numerator);
        numerator = numerator / g1 * (f.numerator / g2);
        denominator = denominator / g2 * (f.denominator / g1);
        return *this;
    }
    auto operator/=(const Fraction& f)
    {
        auto g1 = std::gcd(numerator, f.numerator);
        auto g2 = std::gcd(denominator, f.denominator);
        numerator = numerator / g1 * (f.denominator / g2);
        denominator = denominator / g2 * (f.numerator / g1);
        return *this;
    }
    auto toInteger() const
    {
        return numerator / denominator;
    }
    auto toDouble() const
    {
        return double(numerator) / denominator;
    }
    auto toString() const
    {
        return std::to_string(numerator) + '/' + std::to_string(denominator);
    }
    friend Fraction operator+(const Fraction&, const Fraction&);
    friend Fraction operator-(const Fraction&, const Fraction&);
    friend Fraction operator*(const Fraction&, const Fraction&);
    friend Fraction operator/(const Fraction&, const Fraction&);
    friend bool operator<(const Fraction&, const Fraction&);
    friend bool operator>(const Fraction&, const Fraction&);
    friend bool operator==(const Fraction&, const Fraction&);
    friend bool operator!=(const Fraction&, const Fraction&);
};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    auto g = std::gcd(f1.denominator, f2.denominator);
    return Fraction(f2.denominator / g * f1.numerator + f1.denominator / g * f2.numerator,
                    f1.denominator / g * f2.denominator);
}
Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    auto g = std::gcd(f1.denominator, f2.denominator);
    return Fraction(f2.denominator / g * f1.numerator - f1.denominator / g * f2.numerator,
                    f1.denominator / g * f2.denominator);
}
Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    auto g1 = std::gcd(f1.numerator, f2.denominator);
    auto g2 = std::gcd(f1.denominator, f2.numerator);
    return Fraction(f1.numerator / g1 * (f2.numerator / g2), f1.denominator / g2 * (f2.denominator / g1));
}
Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    auto g1 = std::gcd(f1.numerator, f2.numerator);
    auto g2 = std::gcd(f1.denominator, f2.denominator);
    return Fraction(f1.numerator / g1 * (f2.denominator / g2), f1.denominator / g2 * (f2.numerator / g1));
}
bool operator<(const Fraction& f1, const Fraction& f2)
{
    return (f1 - f2).numerator < 0;
}
bool operator>(const Fraction& f1, const Fraction& f2)
{
    return (f1 - f2).numerator > 0;
}
bool operator==(const Fraction& f1, const Fraction& f2)
{
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}
bool operator!=(const Fraction& f1, const Fraction& f2)
{
    return !(f1 == f2);
}
} // namespace agoh

#endif
