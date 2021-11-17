#include <iostream>

#include <Windows.h>
void task1();
void task2();
void task3();
void task4();
void task5();

int run() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
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

			case 2:
				task2();
				break;

			case 3:
				task3();
				break;

			case 4:
				task4();
				break;

			case 5:
				task5();
				break;

			default:
				std::cout<<"Такого задания нет\n";
				break;
		}
	}
	return 0;
}