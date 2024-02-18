#pragma once
#include "Weapon.h"
#include "DamageModifier.h"
#include <memory>

using std::unique_ptr, std::make_unique, std::move;

class SwordHW19 :
    public Weapon
{
public:

    SwordHW19(string name = "Sword", float damage = 15, unique_ptr<DamageModifier> damageModifier = nullptr);
    ~SwordHW19() {};

    string GetName() override;
    float GetDamage() override;

private:

    string m_name;
    float m_damage;
    unique_ptr<DamageModifier> m_damageModifier;

};

