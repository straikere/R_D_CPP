#include "Character.h"

Character::Character(string Name, float Health){
	IsDead = false;
	this->Health = Health;
	MaxHealth = this->Health;
	this->Name = Name;
}

void Character::SetWeapon(Weapon* _weapon) {
	weapon = _weapon;
}

Weapon* Character::GetWeapon() const {
	return weapon;
}

float Character::GetModifiedDamage() {
		return weapon->GetDamage();
}

void Character::SetDamageModifier(DamageModifier* _DmgModifier) {
	DmgModifier = _DmgModifier;
}

void Character::ApplyDamage(float Damage) {
	if (IsDead) {
		std::cout << "Caracter " << Name << " is already Dead!\n";
	}
	else
	{
		if (DmgModifier)
		{
			Health = GetHealth() - (DmgModifier->CalculateDamage(Damage));
		}
		else
		{
			Health -= Damage;
		}
		if (Health <= 0) 
		{
			IsDead = true;
			std::cout << "Caracter " << Name << " is Dead!\n";
		}
	}
}

float Character::GetHealth() const {
	return Health;
}

bool Character::CharacterIsDead() const {
	return IsDead;
};