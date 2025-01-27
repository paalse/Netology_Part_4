#include <iostream>
#include <iomanip>
#include <map>


double fib(const int& numb, std::map<int, double>& fibArray) {
	double res;

	if (numb <= 1) return numb;
	else {
		auto fibFound = fibArray.find(numb);
		if (fibFound != fibArray.end())
		{
			return fibFound->second;
		}
		else {
			res = fib(numb - 1, fibArray) + fib(numb - 2, fibArray);
			fibArray.insert(std::make_pair(numb, res));
			return res;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	int tmp;
	std::map<int, double> fibArray = {}; // Массив чисел Фибоначи


	do {
		std::cout << "Введите число: ";
		std::cin >> tmp;
		std::cout << std::fixed << std::setprecision(0) << "Число фибоначи: " << fib(tmp, fibArray) << std::endl << std::endl;
	} while (1);

	return 0;
}