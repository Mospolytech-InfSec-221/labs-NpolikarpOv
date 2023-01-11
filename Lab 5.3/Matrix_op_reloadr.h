#pragma once
#include <iostream>
class Matrix {
public:
	int size_col, size_row;
	double* elem;

	Matrix();// конструктор
	Matrix(int i, int j);// конструктор
	Matrix(int i, int j, const double* arr);// конструктор
	Matrix(const Matrix& temp); // копирующий консткрутор
	~Matrix();// деконструктор
	bool sum(const Matrix* mat2); //
	bool sum(const double* arr, int row, int col);
	bool mult(const Matrix* mat2);//
	bool mult(const double* arr, int col, int row);
	double trace(); //
	double det();
	void mult_by_num(double num); //
	void input(); //
	void input(int i, int j);
	void input(int i, int j, double* arr);
	void print(); //
	int get_columns(); //
	int get_rows(); //
	double get_elem(int i, int j); //
	friend std::ostream& operator <<(std::ostream& out, const Matrix& temp);
	friend std::istream& operator>>(std::istream& in, Matrix& temp);
	friend Matrix operator+ (const Matrix& temp1, const Matrix& temp2);
	friend Matrix operator- (const Matrix& temp1, const Matrix& temp2);
	void operator - ();
	void operator * (int n);
	void operator * (const Matrix& temp);
	void operator= (const Matrix& temp);
	void operator += (const Matrix& temp);
	void operator -= (const Matrix& temp);
};