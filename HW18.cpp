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
#include "ParityDamageModifier.h"
#include <vector>


using std::cout;
using std::vector;

void Homework18() {

	Character* warrior = new Character("Sergo"); // ���� � sword
	Character* boss = new Character("SIDOROVICH"); // ���� � daggerForBoss
	Character* thief = new Character("ULTRAKILLER"); // ���� � dagger
	Character* empty = new Character(""); // ������ �������� ��� ����� �� �������

	DamageModifier* mdm = new MultiplicationDamageModifier(2); // ������� �� 2 �����
	DamageModifier* adm_add10 = new AdditionDamageModifier(10); // ���� 10 �� �����
	DamageModifier* adm_substruct6 = new AdditionDamageModifier(-6); // ����� 6 �����
	DamageModifier* parity = new ParityDamageModifier(1.5); // ����� ��� ������� ����� �� 1.5

	// DamageModifier� ����� ���� �� ����\������ �� �����, � ������� ������� ����� �� Sword ���� �� �� ����������� 
	Weapon* sword = new Sword("Destructor 9000",10, mdm); // ������� ������� ����� �� 2
	Weapon* goodSword = new Sword("Destructor 9000",10, parity); // ������� ������� ����� ����� ��� �� 1.5
	Weapon* daggerForBoss = new Sword("Gay DESTROYER", 23);
	Weapon* dagger = new Dagger("Little Needle", 5);
	

	// ������� ����� ����������
	warrior->SetWeapon(sword);
	boss->SetWeapon(daggerForBoss);
	thief->SetWeapon(dagger);


	// DamageModifier� ����� ���� �� ����\������ �� ��������� 
	warrior->SetDamageModifier(adm_substruct6); //������ ������ ����� �� 6
	thief->SetDamageModifier(adm_add10); //������ ������ ����� �� 10

	// �� � ������
	while (true)
	{
		warrior->ApplyDamage(boss->GetModifiedDamage());
		if (warrior->CharacterIsDead()) break;
		boss->ApplyDamage(warrior->GetModifiedDamage());
		if (boss->CharacterIsDead()) break;
	}

	// ��� ������ ������
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
			cout << "Weapon Damage " << character->GetWeapon()->GetDamage() << '\n'; //Damage � ����������� ������������ ���� �� �
			cout << "--------------------\n";
		}
	}
	
	boss->Reincarnation();
	warrior->Reincarnation();

	// ������� ����������� 
	warrior->SetDamageModifier(adm_add10); // ������ ������ ����� �� 10

	// �� ���� �� � ������
	while (true)
	{
		warrior->ApplyDamage(boss->GetModifiedDamage());
		if (warrior->CharacterIsDead()) break;
		boss->ApplyDamage(warrior->GetModifiedDamage());
		if (boss->CharacterIsDead()) break;
	}

	// ��������� �� �� ������������
	delete warrior, thief, empty, sword, dagger, mdm, adm_add10, adm_substruct6, boss, goodSword;
}