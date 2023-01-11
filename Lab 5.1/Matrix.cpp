#include "Matrix.h"
Matrix::Matrix() { // конструктор
	this->size_row = 0;
	this->size_col = 0;
	this->elem = nullptr;
};
Matrix::~Matrix() { // деконструтор
	if (this->elem != nullptr)
	{
		delete[] this->elem;
	}
}
void Matrix::input() { //ввод матрицы
	std::cout << "¬ведите количество строк матрицы: ";
	std::cin >> this->size_row;
	std::cout << "¬ведите количество столбцов матрицы: ";
	std::cin >> this->size_col;
	this->elem = new double[size_row * size_col];
	for (int i = 0; i < size_row * size_col; i++) {
		std::cin >> *&this->elem[i];
	}
}
void Matrix::print() { //вывод матрицы
	std::cout << "¬аша матрица: \n";
	for (int i = 0; i < this->size_row; i++) {
		for (int j = 0; j < this->size_col; j++) {
			std::cout << this->elem[i * this->size_col + j] << " ";
		}
		std::cout << '\n';
	}
}
int Matrix::get_columns() { // получить количество столбцов
	return this->size_col;
}
int Matrix::get_rows() { // получить колисчество строк
	return this->size_row;
}
double Matrix::get_elem(int i, int j) { // получить элемент по индексу
	return this->elem[i * this->size_col + j];
}
void Matrix::mult_by_num(double num) { // умножить матрицу на число
	for (int i = 0; i < this->size_row; i++) {
		for (int j = 0; j < this->size_col; j++) {
			this->elem[i * this->size_col + j] = this->elem[i * this->size_col + j] * num;
		}
	}
}
bool Matrix::sum(const Matrix *mat2) { //сложить две матрицы
	if ((this->size_col == mat2->size_col) and (this->size_row == mat2->size_row)) { // проверка на тождественность столбцов и строк
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < this->size_col; j++) {
				this->elem[i * this->size_col + j] = this->elem[i * this->size_col + j] + mat2->elem[i * mat2->size_col + j];
			}
		}
		return 0;
	}
	else {
		return 1;
	}
}
double Matrix::trace() { // след матрицы
	if (this->size_col == this->size_row) {
		double summ = 0;
		for (int i = 0; i < this->size_col; i++) {
			summ += this->elem[i * this->size_col + i];
		}
		return summ;
	}
	return 100000;
}
bool Matrix::mult(const Matrix *mat2) { // умжножение матрицы на матрицу
	if (this->size_row == mat2->size_col) {
		double* res = new double[this->size_row * mat2->size_col]; //создание нового массива
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < mat2->size_col; j++) {
				double summ = 0;
				for (int q = 0; q < this->size_col; q++) {
					summ += this->elem[i * this->size_col + q] * mat2->elem[q * mat2->size_col + j];
				}
				res[i * mat2->size_col + j] = summ;
			}
		}
		delete[] this->elem; //очистка пам€ти
		this->elem = res;
		this->size_col = mat2->size_col;
		return 1;
	}
	else {
		return 0;
	}
}
