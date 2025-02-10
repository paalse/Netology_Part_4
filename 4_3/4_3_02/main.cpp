#include <iostream>

// Вывод массива на консоль
void arrToConsole(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// Быстрая сортировка
void quick_sort(int* arr, int size) {
	int i = 0;          // Указатель на крайний левый элемент
	int j = size - 1;   // Указатель на правой правый элемент
	int tmp;            // Временная переменная для смены элементов массива между собой
	int pivot = arr[size / 2];  // Определение опорного элемента

	do {
		// С лева от опорного элемента ищем элемент, который больше опорного
		while (arr[i] < pivot) {
			i++;
		}
		// С права от опорного элемента ищем элемент, который меньше опорного
		while (arr[j] > pivot) {
			j--;
		}

		// Меняем местами найденные элементы
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j); // Продолжаем до тех пор пока указатель на левую границу массива не пересекается с указателем на правый элемент


	//Если еще не весь массив отсортирован то продолжаем
	if (j > 0) {
		quick_sort(arr, j + 1);  //Сортируем левую часть массива
	}
	if (i < size) {
		quick_sort(&arr[i], size - i);    //Сортируем правую часть массива
	}
}



int main() {
	setlocale(LC_ALL, "RUS");

	int arr[] = { 3, 43, 38, 29, 18 , 72, 57, 61, 2, 33 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Исходный массив #1: ";
	arrToConsole(arr, arrSize);
	quick_sort(arr, arrSize);
	std::cout << "Отсортированный массив #1: ";
	arrToConsole(arr, arrSize);
	std::cout << std::endl;

	int arr1[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
	std::cout << "Исходный массив #2: ";
	arrToConsole(arr1, arr1Size);
	quick_sort(arr1, arr1Size);
	std::cout << "Отсортированный массив #2: ";
	arrToConsole(arr1, arr1Size);
	std::cout << std::endl;

	int arr2[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << "Исходный массив #3: ";
	arrToConsole(arr2, arr2Size);
	quick_sort(arr2, arr2Size);
	std::cout << "Отсортированный массив #3: ";
	arrToConsole(arr2, arr2Size);

	return 0;
}