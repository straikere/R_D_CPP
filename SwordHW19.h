#pragma once
#include "Weapon.h"
#include "DamageModifier.h"
#include <memory>

using std::unique_ptr, std::make_unique, std::shared_ptr, std::weak_ptr;

class SwordHW19 :
    public Weapon
{
public:
    SwordHW19();
    SwordHW19(string name);
    SwordHW19(string name, float damage);
    SwordHW19(string name, float damage, shared_ptr<DamageModifier>& damageModifier);
    ~SwordHW19() {};

    string GetName() override;
    float GetDamage() override;

private:

    string m_name;
    float m_damage;
    weak_ptr<DamageModifier> m_damageModifier;

};

