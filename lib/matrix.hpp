#ifndef CPLIB_ALGORITHM_LIB_MATRIX_HPP
#define CPLIB_ALGORITHM_LIB_MATRIX_HPP

#include <algorithm>
#include <iostream>
#include <valarray>

namespace agoh
{
template<typename T>
class Matrix
{
private:
    size_t _r, _c;
    std::valarray<std::valarray<T>> _ele;
    void assert_can_plus_or_minus(const Matrix& M)
    {
        if(_r != M._r || _c != M._c) throw std::invalid_argument("Illegal number of rows or columns");
    }
    void assert_can_mul(const Matrix& M)
    {
        if(_c != M._r) throw std::invalid_argument("Illegal number of rows or columns");
    }

public:
    Matrix(size_t row, size_t col) : _r(row), _c(col)
    {
        _ele.resize(row, std::valarray<T>(col));
    }
    explicit Matrix(const std::valarray<std::valarray<T>>& elements)
    {
        _r = elements.size();
        _c = _r ? elements[0].size() : 0;
        _ele = elements;
    }
    Matrix(const std::initializer_list<std::valarray<T>> list) : Matrix(std::valarray(list))
    {
    }
    template<size_t C>
    Matrix(size_t row, size_t col, T array[][C]) : _r(row), _c(col)
    {
        _ele.resize(row);
        for(size_t i = 0; i < row; i++)
            _ele[i] = std::valarray<T>(array[i], col);
    }
    [[nodiscard]] size_t row() const
    {
        return _r;
    }
    [[nodiscard]] size_t col() const
    {
        return _c;
    }
    [[nodiscard]] T& operator()(size_t r, size_t c)
    {
        return _ele[r][c];
    }
    Matrix operator+(const T& x)
    {
    }
    Matrix& operator+=(const T& x)
    {
        std::for_each(begin(_ele), end(_ele), [&x](auto& r) { r += x; });
    }
    Matrix operator+(const Matrix& M)
    {
        assert_can_plus_or_minus(M);
        Matrix R(*this);
        for(size_t i = 0; i < _r; i++)
            R[i] += M._ele[i];
        return R;
    }
    Matrix& operator+=(const Matrix& M)
    {
        assert_can_plus_or_minus(M);
        for(size_t i = 0; i < _r; i++)
            _ele[i] += M._ele[i];
        return *this;
    }
    Matrix operator-(const T& x)
    {
    }
    Matrix& operator-=(const T& x)
    {
        std::for_each(begin(_ele), end(_ele), [&x](auto& r) { r -= x; });
    }
    Matrix operator-(const Matrix& M)
    {
        assert_can_plus_or_minus(M);
    }
    Matrix& operator-=(const Matrix& M)
    {
        assert_can_plus_or_minus(M);
    }
    Matrix operator*(const T& x)
    {
    }
    Matrix& operator*=(const T& x)
    {
        std::for_each(begin(_ele), end(_ele), [&x](auto& r) { r *= x; });
    }
    Matrix operator*(const Matrix& M)
    {
        assert_can_mul(M);
        Matrix R(_r, _c);
        for(size_t i = 0; i < _r; i++)
            for(size_t j = 0; j < M._c; j++)
                for(size_t k = 0; k < _c; k++)
                    R._ele[i][j] += _ele[i][k] * M._ele[k][j];
        return R;
    }
    template<typename I>
    requires std::integral<T> && std::integral<I>
    Matrix operator%(I p)
    {
        return Matrix(_ele.apply([p](const auto& r) { r.apply([p](const auto& e) { return e % p; }); }));
    }
    template<typename I>
    requires std::integral<T> && std::integral<I>
    Matrix& operator%=(I p)
    {
        std::for_each(begin(_ele), end(_ele), [p](auto& r) { r %= p; });
    }
    Matrix transpose()
    {
        Matrix R(_c, _r);
        for(size_t i = 0; i < _c; i++)
            for(size_t j = 0; j < _r; j++)
                R[i][j] = _ele[j][i];
        return R;
    }

public:
    friend std::istream& operator>>(std::istream& is, const Matrix& M)
    {
        for(size_t i = 0; i < M._r; i++)
            for(size_t j = 0; j < M._c; j++)
                is >> M._ele[i][j];
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M)
    {
        for(size_t i = 0; i < M._r; i++)
        {
            for(size_t j = 0; j < M._c; j++)
                os << M._ele[i][j] << ' ';
            os << std::endl;
        }
        return os;
    }
};

template<typename T, typename I>
requires std::integral<I>
Matrix<T> qpow(Matrix<T> M, I k, I p)
{
    Matrix R(M);
    for(k--; k; k >>= 1, M = M * M % p)
        if(k & 1) R = R * M % p;
    return R;
}
} // namespace agoh

#endif // CPLIB_ALGORITHM_LIB_MATRIX_HPP
