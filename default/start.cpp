#include <iostream>

void task1();

int run() {
	bool finish = false;
	while (!finish) {
		int task = 0;
		if (true) {
			std::cout << "������� ����� �������\n";
			std::string temp;
			do {std::getline(std::cin, temp);} while(temp.empty());
			task = std::stoi(temp);
		}
		else {
			/* ��� ��������, �� ����� ��������� ����������� ������� ��������� � ������� false � ����� ������� �����.
			!!! ����� ����� ����� ��������� �� �������� ������� true*/
			task = 1;
			// ��� ���������� ������� ��������� finish = true
			finish = false;
		}
		std::cout<<"\n������� � "<<task<<"\n";
		std::cout<<"====================\n";

		switch (task) {
			case 0:
				return 0;

			case 1:
				task1();
				break;

			default:
				std::cout<<"������ ������� ���\n";
				break;
		}
	}
	return 0;
}