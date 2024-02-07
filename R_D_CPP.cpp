// R_D_CPP.cpp 

#include <iostream>
#include <Windows.h>

using std::cout, std::cin;

void Homework13();
void Homework14();
void Homework15();
void Homework16();

int switch_on;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout <<	"Домашнє завдання 13 -- 1\n"
			"Домашнє завдання 14 -- 2\n"
			"Домашнє завдання 15 -- 3\n"
			"Домашнє завдання 16 -- 4\n" << '\n';

	cout << "Виберіть домашє завдання: ";
	cin >> switch_on;
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
	default:
		break;
	}

	return 0;
}
