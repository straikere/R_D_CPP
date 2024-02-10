//
//	Домашнє завдання 18
// 
//	 Створити базовий клас Персонажа Character із методами 
//		- void SetWeapon(Weapon* weapon); дає вепон персонажу
//		- Weapon* GetWeapon() const; дає змогу дізнатися, що за вепон у персонажа
// 
//	 Створити базовий клас Weapon із двома абстрактними методами
//		- float GetDamage() = 0; повертає значення шкоди вепона
//		- string GetName() = 0; повертає назву вепона
//	
//	 Створити класи-нащадки різних видів вепонів
//		
//	 Завдання із зірочкою:
// 
//	 Реалізувати класс DamageModifier в якому є функція калькуляції урона
//		- float CalculateDamage(float CurrentHealth, float Damage) = 0;
// 
//	 Створити нащадків цього класу із різною логікою модифікації урона. Наприклад:
//		- MultiplicationDamageModifier(float multiplicator) – клас який множить шкоду
//		- AdditionDamageModifier(float addition) – клас який додає/зменшує  шкоду від вепона (але не менше нуля)
//		- ParityDamageModifier(float multiplicator) – клас який множить тількі парні запроси на зміну демеджа
//	
//	 Додати в клас персонажа функцію 
//		- float GetModifiedDamage(); повертає модифіковану шкоду від зброї
//		
//   Створювати об’єкти класів вище, і динамічно назначати їх в персонажі
//	 Тобто якщо я захочу змінити демедж модифаєр після якогось інпуту, то в мене буде змога це зробити
// 
//

#include <iostream>
#include "Character.h"

#include "Sword.h"
#include "Dagger.h"
using std::cout;

void Homework18() {

	Sword Atlanta("SSS");

	cout << "Name " << Atlanta.GetName() << '\n';
	cout << "Damage " << Atlanta.GetDamage() << '\n';

	Character test,test1,ttt;
	Weapon* swrd = new Sword("sss");
	Weapon* dgr = new Dagger;

	test.SetWeapon(swrd);
	test1.SetWeapon(dgr);

	cout << "Weapon Name " << test.GetWeapon()->GetName() << '\n';
	cout << "Weapon Name " << test1.GetWeapon()->GetName() << '\n';

	cout << "Weapon Name " << ttt.GetWeapon()<< '\n';

	
}