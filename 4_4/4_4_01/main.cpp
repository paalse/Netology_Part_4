#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

	std::cout << "������������ ������: ";

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
	}
	return 0;
}