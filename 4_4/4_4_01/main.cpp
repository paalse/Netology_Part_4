#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	std::cout << "ƒинамический массив: ";

	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout <<  "_ ";
		}
	}

}

int main() {
	setlocale(LC_ALL, "RUS");

	int sizeFull;
	int sizeLogic;
	int tmp;

	std::cout << "¬ведите фактичеcкий размер массива: ";
	std::cin >> sizeFull;
	std::cout << "¬ведите логический размер массива: ";
	std::cin >> sizeLogic;

	int* arr = new int[sizeFull];

	if (sizeFull < sizeLogic) {
		std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" << std::endl;
	}
	else {
		for (int i = 0; i < sizeLogic; i++) {
			std::cout << "¬ведите arr[" << i << "]: ";
			std::cin >> tmp;
			arr[i] = tmp;
		}

		print_dynamic_array(arr, sizeLogic, sizeFull);
	}
	return 0;
}