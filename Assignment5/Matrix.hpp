#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream> 
#include <string> 
#include <vector>



template<typename T>  // T - type

class Matrix {
private:
	int m; // size m -  height. matrix: m*n
	int n;
	std::vector<std::vector<T>> data;

public: 
	Matrix(int m_size, int n_size) :  m(m_size), n(n_size)  {}
	
	 T& operator()(int m, int n) {return data[m][n];}
	const T& operator()(int m, int n) const {return data[m][n];}


// multipy scalar
	Matrix<T>& operator*=(const T& a) //scalar
	{
	for (auto& row : data) {
		for (auto& elem :row) {
			elem*= a;
				}
		}
	return *this;
	}






};










#endif
