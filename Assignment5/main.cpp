/*
* Pavel Zak
* st142062@student.spbu.ru
HomeAssignment5
*/

#include <iostream>
#include "Matrix.hpp"
#include "Rational.hpp"

int main() {
    Matrix<Rational> A(2, 2);
    Matrix<Rational> B(2, 2);

    A(0, 0) = Rational(1, 2);
    A(0, 1) = Rational(1, 4);
    A(1, 0) = Rational(0);
    A(1, 1) = Rational(1);

    B(0, 0) = Rational(2, 1);
    B(0, 1) = Rational(1);
    B(1, 0) = Rational(1, 2);
    B(1, 1) = Rational(3);

    Matrix<Rational> C = A + B;
    Matrix<Rational> D = A * B;
    Matrix<Rational> E = A.transp();
    
    A *= Rational(2);

    Rational val = D(0, 0);
    std::cout << val.get_num() << "/" << val.get_den() << std::endl;

    return 0;
}
