#include <iostream>
#include "UI_Weapon.h"
#include "CharacterHW19.h"
#include "Dagger.h"
#include "SwordHW19.h"
#include "AdditionDamageModifier.h"
#include "MultiplicationDamageModifier.h"
#include <vector>

using std::cout;

void Homework19() {

	// Створення персонажів
	shared_ptr<CharacterHW19> warrior = make_shared<CharacterHW19>("Warrior");
	shared_ptr<CharacterHW19> thief = make_shared<CharacterHW19>("Thief");
	shared_ptr<CharacterHW19> shadow = make_shared<CharacterHW19>("Shadow");
	shared_ptr<CharacterHW19> empty = make_shared<CharacterHW19>("");

	// маємо на увазі, що будемо використовувати і в Character і в Weapon той самий модифікатор 
	shared_ptr<DamageModifier> mdm = make_shared<MultiplicationDamageModifier>(1.5);
	shared_ptr<DamageModifier> admAdd10 = make_shared<AdditionDamageModifier>(10);
	shared_ptr<DamageModifier> admRemove11 = make_shared<AdditionDamageModifier>(-11);
	

	// унікальна зброя
	unique_ptr<Weapon> sword = make_unique<SwordHW19>("BIG DESTRUCTOR",30, mdm);
	unique_ptr<Weapon> swordForThief = make_unique<SwordHW19>("Little Sword",11, admAdd10);
	unique_ptr<Weapon> dagger = make_unique<Dagger>("Fast penetrator", 15);

	// присвоювання зброї
	warrior->SetWeapon(sword);
	thief->SetWeapon(swordForThief);
	shadow->SetWeapon(dagger);

	// Просто повторення прикладу з лекції
	shared_ptr<Weapon> sharedSword = std::make_shared<SwordHW19>();
	UI_Weapon ui_weapon(sharedSword);
	ui_weapon.PrintWeaponName();

	// ось і плюс shared_ptr, тепер я їх зрозумів :3 до цього був vector<unique_ptr<CharacterHW19>> і це накладувало обмежання подальшого використовування warrior, thief і т.д.
	std::vector<weak_ptr<CharacterHW19>> characterVec;

	characterVec.push_back(warrior);
	characterVec.push_back(thief);
	characterVec.push_back(shadow);
	characterVec.push_back(empty);


	cout << "--------------------\n";


	// ось і приклад використання shared_ptr
	for (weak_ptr<CharacterHW19>& character : characterVec)
	{
		if (shared_ptr<CharacterHW19> shared_characer = character.lock())
		{
			if (shared_characer->GetWeapon())
			{
				cout << "Character Name " << shared_characer->GetName() << '\n';
				cout << "Weapon Name " << shared_characer->GetWeapon()->GetName() << '\n';
				cout << "Weapon Damage " << shared_characer->GetWeapon()->GetDamage() << '\n';
				cout << "--------------------\n";
			}
		}
	}

	// Ми все ще можемо використовувати якщо Character був би unique_ptr, то на строці 45-48 прийшлося використовувати move.
	// І в warrior вже не було данних
	cout << "HP Warrior " << warrior->GetHealth() << '\n';
	
	//Нова зброя зі старим модифікатором
	unique_ptr<Weapon> newSword = make_unique<SwordHW19>("NEW SWORD", 11, admAdd10);
	warrior->SetWeapon(newSword);

	cout << "--------------------\n";

	for (weak_ptr<CharacterHW19>& character : characterVec)
	{
		if (shared_ptr<CharacterHW19> shared_characer = character.lock())
		{
			if (shared_characer->GetWeapon())
			{
				cout << "Character Name " << shared_characer->GetName() << '\n';
				cout << "Weapon Name " << shared_characer->GetWeapon()->GetName() << '\n';
				cout << "Weapon Damage " << shared_characer->GetWeapon()->GetDamage() << '\n';
				cout << "--------------------\n";
			}
		}
	}

	cout << '\n';
}

