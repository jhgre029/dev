/* Name: Jacob Grendahl
 * NetID: jhgrendahl
 * Date: 2018-03-02
 * Project: structures
 * File: Matrix.h
 */
 
/* Description: This file runs the Matrix Class and implents all methods */
 
#ifndef MATRIX_H
#define MATRIX_H
/* Libraries: */
#include<iostream> 
#include<fstream>

/* Headers: */
/* None */

template<typename T, int rows, int columns>
class Matrix
{
public: 
	/* Data */
	T values[rows][columns];

	/* Constructors and Destructors */
	Matrix();
	Matrix(const Matrix<T, rows, columns>& m);
	
	/* Getters */
	int getRows() { return _rows; };
	int getColumns() { return _columns; };

	/* Setters */
	/* Operator Overloads */
	friend std::ostream& operator << (std::ostream& o, Matrix<T, rows, columns>& m)
	{
		std::cout << "Entered Matrix Operator << Overload" << std::endl;
		for (int i = 0; i < rows; i++)
		{
			o << "[\t";
			for (int j = 0; j < columns; j++)
				o << m.values[i][j] << '\t';
			o << ']' << std::endl;
		}
		return o;
	}

	Matrix<T, rows, columns> operator = (const Matrix<T, rows, columns>& m)
	{
		std::cout << "Entered Matrix Operator = Overload" << std::endl;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				values[i][j] = m.values[i][j];
		return *this;
	}

	Matrix<T, rows, columns> operator + (const Matrix<T, rows, columns>& m)
	{
		std::cout << "Entered Matrix Operator + Overload" << std::endl;
		Matrix < T, rows, columns> result;
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				result.values[i][j] = values[i][j] + m.values[i][j];
		return result;
	}
	/* Other Methods */
	Matrix<T, columns, rows> transpose();

private:
	int _rows;
	int _columns;
};


/***********************************************************************************************/
/* CONSTRUCTORS AND DESTRUCTORS */
/***********************************************************************************************/
template<typename T, int rows, int columns>
Matrix<T, rows, columns>::Matrix()
	:_rows(rows), _columns(columns)
{
	std::cout << "Entered Matrix Default Constructor" << std::endl;
	for (int i = 0; i < _rows; i++)
		for (int j = 0; j < _columns; j++)
			values[i][j] = T(0);
}

template<typename T, int rows, int columns>
Matrix<T, rows, columns>::Matrix(const Matrix<T, rows, columns>& m)
	:_rows(rows), _columns(columns)
{
	std::cout << "Entered Matrix Copy Constructor" << std::endl;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			values[i][j] = m.values[i][j];
}

/***********************************************************************************************/
/* OTHER METHODS */
/***********************************************************************************************/
template<typename T, int rows, int columns>
Matrix<T, columns, rows> Matrix<T, rows, columns>::transpose()
{
	Matrix<T, columns, rows> result;
	for (int i = 0; i < columns; i++)
		for (int j = 0; j < rows; j++)
			result.values[i][j] = values[j][i];
	return result;
}

#endif//MATRIX_H