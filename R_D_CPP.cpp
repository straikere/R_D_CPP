// R_D_CPP.cpp 

#include <iostream>
#include <Windows.h>

using std::cout, std::cin;

void Homework13();
void Homework14();
void Homework15();
void Homework16();
void Homework17();
void Homework18();
void Homework19();
void Homework20();

int switch_on;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout <<	"Домашнє завдання 13 -- 1\n"
			"Домашнє завдання 14 -- 2\n"
			"Домашнє завдання 15 -- 3\n"
			"Домашнє завдання 16 -- 4\n"
			"Домашнє завдання 17 -- 5\n"
			"Домашнє завдання 18 -- 6\n"
			"Домашнє завдання 19 -- 7\n"
			"Домашнє завдання 20 -- 8\n" << '\n';

	cout << "Виберіть домашє завдання: ";
	//cin >> switch_on;
	cout << '\n'; switch_on = 8;
	switch (switch_on)
	{
	case 1 :
		Homework13();
		break;
	case 2 :
		Homework14();
		break;
	case 3:
		Homework15();
		break;
	case 4:
		Homework16();
		break;
	case 5:
		Homework17();
		break;
	case 6:
		Homework18();
		break;
	case 7:
		Homework19();
		break;
	case 8:
		Homework20();
		break;
	default:
		break;
	}

	return 0;
}
