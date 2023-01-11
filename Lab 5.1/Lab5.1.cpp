// Policarpov
#include "Matrix.h"
#include <iostream>
int main() {
	setlocale(LC_ALL, "RUS");
	Matrix mat1, mat2;
	int choice;
	//меню
	while (true) {
		std::cout << "\nЧто вы хотите выполнить? \n"
			<< "1. Ввод матрицу №1\n"
			<< "2. Ввод матрицы №2\n"
			<< "3. Вывод матрицы №1\n"
			<< "4. Вывод матрицы №2\n"
			<< "5. Вывести кол-во строк и столбцов первой матрицы\n"
			<< "6. Вывести кол-во строк и столбцов второй матрицы\n"
			<< "7. Вывод элемента матрицы номер 1 по индексу\n"
			<< "8. Вывод элемента матрицы номер 2 по индексу\n"
			<< "9. Умножить матрицу №1 на число n\n"
			<< "10.Умножить матрицу №2 на число n\n"
			<< "11.Прибавить к матрице №1 матрицу №2\n"
			<< "12.Найти след первой матрицы\n"
			<< "13.Найти след второй матрицы\n"
			<< "14.Умножить первую матрицу на вторую\n"
			<< "15.Умножить вторую матрицу на первую\n"
			<< "16.Выход\n";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cout << "Ввод матрицы №1\n";
			mat1.input();
			std::cout << "Ввод матрицы №1 завершён\n";
			break;
		}
		case 2: {
			std::cout << "Ввод матрицы №2\n";
			mat2.input();
			std::cout << "Ввод матрицы №2завершён\n";
			break;
		}
		case 3: {
			std::cout << "Вывод матрицы №1\n";
			mat1.print();
			break;
		}
		case 4: {
			std::cout << "Вывод матрицы №2\n";
			mat2.print();
			break;
		}
		case 5: {
			std::cout << "Кол-во строк первой матрицы " << mat1.get_rows() << '\n';
			std::cout << "Кол-во столбцов первой матрицы " << mat1.get_columns();
			break;
		}
		case 6: {
			std::cout << "Кол-во строк второй матрицы " << mat2.get_rows() << '\n';
			std::cout << "Кол-во столбцов второй матрицы " << mat2.get_columns();
			break;
		}
		case 7: {
			int i, j;
			std::cout << "\nВведите i-индекс и j- индекс для поиска элемента в первой матрице\n";
			std::cout << "i-индекс: "; std::cin >> i;
			std::cout << "j-индекс: "; std::cin >> j;
			std::cout << mat1.get_elem(i, j);
			break;
		}
		case 8: {
			int i, j;
			std::cout << "\nВведите i-индекс и j- индекс для поиска элемента во второй матрице\n";
			std::cout << "i-индекс: "; std::cin >> i;
			std::cout << "j-индекс: "; std::cin >> j;
			std::cout << mat2.get_elem(i, j);
			break;
		}
		case 9: {
			std::cout << "\nВведите число n: "; double n; std::cin >> n;
			mat1.mult_by_num(n);
			break;
		}
		case 10: {
			std::cout << "\nВведите число n: "; double n; std::cin >> n;
			mat2.mult_by_num(n);
			break;
		}
		case 11: {
			if (mat2.get_columns() != 0) {
				if (mat1.sum(&mat2) == 0) {
					std::cout << "Сложение первой матрицы со второй прошла успешно\n";
				}
				else {
					std::cout << "Размерность второй матрицы не совпадает с размерностью первой";
				}
			}
			break;
		}
		case 12: {
			if (mat1.get_columns() == 0) {
				std::cout << "Матрица №1 пуста";
				break;
			}
			if (mat1.trace() != 100000 ) {
				std::cout << mat1.trace();
			}
			else {
				std::cout << "Матрица №1 не квадратная\n";
			}
			break;
		}
		case 13: {
			if (mat2.get_columns() == 0) {
				std::cout << "Матрица №2 пуста";
				break;
			}
			if (mat2.trace() != 100000) {
				std::cout << mat2.trace();
			}
			else {
				std::cout << "Матрица №2 не квадратная\n";
			}
			break;
		}
		case 14: {
			if (mat1.mult(&mat2) == 0 or mat1.get_columns() == 0 or mat2.get_columns() == 0) {
				std::cout << "Одна из матриц некорректна";
			}
			else {
				mat1.mult(&mat2);
				std::cout << "Умножение прошло успешно";
			}
			break;
		}
		case 15: {
			if (mat2.mult(&mat1) == 0 or mat1.get_columns() == 0 or mat2.get_columns() == 0) {
				std::cout << "Одна из матриц некорректна";
			}
			else {
				mat2.mult(&mat1);
				std::cout << "Умножение прошло успешно";
			}
			break;
		}
		case 16: {
			return 0;
		}
		}
	}
}