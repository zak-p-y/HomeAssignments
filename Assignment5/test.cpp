#include <gtest/gtest.h>
#include "Matrix.hpp"


TEST(MatrixTest, MultiplyByScalar) {
	Matrix<int> m(2,2);
	m(0,0) = 1; m(0, 1) = 2; m(1,0) = 4; m(1,1) = 6;
	//Matrix<int>  result =  m*=(2);
	m*=2;
	EXPECT_EQ(m(0,0), 2);
	EXPECT_EQ(m(0,1), 4);

}
