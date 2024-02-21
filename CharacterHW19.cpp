#include "CharacterHW19.h"
#include <iostream>

using std::cout;

CharacterHW19::CharacterHW19(string Name, float Health, bool isHero) {
	IsDead = false;
	this->Health = Health;
	MaxHealth = this->Health;
	this->Name = Name;
	this->m_data = {};
	m_data.isHero = isHero;
	this->m_achievements = new Achievements();
	addObserver(m_achievements);
}
CharacterHW19::~CharacterHW19() {
	delete m_achievements; 
}

void CharacterHW19::SetWeapon(unique_ptr<Weapon>& weapon) {
	this->weapon = move(weapon);
	notify(m_data, Event::PIKUP);
}

unique_ptr<Weapon>& CharacterHW19::GetWeapon()
{
	return weapon;
}

float CharacterHW19::GetModifiedDamage() {
	return weapon->GetDamage();
}

void CharacterHW19::SetDamageModifier(shared_ptr<DamageModifier>& _DmgModifier) {
	DmgModifier = _DmgModifier;
}

void CharacterHW19::ApplyDamage(float Damage) {
	if (IsDead) {
		std::cout << "Caracter " << Name << " is already Dead!\n";
	}
	else
	{
		if (shared_ptr<DamageModifier> sharedDmgMoidifier = DmgModifier.lock())
		{
			Health = GetHealth() - (sharedDmgMoidifier->CalculateDamage(Damage));
		}
		else
		{
			Health -= Damage;
		}
		if (Health <= 0)
		{
			IsDead = true;
			std::cout << "Caracter " << Name << " is Dead!\n";
			notify(m_data, Event::DEAD);
		}
	}
}

float CharacterHW19::GetHealth() const {
	return Health;
}

bool CharacterHW19::CharacterIsDead() const {
	return IsDead;
};

string CharacterHW19::GetName() {
	return Name;
}

