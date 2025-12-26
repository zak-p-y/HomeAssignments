/*
* Pavel Zak
* st142062@student.spbu.ru
HomeAssignment5
*/


#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>
#include <utility>

template<typename T>  // T - type

class Matrix {
private:
	int m; // size m -  height. matrix: m*n
	int n;
	std::vector<std::vector<T>> data;

public: 
	Matrix(int m_size, int n_size) : 
m(m_size), 
n(n_size),
data(m_size, std::vector<T>(n_size, T()))
{}
	
T& operator()(int i, int j) { return data[i][j]; }
const T& operator()(int i, int j) const { return data[i][j]; }

int rows() const {return this->m;}
int cols() const {return this->n;}




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


// matrix sum

Matrix<T>& operator+=(const Matrix<T>& other) {
	if ( (*this).m != other.m || (*this).n != other.n) {
	throw std::invalid_argument("sizes of matrix don't math");
}

	for (int row=0; row<m; row++) {
		for (int col=0; col<n; col++) {
			(*this)(row, col) +=  other(row, col);
			} 
		}
	return *this;
	}



// Matrix multipy

Matrix<T>& operator*=(const Matrix<T>  &other) {
	if (this->n != other.m) {throw std::invalid_argument("shapes of matrix don't fit");}  
	

	Matrix<T> new_matrix(this->m, other.n);

	// iterate i,j new matirx
	for (int i=0; i<new_matrix.m; i++) {
		for (int j=0; j<new_matrix.n; j++) {
			for (int k=0; k<this->n; k++) {
				new_matrix(i,j) +=  this->data[i][k] * other.data[k][j];

			}
		}
	}

	*this = std::move(new_matrix);
	return *this;
}





// transp()
Matrix<T> transp() const {
Matrix<T> new_matrix(this->n, this->m);
for (int i=0; i<this->m; i++) {
	for (int j=0; j<this->n; j++) {
		new_matrix(j, i) = (*this)(i, j);
	}
}

return new_matrix;
}



Matrix<T> operator+(const Matrix<T>& other) const {
    Matrix<T> result = *this;
    result += other;
    return result;
}

Matrix<T> operator*(const Matrix<T>& other) const {
    return Matrix<T>(*this) *= other; 
}

Matrix<T> operator*(const T& a) const {
    return Matrix<T>(*this) *= a;
}



bool operator==(const Matrix<T>& other) const {
    if (m != other.m || n != other.n) return false;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (data[i][j] != other.data[i][j])
                return false;
    return true;
}

};








#endif


