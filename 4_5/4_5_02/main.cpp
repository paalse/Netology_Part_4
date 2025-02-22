#include <iostream>

// Вывод элемента пирамиды
void printElementPyramid(int* arr, int currentPos) {
	int parrent = (currentPos - 1) / 2;
	int level = static_cast<int>(std::round(sqrt(currentPos)));
	std::string side = "";

	if (currentPos == 0) {
		side = "root";
	} else {
		if (currentPos % 2 == 0) {
			side = "right";
		} else {
			side = "left";
		}
	}

	std::cout << level << " " << side;
	if (currentPos != 0) { 
		std::cout << " (" << arr[parrent] << ") ";
	} else {
		std::cout << " ";
	}
	std::cout << arr[currentPos] << std::endl;
}


int main() {
	setlocale(LC_ALL, "RUS");

	int size = 6;
	int* pyramid = new int[10] {1, 3, 6, 5, 9, 8}; // {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}; 

	std::string str = "";
	int currentPos = 0;

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << pyramid[i] << " ";
	}

	std::cout << "\nПирамида:\n";
	for (int i = 0; i < size; i++) {
		printElementPyramid(pyramid, i);
	}

	do {
		std::cout << "Вы находитесь здесь: ";
		printElementPyramid(pyramid, currentPos);

		str = "";
		std::cout << "Введите команду: ";
		std::cin >> str;

		if (str == "exit") {
			break;
		} else if (str == "up") {
			if (currentPos != 0) {
				std::cout << "Ok\n";
				currentPos = (currentPos - 1) / 2;
			} else {
				std::cout << "Ошибка! Отсутствует родитель\n";
			}
		} else if (str == "left") {
			if ((2 * currentPos + 1) < size) {
				std::cout << "Ok\n";
				currentPos = 2 * currentPos + 1;
			} else {
				std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
			}
		} else if (str == "right") {
			if ((2 * currentPos + 2) < size) {
				std::cout << "Ok\n";
				currentPos = 2 * currentPos + 2;
			} else {
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
			}
		}
	} while (str != "exit");

	delete[] pyramid;

	return 0;
}