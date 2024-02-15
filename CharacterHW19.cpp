#include "CharacterHW19.h"

CharacterHW19::CharacterHW19() {

}

CharacterHW19::~CharacterHW19() {

}

void CharacterHW19::SetWeapon(unique_ptr<Weapon>& weapon) {
	this->weapon = move(weapon);
}

unique_ptr<Weapon>& CharacterHW19::GetWeapon()
{
	return weapon;
}
