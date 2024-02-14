#pragma once
#include "Weapon.h"
class Dagger :
    public Weapon
{
public:
    Dagger(string _Name = "Dagger", float _Damage = 0);
    
    float GetDamage();
    string GetName();

private:
    string Name;
    float Damage;
};

