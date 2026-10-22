#include <iostream>
#include <windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	
	std::cout << "Динамический массив: ";

	for (int i = 0;i < actual_size;i++) {

		if (arr[i] != 0) {
			std::cout << arr[i] << " ";
		}
		else {
			std::cout << "_" << " ";
		};
	};
};

int main() {

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::setlocale(LC_ALL, "ru_RU.UTF-8");

	int actual_size = 0;
	int logical_size = 0;

	std::cout << "Введите фактичеcкий размер массива: ";
	std::cin >> actual_size;

	if (actual_size < 0) {

		std::cout << "Значение должно быть положительным" << std::endl;
		return 0;
	}

	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;

	if (logical_size < 0) {

		std::cout << "Значение должно быть положительным" << std::endl;
		return 0;
	}

	if (logical_size > actual_size) {

		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
		return 0;
	}

	int* arr = new int[actual_size] {};
	int counter = 0;
	for (int counter = 0,i = 0;counter < logical_size;counter++) {
		std::cout << "Введите arr[" << counter << "]:";
		std::cin >> arr[i];
		i++;

	};
	print_dynamic_array(arr, logical_size, actual_size);

	delete[] arr;

	return 0;
}