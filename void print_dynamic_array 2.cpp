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
	
	for (int counter = 0, i = 0;counter < logical_size;counter++) {
		std::cout << "Введите arr[" << counter << "]:";
		std::cin >> arr[i];
		i++;

	};
	print_dynamic_array(arr, logical_size, actual_size);

	std::cout << std::endl;

	std::cout << "Для завершения ввода наберите 99" << std::endl;

	for (int i = logical_size;logical_size < actual_size;logical_size++) {

		std::cout << "Введите элемент для добавления: ";
		std::cin >> arr[i];

		if (arr[i] == 99) {
			std::cout << "Спасибо!Ваш ";
			print_dynamic_array(arr, logical_size, actual_size);
			std::cout << std::endl;
			return 0;
		}
		else {
			print_dynamic_array(arr, logical_size, actual_size);
			std::cout << std::endl;
		};

		i++;
	};

	delete[] arr;

	return 0;
}