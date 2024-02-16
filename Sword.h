#pragma once
#include "Weapon.h"
#include "DamageModifier.h"
#include <memory>

using std::unique_ptr, std::make_unique;

class Sword :
    public Weapon
{
public:

    Sword(string _Name = "Sword", float _Damage = 0, DamageModifier* Dmg = {});
    Sword(string _Name = "Sword", float _Damage = 0, unique_ptr<DamageModifier> uniqDmgModifirer = make_unique<DamageModifier>() );
    ~Sword() {};

    float GetDamage() override;
    string GetName() override;

private:

    string Name;
    float Damage;
    DamageModifier* DmgModifirer{};
    unique_ptr<DamageModifier> uniqDmgModifirer{};

};

