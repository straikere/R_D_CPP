#include "Character.h"

Character::Character(){
	
}

Character::~Character() {
	
}

void Character::SetWeapon(Weapon* _weapon) {
	weapon = _weapon;
}

Weapon* Character::GetWeapon() const {
	return weapon;
}

// Мені в голову прийшла тільки така реалізація
float Character::GetModifiedDamage() {
	if (DmgModifier)
	{
	return DmgModifier->CalculateDamage(weapon->GetDamage());
	}
	return weapon->GetDamage();
}

void Character::SetDamageModifier(DamageModifier* _DmgModifier) {
	DmgModifier = _DmgModifier;
}