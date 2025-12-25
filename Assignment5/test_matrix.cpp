#include <gtest/gtest.h>
#include "Matrix.hpp"
#include "Rational.hpp"



TEST(MatrixIntTest, ScalarMultiplication) {
    Matrix<int> mat(2, 2);
    mat(0, 0) = 1; mat(0, 1) = 2;
    mat(1, 0) = 3; mat(1, 1) = 4;

    mat *= 2;

    EXPECT_EQ(mat(0, 0), 2);
    EXPECT_EQ(mat(1, 1), 8);
}

TEST(MatrixIntTest, MatrixAddition) {
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);
    A(0,0) = 1; B(0,0) = 10;
    
    Matrix<int> C = A + B;
    EXPECT_EQ(C(0, 0), 11);
}


TEST(MatrixDoubleTest, Transpose) {
    Matrix<double> mat(2, 3);
    mat(0, 0) = 1.0; mat(0, 1) = 2.0; mat(0, 2) = 3.0;
    
    Matrix<double> T = mat.transp();
    
    EXPECT_EQ(T.rows(), 3);
    EXPECT_EQ(T.cols(), 2);
    EXPECT_EQ(T(1, 0), 2.0); 
}


TEST(RationalTest, Invariant) {
    Rational r1(2, 4);
    EXPECT_EQ(r1.get_num(), 1);
    EXPECT_EQ(r1.get_den(), 2);

    Rational r2(5, -5);
    EXPECT_EQ(r2.get_num(), -1);
    EXPECT_EQ(r2.get_den(), 1);
}

TEST(MatrixRationalTest, FullMultiplication) {
    Matrix<Rational> A(2, 2);
    Matrix<Rational> B(2, 2);

    A(0, 0) = Rational(1, 2);
    A(1, 1) = Rational(1, 2);

    B(0, 0) = Rational(2);
    B(1, 1) = Rational(2);

    Matrix<Rational> C = A * B;

    EXPECT_EQ(C(0, 0), Rational(1, 1));
    EXPECT_EQ(C(0, 1), Rational(0, 1));
    EXPECT_EQ(C(1, 1), Rational(1, 1));
}

TEST(MatrixRationalTest, ThrowException) {
    Matrix<int> A(2, 2);
    Matrix<int> B(3, 3);
    
    EXPECT_THROW(A + B, std::invalid_argument);
    EXPECT_THROW(A *= B, std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
