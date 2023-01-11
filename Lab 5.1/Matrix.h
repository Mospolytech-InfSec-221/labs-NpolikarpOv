#pragma once
#include <iostream>
class Matrix {
public:
	int size_col, size_row;
	double* elem;
	Matrix();
	~Matrix();
	bool sum(const Matrix* mat2); //
	bool mult(const Matrix* mat2);//
	double trace(); //
	void mult_by_num(double num); //
	void input(); //
	void print(); //
	int get_columns(); //
	int get_rows(); //
	double get_elem(int i, int j); //
};