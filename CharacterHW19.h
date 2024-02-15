#pragma once
#include <memory>
#include "Weapon.h"
#include "DamageModifier.h"

using std::unique_ptr, std::make_unique;

class CharacterHW19
{
public:

	CharacterHW19();
	~CharacterHW19();

	void SetWeapon(unique_ptr<Weapon>& weapon);
	unique_ptr<Weapon>& GetWeapon();


private:
	
	unique_ptr<Weapon> weapon{};
	unique_ptr<DamageModifier> DmgModifier{};

};

