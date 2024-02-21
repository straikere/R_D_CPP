#include "CharacterHW19.h"
#include "SwordHW19.h"
#include <iostream>

void Homework20() {

	CharacterHW19 hero("Main Character");

	unique_ptr<Weapon> weapon = make_unique<SwordHW19>();
	unique_ptr<Weapon> weapon1 = make_unique<SwordHW19>();
	unique_ptr<Weapon> weaponForBoss = make_unique<SwordHW19>();

	hero.SetWeapon(weapon); //������ ���� ���
	hero.Reincarnation(); //������ ���� ���
	// �� ����� ���� ��� �� ����������
	hero.Reincarnation();
	hero.SetWeapon(weapon1);
	hero.Reincarnation();
	hero.ApplyDamage(300); //������ �� �������� �� �� �����

	std::cout << "\n---------Boss----------\n";

	CharacterHW19 boss("Butcher", 200, false);

	boss.SetWeapon(weaponForBoss);// �� �������� ������ �� First weapon �� �� �� �����
	boss.ApplyDamage(300); //������ �������� �� �� �� �����

	std::cout << "\n-----------------------\n";
}