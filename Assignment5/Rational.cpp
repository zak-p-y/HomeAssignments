#include "Rational.hpp"
#include <numeric>
#include <stdexcept>
#include <cmath>

void Rational::simplify() {
    if (den == 0) {
        throw std::invalid_argument("den cannot be zero");
    }
    if (den < 0) {
        num = -num;
        den = -den;
    }
    int common = std::gcd(std::abs(num), den);
    num /= common;
    den /= common;
}

Rational::Rational() : num(0), den(1) {}

Rational::Rational(int n) : num(n), den(1) {}

Rational::Rational(int n, int d) : num(n), den(d) {
    simplify();
}

int Rational::get_num() const { return num; }

int Rational::get_den() const { return den; }

Rational& Rational::operator+=(const Rational& other) {
    num = num * other.den + other.num * den;
    den = den * other.den;
    simplify();
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    num *= other.num;
    den *= other.den;
    simplify();
    return *this;
}

Rational Rational::operator+(const Rational& other) const {
    Rational res = *this;
    res += other;
    return res;
}

Rational Rational::operator*(const Rational& other) const {
    Rational res = *this;
    res *= other;
    return res;
}

bool Rational::operator==(const Rational& other) const {
    return num == other.num && den == other.den;
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}
