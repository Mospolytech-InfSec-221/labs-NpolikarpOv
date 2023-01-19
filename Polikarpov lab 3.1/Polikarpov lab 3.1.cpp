#include <iostream>
void bubbles(int* arr, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	std::cout << "{ ";
	for (int i = 0; i < k; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << '}' << '\n';

}

void withcounter(char* arr1, int size) {
	int q = 0, pod[26] = { 0 }, size_alp = 26;
	for (int i = 0; i < size; i++) {
		q = arr1[i] - 'a';
		pod[q]++;
	}
	int i = 0, r = 0;
	while (r <= size_alp) {
		if (pod[r] > 0) {
			arr1[i] = char(int('a') + r);
			i++;
			pod[r]--;
		}
		else {
			r++;
		}
	}
	std::cout << "{ ";
	for (int i = 0; i < size; i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << "}\n";
}
void merge(int*, int, int, int); //объявляем функцию merge, так как она используется в merge_sort
void merge_sort(int* arr, int low, int high)
//изначально делим пополам, потом половинку на 2 (получаем четверть) до тех пор пока не получим единчиный массив, что указано в условии
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2; // середина ряда
		merge_sort(arr, low, mid); // рекурсивно передвигаем вверхнюю границу до серидины (то есть делим массив на 2 и берём первую часть)
		merge_sort(arr, mid + 1, high); // рекурсивно передвигаем нижнюю границу (то есть делим массив на 2 и берём вторую половину)
		merge(arr, low, high, mid); // сортируем и заносим значения в глобальный массив arr2
	}
}
void merge(int* arr, int low, int high, int mid)
{
	int i, j, k, c[50];
	//i и j образуют неотсортированную пару
	i = low; // счётчик для нижней границы
	k = low; //индекс для основного массива
	j = mid + 1; // счётчик для нижней границы относительно середины mid + 1
	while (i <= mid and j <= high) { // если нижняя граница меньше mid и нижняя граница отсносительно mid + 1 меньше вверхнкй границы
		if (arr[i] < arr[j]) {
			c[k] = arr[i]; //записываем в основном массив меньшее значение пары
			k++; // увеличиваем индекс на 1
			i++; // сдвигаем нижнюю границу на 1 вправо
		}
		else {
			c[k] = arr[j];
			k++;//увеличиваем индекс на 1
			j++;// сдвигаем второй элемент пары вправо
		}
	}
	while (i <= mid and j > high) { // для нечётного количества элементов изначального массива
		c[k] = arr[i];
		k++;
		i++;
	}
	for (i = low; i < k; i++) {
		arr[i] = c[i]; //заносим значения в глобальный массив arr2
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	const int max_size = 1000;
	// сортировка пузырьком;
	int arr[1000], n, counter = 0, k, choice = 0;
	while (true) {
		std::cout << "Что вы хотите выполнить? \n"
			<< "1. Сортировка пузырьком\n"
			<< "2. Сортировка подсчётом\n"
			<< "3. Сортировка слиянием\n"
			<< "4. выход\n";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::cout << "Сортировка пузырьком" << std::endl;
			std::cout << "Введите размера массива n < 1000: ";
			std::cin >> k;
			for (int i = 0; i < k; i++) {
				std::cin >> arr[i];
			}
			bubbles(arr, k);
			break;
		}
		case 2: {
			// сортировка подсчётом
			char arr1[1000];
			int size_alp = 26, pod[26] = { 0 }, q = 0, size;
			std::cout << "Сортировка подсчётом" << std::endl;
			std::cout << "Введите размер массива: ";
			std::cin >> size;
			for (int i = 0; i < size; i++) {
				std::cin >> arr1[i];
			}
			withcounter(arr1, size);
			break;
		}
			  // сортировка слиянием;
		case 3: {
			int arr2[1000], size1;
			std::cout << "Сортировка слиянием";
			std::cout << '\n' << "Введите размер массива n < 1000: ";
			std::cin >> size1;
			for (int i = 0; i < size1; i++) {
				std::cin >> arr2[i];
			}
			merge_sort(arr2, 0, size1 - 1);
			for (int i = 0; i < size1; i++) {
				std::cout << arr2[i] << ' ';
			}
			std::cout << '\n';
			break;
		}
		default: {
			return 0;
		}
		}
	}
}
