/*
* Pavel Zak
* st142062@student.spbu.ru
HomeAssignment5
*/

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational {
private:
    int num;
    int den;

    void simplify();

public:
    Rational();
    Rational(int n);
    Rational(int n, int d);

    int get_num() const;
    int get_den() const;

    Rational& operator+=(const Rational& other);
    Rational& operator*=(const Rational& other);

    Rational operator+(const Rational& other) const;
    Rational operator*(const Rational& other) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
};

#endif
