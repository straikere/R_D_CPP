#pragma once
#include "Weapon.h"
#include "DamageModifier.h"
#include <iostream>

class Character
{
public:

	Character(string Name, float Health = 100);
	~Character() {};

	void SetWeapon(Weapon* weapon);
	void SetDamageModifier(DamageModifier* _DmgModifier);
	Weapon* GetWeapon() const;
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
	Weapon* weapon{};
	DamageModifier* DmgModifier{};

};

