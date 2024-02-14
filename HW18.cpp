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
#include "MultiplicationDamageModifier.h"
#include "AdditionDamageModifier.h"
#include <vector>


using std::cout;
using std::vector;

void Homework18() {

	Character* warrior = new Character(); // буде з sword + клас який множить шкоду
	Character* thief = new Character(); // буде з dagger + клас який додає шкоду від вепона
	Character* shadow = new Character(); // буде з dagger + клас який зменшує шкоду від вепона
	Character* empty = new Character(); // пустий чарактер для теста на помилки


	Weapon* sword = new Sword("Destructor 9000",10);
	Weapon* dagger = new Dagger("Little Needle", 5);

	warrior->SetWeapon(sword);
	thief->SetWeapon(dagger);
	shadow->SetWeapon(dagger);

	DamageModifier* mdm = new MultiplicationDamageModifier(2);
	DamageModifier* adm_add10 = new AdditionDamageModifier(10);
	DamageModifier* adm_substruct6 = new AdditionDamageModifier(-6);

	warrior->SetDamageModifier(mdm);
	thief->SetDamageModifier(adm_add10);
	shadow->SetDamageModifier(adm_substruct6);

	// для зручної роботи
	vector<Character*> characterVec;
	characterVec.push_back(warrior);
	characterVec.push_back(thief);
	characterVec.push_back(shadow);
	characterVec.push_back(empty);

	cout << "--------------------\n";

	for (Character* character : characterVec)
	{
		if (character->GetWeapon())
		{
			cout << "Weapon Name " << character->GetWeapon()->GetName() << '\n';
			cout << "Weapon Damage " << character->GetWeapon()->GetDamage() << '\n';
			cout << "Modified weapon damage " << character->GetModifiedDamage() << '\n';
			cout << "--------------------\n";
		}
	}
	
	// змінюємо модифікатори 
	warrior->SetDamageModifier(adm_substruct6); 
	thief->SetDamageModifier(mdm);
	shadow->SetDamageModifier(adm_add10);

	cout << "--------------------\n";

	for (Character* character : characterVec)
	{
		if (character->GetWeapon())
		{
			cout << "Weapon Name " << character->GetWeapon()->GetName() << '\n';
			cout << "Weapon Damage " << character->GetWeapon()->GetDamage() << '\n';
			cout << "Modified weapon damage " << character->GetModifiedDamage() << '\n';
			cout << "--------------------\n";
		}
	}

	// видаляємо те що настворювали
	delete warrior, thief, empty, sword, dagger, thief, mdm, adm_add10, adm_substruct6;
}