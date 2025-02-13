#include <iostream>
#include <string>

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

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
	if (logical_size == 1) {
		logical_size--;
	}
	else if ((logical_size - 1) > (actual_size / 3)) {
		for (int i = 1; i < logical_size; i++) {
			arr[i - 1] = arr[i];
		}
		logical_size--;
	}
	else {
		int* newArr = new int[actual_size / 3];
		std::copy(arr + 1, arr + logical_size, newArr);
		arr = newArr;
		logical_size--;
		actual_size /= 3;
	}
}


int main() {
	setlocale(LC_ALL, "RUS");

	int sizeFull;
	int sizeLogic;
	int tmp;
	std::string str;

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
			std::cout << "\n������� ������ ������� (Y/N) ? ";
			std::cin >> str;

			if (!str.compare("N")) {
				std::cout << "�������! ��� ������: ";
				print_dynamic_array(arr, sizeLogic, sizeFull);
				break;
			}
			else if (!str.compare("Y")) {
				if (sizeLogic == 0) {
					std::cout << "���������� ������� ������ �������, ��� ��� ������ ������.�� ��������!" << std::endl;
					break;
				}
				else {
					remove_dynamic_array_head(arr, sizeLogic, sizeFull);
					std::cout << "������������ ������: ";
					print_dynamic_array(arr, sizeLogic, sizeFull);
				}
			}
		} while (1);
	}
	delete[] arr;

	return 0;
}