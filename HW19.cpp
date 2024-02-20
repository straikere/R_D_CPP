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

	// ��������� ���������
	shared_ptr<CharacterHW19> warrior = make_shared<CharacterHW19>("Warrior");
	shared_ptr<CharacterHW19> thief = make_shared<CharacterHW19>("Thief");
	shared_ptr<CharacterHW19> shadow = make_shared<CharacterHW19>("Shadow");
	shared_ptr<CharacterHW19> empty = make_shared<CharacterHW19>("");

	// ���� �� ����, �� ������ ��������������� � � Character � � Weapon ��� ����� ����������� 
	shared_ptr<DamageModifier> mdm = make_shared<MultiplicationDamageModifier>(1.5);
	shared_ptr<DamageModifier> admAdd10 = make_shared<AdditionDamageModifier>(10);
	shared_ptr<DamageModifier> admRemove11 = make_shared<AdditionDamageModifier>(-11);
	

	// �������� �����
	unique_ptr<Weapon> sword = make_unique<SwordHW19>("BIG DESTRUCTOR",30, mdm);
	unique_ptr<Weapon> swordForThief = make_unique<SwordHW19>("Little Sword",11, admAdd10);
	unique_ptr<Weapon> dagger = make_unique<Dagger>("Fast penetrator", 15);

	// ������������ ����
	warrior->SetWeapon(sword);
	thief->SetWeapon(swordForThief);
	shadow->SetWeapon(dagger);

	// ������ ���������� �������� � ������
	shared_ptr<Weapon> sharedSword = std::make_shared<SwordHW19>();
	UI_Weapon ui_weapon(sharedSword);
	ui_weapon.PrintWeaponName();

	// ��� � ���� shared_ptr, ����� � �� ������� :3 �� ����� ��� vector<unique_ptr<CharacterHW19>> � �� ����������� ��������� ���������� ���������������� warrior, thief � �.�.
	std::vector<weak_ptr<CharacterHW19>> characterVec;

	characterVec.push_back(warrior);
	characterVec.push_back(thief);
	characterVec.push_back(shadow);
	characterVec.push_back(empty);


	cout << "--------------------\n";


	// ��� � ������� ������������ shared_ptr
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

	// �� ��� �� ������ ��������������� ���� Character ��� �� unique_ptr, �� �� ������ 45-48 ��������� ��������������� move.
	// � � warrior ��� �� ���� ������
	cout << "HP Warrior " << warrior->GetHealth() << '\n';
	
	//���� ����� � ������ �������������
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

