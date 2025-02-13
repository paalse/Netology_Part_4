#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	for (int i = 0; i < actual_size; i++) {
		if (i < logical_size) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout << "_ ";
		}
	}
}


void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int newElement) {

	if (logical_size < actual_size) {
		arr[logical_size] = newElement;
		logical_size++;
	}
	else {
		int* newArr = new int[actual_size * 2];

		std::copy(arr + 0, arr + actual_size, newArr);
		newArr[logical_size] = newElement;
		logical_size++;
		actual_size *= 2;
		arr = newArr;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	int sizeFull;
	int sizeLogic;
	int tmp;

	std::cout << "������� �������c��� ������ �������: ";
	std::cin >> sizeFull;
	std::cout << "������� ���������� ������ �������: ";
	std::cin >> sizeLogic;

	int* arr = new int[sizeFull];

	if (sizeFull < sizeLogic) {
		std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!" << std::endl;
	}
	else {
		for (int i = 0; i < sizeLogic; i++) {
			std::cout << "������� arr[" << i << "]: ";
			std::cin >> tmp;
			arr[i] = tmp;
		}

		print_dynamic_array(arr, sizeLogic, sizeFull);


		do {
			std::cout << "\n������� ������� ��� ����������: ";
			std::cin >> tmp;

			if (tmp == 0) break;

			append_to_dynamic_array(arr, sizeLogic, sizeFull, tmp);
			std::cout << "������������ ������: ";
			print_dynamic_array(arr, sizeLogic, sizeFull);

		} while (1);

		std::cout << "�������! ��� ������: ";
		print_dynamic_array(arr, sizeLogic, sizeFull);
	}
	delete[] arr;

	return 0;
}