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
#include "ParityDamageModifier.h"
#include <vector>


using std::cout;
using std::vector;

void Homework18() {

	Character* warrior = new Character("Sergo"); // буде з sword
	Character* boss = new Character("SIDOROVICH"); // буде з daggerForBoss
	Character* thief = new Character("ULTRAKILLER"); // буде з dagger
	Character* empty = new Character(""); // пустий чарактер для теста на помилки

	DamageModifier* mdm = new MultiplicationDamageModifier(2); // множить на 2 шкоду
	DamageModifier* adm_add10 = new AdditionDamageModifier(10); // додає 10 до шкоди
	DamageModifier* adm_substruct6 = new AdditionDamageModifier(-6); // віднімає 6 шкоди
	DamageModifier* parity = new ParityDamageModifier(1.5); // через раз множить шкоду на 1.5

	// DamageModifierи тепер діють як бафи\дебафи на зброю, в данному випадку тільки на Sword тому як він розширенний 
	Weapon* sword = new Sword("Destructor 9000",10, mdm); // множить вихідну шкоду на 2
	Weapon* goodSword = new Sword("Destructor 9000",10, parity); // множить вихідну шкоду через раз на 1.5
	Weapon* daggerForBoss = new Sword("Gay DESTROYER", 23);
	Weapon* dagger = new Dagger("Little Needle", 5);
	

	// вручаємо зброю персонажам
	warrior->SetWeapon(sword);
	boss->SetWeapon(daggerForBoss);
	thief->SetWeapon(dagger);


	// DamageModifierи тепер діють як бафи\дебафи на персонажа 
	warrior->SetDamageModifier(adm_substruct6); //зменшує вхідну шкоду на 6
	thief->SetDamageModifier(adm_add10); //збільшує вхідну шкоду на 10

	// бій з боссом
	while (true)
	{
		warrior->ApplyDamage(boss->GetModifiedDamage());
		if (warrior->CharacterIsDead()) break;
		boss->ApplyDamage(warrior->GetModifiedDamage());
		if (boss->CharacterIsDead()) break;
	}

	// для зручної роботи
	vector<Character*> characterVec;
	characterVec.push_back(warrior);
	characterVec.push_back(boss);
	characterVec.push_back(thief);
	characterVec.push_back(empty);

	cout << "--------------------\n";

	for (Character* character : characterVec)
	{
		if (character->GetWeapon())
		{
			cout << "Weapon Name " << character->GetWeapon()->GetName() << '\n';
			cout << "Weapon Damage " << character->GetWeapon()->GetDamage() << '\n'; //Damage з урахуванням модифікатора якщо він є
			cout << "--------------------\n";
		}
	}
	
	boss->Reincarnation();
	warrior->Reincarnation();

	// змінюємо модифікатор 
	warrior->SetDamageModifier(adm_add10); // збільшує вхідну шкоду на 10

	// ще один бій з боссом
	while (true)
	{
		warrior->ApplyDamage(boss->GetModifiedDamage());
		if (warrior->CharacterIsDead()) break;
		boss->ApplyDamage(warrior->GetModifiedDamage());
		if (boss->CharacterIsDead()) break;
	}

	// видаляємо те що настворювали
	delete warrior, thief, empty, sword, dagger, mdm, adm_add10, adm_substruct6, boss, goodSword;
}