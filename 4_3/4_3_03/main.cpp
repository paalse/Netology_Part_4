#include <iostream>

// Вывод массива на консоль
void arrToConsole(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Сортировка подсчетом
void count_sort(int* arr, int size)
{
	int max = 0;

	int* output = new int[size]; // Выходной массив
	int* count = new int[size];	// Массив счетчиков

	// Здесь находим наибольший элемент в  исходном массиве 
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) max = arr[i];
	}

	// Заполняем массив 0-ми  массив со счетчиками
	for (int i = 0; i <= max; ++i) {
		count[i] = 0;
	}

	// Подсчитываем количество элементов в исходном массиве и сохраняем в массиве со счетчиками
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	// Сохраняем кумулятивный счёт каждого элемента
	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}
	// Получение количества из счетного массива для элементов исходного массива и размещаем элементы в выходной массив
	for (int i = size - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	// Перенос отсортированных элементов в исходный массив
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}

	delete[] output;
	delete[] count;
}

int main() {
	setlocale(LC_ALL, "RUS");

	int arr[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Исходный массив #1: ";
	arrToConsole(arr, arrSize);
	count_sort(arr, arrSize);
	std::cout << "Отсортированный массив #1: ";
	arrToConsole(arr, arrSize);
	std::cout << std::endl;

	int arr1[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
	int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
	std::cout << "Исходный массив #2: ";
	arrToConsole(arr1, arr1Size);
	count_sort(arr1, arr1Size);
	std::cout << "Отсортированный массив #2: ";
	arrToConsole(arr1, arr1Size);
	std::cout << std::endl;

	int arr2[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
	int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "Исходный массив #3: ";
	arrToConsole(arr2, arr2Size);
	count_sort(arr2, arr2Size);
	std::cout << "Отсортированный массив #3: ";
	arrToConsole(arr2, arr2Size);

	return 0;
}