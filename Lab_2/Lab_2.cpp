#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

void task_1() {
	int n;
	cout << "Введите n" << endl;
	cin >> n;
	cout << "Ваш числовой треугольник" << endl;
	int i;
	std::string str;
	for (i = 0; i <= n; i++) {
		str = str + std::to_string(i);
		cout << str << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	bool flag = true;
	while (flag) {
		int quest;
		cout << "Если вы хотите вывести числовой треугольник нажмите 1\n Если вы хотите посчитать биномиальные коэфициенты нажмите 2 \n Если вы хотите посчитать среднее арифметическое нескольких цифр нажмите 3\n Для завершения работы программы нажмите 0" << endl;
		cin >> quest;
		if (quest == 1) {
			//Задание 1
			task_1();
		}
		else if (quest == 2) {
			//Задание 2
			int b;
			cout << "Введите число n биномиальные коэфициенты которого вы хотите расчитать" << endl;
			cin >> b;
			cout << "Ваши биномиальные коэфициенты" << endl;
			long double Cnk = 1;


			for (int k = 1; k <= b + 1; k++) {
				cout << Cnk << endl;
				Cnk = Cnk * (b + 1 - k) / k;
			}

		}
		else if (quest == 3) {
			//Задание 3
			cout << "Введите - чтобы остановить ввод и расчитать" << "\n";
			std::string 	s_num;
			int 					ctn = 0;
			int 					summ = 0;
			std::cout << "Enter num[0]: ";
			std::cin >> s_num;
			while (s_num != "-") {
				summ += std::atoi(s_num.c_str());
				ctn++;
				std::cout << "Enter num[" << ctn << "]: ";
				std::cin >> s_num;
			}
			std::cout << double(summ) / ctn << "\n";
		}
		else if (quest == 0) {
			flag = false;
		}
		else {
			cout << "Извините в данной программе нет такой операции" << endl;
		}
	}
	return 0;
}











