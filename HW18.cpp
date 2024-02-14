//
//	������ �������� 18
// 
//	 �������� ������� ���� ��������� Character �� �������� 
//		- void SetWeapon(Weapon* weapon); �� ����� ���������
//		- Weapon* GetWeapon() const; �� ����� ��������, �� �� ����� � ���������
// 
//	 �������� ������� ���� Weapon �� ����� ������������ ��������
//		- float GetDamage() = 0; ������� �������� ����� ������
//		- string GetName() = 0; ������� ����� ������
//	
//	 �������� �����-������� ����� ���� ������
//		
//	 �������� �� �������:
// 
//	 ���������� ����� DamageModifier � ����� � ������� ����������� �����
//		- float CalculateDamage(float CurrentHealth, float Damage) = 0;
// 
//	 �������� ������� ����� ����� �� ����� ������ ����������� �����. ���������:
//		- MultiplicationDamageModifier(float multiplicator) � ���� ���� ������� �����
//		- AdditionDamageModifier(float addition) � ���� ���� ����/������  ����� �� ������ (��� �� ����� ����)
//		- ParityDamageModifier(float multiplicator) � ���� ���� ������� ���� ���� ������� �� ���� �������
//	
//	 ������ � ���� ��������� ������� 
//		- float GetModifiedDamage(); ������� ������������ ����� �� ����
//		
//   ���������� �ᒺ��� ����� ����, � �������� ��������� �� � ��������
//	 ����� ���� � ������ ������ ������ ������� ���� ������� ������, �� � ���� ���� ����� �� �������
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

	Character* warrior = new Character(); // ���� � sword + ���� ���� ������� �����
	Character* thief = new Character(); // ���� � dagger + ���� ���� ���� ����� �� ������
	Character* shadow = new Character(); // ���� � dagger + ���� ���� ������ ����� �� ������
	Character* empty = new Character(); // ������ �������� ��� ����� �� �������


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

	// ��� ������ ������
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
	
	// ������� ������������ 
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

	// ��������� �� �� ������������
	delete warrior, thief, empty, sword, dagger, thief, mdm, adm_add10, adm_substruct6;
}