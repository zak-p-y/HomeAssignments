/*
* Pavel Zak
* st142062@student.spbu.ru
HomeAssignment5
*/

#ifndef RATIONAL_HPP
#define RATIONAL_HPP


#include <iostream>
#include <numeric>
#include <stdexcept>

class Rational {
private:
    int num;
    int den;

    void simplify() {
        if (den == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int common = std::gcd(std::abs(num), den);
        num /= common;
        den /= common;
    }

public:
    Rational() : num(0), den(1) {}

// need for initialization
    Rational(int n) : num(n), den(1) {}

//main constructure
    Rational(int n, int d) : num(n), den(d) {
        simplify();
    }

    int get_num() const { return num; }
    int get_den() const { return den; }


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
