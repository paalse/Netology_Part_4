#include <iostream>
#include <iomanip>

// ���������� ����� ��������
double fib(int numb) {
	if (numb <= 1) return numb;	
	else return fib(numb - 1) + fib(numb - 2);
}

int main() {
	setlocale(LC_ALL, "RUS");

	int tmp;

	do {
		std::cout << "������� �����: ";
		std::cin >> tmp;
		std::cout << std::fixed << std::setprecision(0) << "����� ��������: " << fib(tmp) << std::endl << std::endl;
	} while (1);

	return 0;
}