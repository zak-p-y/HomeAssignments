#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
private:
    long long num;
    long long den;

    void simplify() {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        long long common = std::gcd(std::abs(num), den);
        num /= common;
        den /= common;
    }

public:
    Rational() : num(0), den(1) {}

// need for initialization
    Rational(long long n) : num(n), den(1) {}

//main constructure
    Rational(long long n, long long d) : num(n), den(d) {
        simplify();
    }

    long long get_num() const { return num; }
    long long get_den() const { return den; }


    Rational& operator+=(const Rational& other) {
        num = num * other.den + other.num * den;
        den = den * other.den;
        simplify();
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        num *= other.num;
        den *= other.den;
        simplify();
        return *this;
    }

    Rational operator+(const Rational& other) const {
        Rational res = *this;
        res += other;
        return res;
    }

    Rational operator*(const Rational& other) const {
        Rational res = *this;
        res *= other;
        return res;
    }

    bool operator==(const Rational& other) const {
        return num == other.num && den == other.den;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

};

#endif
