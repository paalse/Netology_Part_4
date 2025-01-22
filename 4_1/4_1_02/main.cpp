#include <iostream>

int cnt(int* arr, int size, int numb) {

	int left = 0;
	int right = size - 1;
	int mid;
	int res;

	while (left <= right) {
		mid = (left + right) / 2; // вычисляем индекс середины массива

		if (arr[mid] == numb && arr[mid + 1] != numb) break; // если число найдено и следующее число в массиве отличается от искомого то выходим из цикла
		if (arr[mid] > numb) right = mid - 1; // проверяем в какой части дальше искать
		else left = mid + 1;
	}

	if (arr[mid] > numb) res = size - mid;	// в случае если искомое число не точно совпадает с найденым в массиве
	else res = size - 1 - mid;

	return res;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int input_numb = 0;

	do {
		std::cout << "Введите точку отсчёта: ";
		std::cin >> input_numb;

		std::cout << "Количество элементов в массиве больших, чем " << input_numb << ": " << cnt(arr, sizeof(arr) / sizeof(arr[0]), input_numb) << std::endl;
	} while (1);

	return 0;
}