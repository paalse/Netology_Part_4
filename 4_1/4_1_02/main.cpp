#include <iostream>

int cnt(int* arr, int size, int numb) {

	int left = 0;
	int right = size - 1;
	int mid;
	int res;

	while (left <= right) {
		mid = (left + right) / 2; // ��������� ������ �������� �������

		if (arr[mid] == numb && arr[mid + 1] != numb) break; // ���� ����� ������� � ��������� ����� � ������� ���������� �� �������� �� ������� �� �����
		if (arr[mid] > numb) right = mid - 1; // ��������� � ����� ����� ������ ������
		else left = mid + 1;
	}

	if (arr[mid] > numb) res = size - mid;	// � ������ ���� ������� ����� �� ����� ��������� � �������� � �������
	else res = size - 1 - mid;

	return res;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
	int input_numb = 0;

	do {
		std::cout << "������� ����� �������: ";
		std::cin >> input_numb;

		std::cout << "���������� ��������� � ������� �������, ��� " << input_numb << ": " << cnt(arr, sizeof(arr) / sizeof(arr[0]), input_numb) << std::endl;
	} while (1);

	return 0;
}