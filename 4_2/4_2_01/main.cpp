#include <iostream>
#include <iomanip>

// Вычисление числа Фибоначи
double fib(int numb) {
	if (numb <= 1) return numb;	
	else return fib(numb - 1) + fib(numb - 2);
}

int main() {
	setlocale(LC_ALL, "RUS");

	int tmp;

	do {
		std::cout << "Введите число: ";
		std::cin >> tmp;
		std::cout << std::fixed << std::setprecision(0) << "Число фибоначи: " << fib(tmp) << std::endl << std::endl;
	} while (1);

	return 0;
}