#pragma once
#include <memory>
#include "Weapon.h"
#include "DamageModifier.h"

using std::unique_ptr, std::make_unique;

class CharacterHW19
{
public:

	CharacterHW19(string Name, float Health = 100);
	~CharacterHW19() {};

	void SetWeapon(unique_ptr<Weapon>& weapon);
	unique_ptr<Weapon>& GetWeapon();

	void SetDamageModifier(unique_ptr<DamageModifier>& _DmgModifier);
	float GetModifiedDamage();
	void ApplyDamage(float Damage);
	float GetHealth() const;
	bool CharacterIsDead() const;
	void Reincarnation() { IsDead = false; Health = MaxHealth; };
	


private:

	string Name;
	bool IsDead;
	float MaxHealth{};
	float Health{};
	unique_ptr<Weapon> weapon{};
	unique_ptr<DamageModifier> DmgModifier{};

};

