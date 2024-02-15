#pragma once
#include "Weapon.h"
#include "DamageModifier.h"
class Sword :
    public Weapon
{
public:

    Sword(string _Name = "Sword", float _Damage = 0, DamageModifier* Dmg = {});
    ~Sword() {};

    float GetDamage() override;
    string GetName() override;

private:

    string Name;
    float Damage;
    DamageModifier* DmgModifirer{};

};

