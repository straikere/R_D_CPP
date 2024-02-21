#pragma once
#include <memory>
#include "Weapon.h"
#include "DamageModifier.h"
#include "Achievements.h"
#include "Subject.h"

using std::unique_ptr, std::make_unique, std::shared_ptr, std::make_shared, std::weak_ptr;

class CharacterHW19 : public Subject
{
public:

	CharacterHW19(string Name, float Health = 100, bool isHero = true);
	~CharacterHW19();

	void SetWeapon(unique_ptr<Weapon>& weapon);
	unique_ptr<Weapon>& GetWeapon();
	void SetDamageModifier(shared_ptr<DamageModifier>& _DmgModifier);
	float GetModifiedDamage();
	void ApplyDamage(float Damage);
	float GetHealth() const;
	bool CharacterIsDead() const;
	void Reincarnation() { IsDead = false; Health = MaxHealth; notify(m_data, Event::SKILL_USE); };
	string GetName();

private:

	string Name;
	bool IsDead;
	float MaxHealth{};
	float Health{};
	unique_ptr<Weapon> weapon{};
	weak_ptr<DamageModifier> DmgModifier{};
	Achievements* m_achievements;
	EventData m_data;

};

