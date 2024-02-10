#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::SetWeapon(Weapon* weapon) {

	wepon = weapon;
}

Weapon* Character::GetWeapon() const {

	return wepon;
};