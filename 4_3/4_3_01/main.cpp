#include <iostream>

// Вывод массива на консоль
void arrToConsole(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Сортировка слиянием
void merge_sort(int* arr, int size)
{
	if (size <= 1) 	return; // Если размер массива 1 м меньшеше то сортировку не выполняем
		
	// Делим массив на два
	int left_size = size / 2;	
	int right_size = size - left_size;

	// По каждой половине массива рекурсивно запускаем сортировку слиянием
	merge_sort(&arr[0], left_size);
	merge_sort(&arr[left_size], right_size);

	int left = 0;
	int right = left_size;
	int tmp = 0;
	int* tmp_arr = new int[size];	// Временный массив

	while (left < left_size || right < size)
	{
		if (arr[left] < arr[right]) {
			tmp_arr[tmp++] = std::move(arr[left]);
			left++;
		}
		else {
			tmp_arr[tmp++] = std::move(arr[right]);
			right++;
		}

		if (left == left_size) {
			std::copy(arr + right, arr + size, &tmp_arr[tmp]);
			break;
		}

		if (right == size) {
			std::copy(arr + left, arr + left_size, &tmp_arr[tmp]);
			break;
		}
	}

	std::copy(tmp_arr + 0, tmp_arr + size, arr);	

	delete[] tmp_arr;
}

int main() {
	setlocale(LC_ALL, "RUS");

	int arr[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Исходный массив #1: ";
	arrToConsole(arr, arrSize);
	merge_sort(arr, arrSize);
	std::cout << "Отсортированный массив #1: ";
	arrToConsole(arr, arrSize);
	std::cout << std::endl;

	int arr1[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
	std::cout << "Исходный массив #2: ";
	arrToConsole(arr1, arr1Size);
	merge_sort(arr1, arr1Size);
	std::cout << "Отсортированный массив #2: ";
	arrToConsole(arr1, arr1Size);
	std::cout << std::endl;

	int arr2[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "Исходный массив #3: ";
	arrToConsole(arr2, arr2Size);
	merge_sort(arr2, arr2Size);
	std::cout << "Отсортированный массив #3: ";
	arrToConsole(arr2, arr2Size);

	return 0;
}