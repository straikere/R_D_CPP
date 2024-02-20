#pragma once
#include "Weapon.h"
#include <memory>
#include <iostream>

using std::shared_ptr, std::weak_ptr, std::cout;

class UI_Weapon
{
public:
	UI_Weapon(const shared_ptr<Weapon>& weapon);
	~UI_Weapon() {};

	void PrintWeaponName();

private:

	weak_ptr<Weapon> m_Weapon;

};

