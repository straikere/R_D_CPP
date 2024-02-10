#pragma once
#include "Weapon.h"

class Character
{
public:
	Character();
	~Character();

	void SetWeapon(Weapon* weapon);
	Weapon* GetWeapon() const;

private:

	Weapon* wepon;
};

