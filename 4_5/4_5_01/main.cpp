#include <iostream>

// Вывод пирамиды
void print_pyramid(int* arr, int size) {

	int level = 0;

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			std::cout << level << " root " << arr[i] << std::endl;
		}
	
		level = static_cast<int>(std::round(sqrt(i*2+1)));

		if (2 * i + 1 < size) {
			std::cout << level << " left(" << arr[i] << ") " << arr[2 * i + 1] << std::endl;
		}
		if (2 * i + 2 < size) {
			std::cout << level << " right(" << arr[i] << ") " << arr[2 * i + 2] << std::endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	int size = 10;
	int* pyramid = new int[10] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}; //{1, 3, 6, 5, 9, 8};

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << pyramid[i] << " ";
	}
	
	std::cout << "\nПирамида:\n";

	print_pyramid(pyramid, size);

	delete[] pyramid;

	return 0;
}