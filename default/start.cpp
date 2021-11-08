#include <iostream>

void task1();

int run() {
	bool finish = false;
	while (!finish) {
		int task = 0;
		if (true) {
			std::cout << "Введите номер задания\n";
			std::string temp;
			do {std::getline(std::cin, temp);} while(temp.empty());
			task = std::stoi(temp);
		}
		else {
			/* Для удобства, во время написания конкретного задания поставьте в условии false и номер задания здесь.
			!!! Важно перед перед отправкой на проверку вернуть true*/
			task = 1;
			// Для единичного запуска поставьте finish = true
			finish = false;
		}
		std::cout<<"\nЗадание № "<<task<<"\n";
		std::cout<<"====================\n";

		switch (task) {
			case 0:
				return 0;

			case 1:
				task1();
				break;

			default:
				std::cout<<"Такого задания нет\n";
				break;
		}
	}
	return 0;
}