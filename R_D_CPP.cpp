// R_D_CPP.cpp 

#include <iostream>
#include <Windows.h>

using namespace std;

void Homework13();
void Homework14();

int switch_on;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout <<	"Домашнє завдання 13 -- 1\n"
			"Домашнє завдання 14 -- 2\n" << endl;

	cout << "Виберіть домашє завдання:";
	cin >> switch_on;
	switch (switch_on)
	{
	case 1 :
		Homework13();
		break;
	case 2 :
		Homework14();
		break;
	default:
		break;
	}

	return 0;
}
