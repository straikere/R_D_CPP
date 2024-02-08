//
//	Домашнє завдання 16
// 
//	Для симулятора міста розробіть клас Building із наступними змінними
//	
//		Id: int (повинен бути унікальний для всіх будівель)
//		MaxAge: int – максимальна кількість років, яка ця будівля простоїть
//		Initial Cost: int – початкова вартість будівлі
// 
//	В цього класса повинні бути наступні функції-члени:
//	
//	Int GetCost();
//		* Повертає поточну вартість будівлі. Із кожним роком вартість будівлі зменшується лінійно: 0 років – initial cost, 
//		  MaxAge років – 0$, MaxAge/2 – InitialCost/2
//	
//	void ToAge(int years);
//		* Виклик цієї функції повинен зістарити будівлю на year років
//		* Якщо будівля зістарилася більше, ніж її максимальний вік, то вона повинна викликати приватну фукцію Destroy();
// 
//	void Destroy();
//		* Приватна функція, яка в косноль повідомить будівля із яким id була знищенна
//	
//
#include "Building.h"
#include <iostream>
using std::cout;

void Homework17() {

	Building build1; //defoult 10 yeras, 10000$
	Building build2(14,30000);
	Building build3(5,1000);

	cout << "-----------------Стартові значення ціни-----------------\n";

	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n'; 
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n'; 
	
	cout << "---------------Зістарені на 10 13 5 років--------------\n";

	build1.ToAge(10);
	build2.ToAge(13);
	build3.ToAge(5);

	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n';
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n';

	cout << "---------------Зістарені ще на 5 1 1 рік--------------\n";

	build1.ToAge(5);
	build2.ToAge(1);
	build3.ToAge(1);
	
	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n';
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n';

	return;
}

