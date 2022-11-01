#include <iostream>

void input(int*& arr, int& len)
{
	std::cout << "input massive len:";
	std::cin >> len;
	if (arr != nullptr)
	{
		delete[] arr;
	}
	arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		std::cin >> arr[i];
	}
}

void output(int* arr, int len)
{
	if (arr != nullptr)
	{
		for (int i = 0; i < len; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}
	else
	{
		std::cout << "array is empty\n\n";
	}
}

int num_len(int num, int count)
{
	int n = 10;
	while (num >= n)
	{
		count++;
		n *= 10;
	}
	return(count);
}

int sum_digit(int num)
{
	int count = 0, sum = 0, n = 10;
	count = num_len(num, count);
	if (count % 2 == 0)
	{
		num /= 10;
	}
	for (int i = 0; i < count; i++)
	{
		sum += num % 10;
		num /= 100;
	}
	return(sum);
}

void sort(int* arr, int len)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (sum_digit(arr[j]) > sum_digit(arr[j + 1]))
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
	}
