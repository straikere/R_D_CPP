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