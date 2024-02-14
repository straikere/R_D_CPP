#pragma once
#include "Weapon.h"
#include "DamageModifier.h"

class Character
{
public:

	Character();
	~Character();

	void SetWeapon(Weapon* weapon);
	void SetDamageModifier(DamageModifier* _DmgModifier);
	Weapon* GetWeapon() const;
	float GetModifiedDamage();

private:

	Weapon* weapon{};
	DamageModifier* DmgModifier{};

};

