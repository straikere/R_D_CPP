#pragma once
#include "Weapon.h"
class Dagger :
    public Weapon
{
public:

    Dagger(string _Name = "Dagger", float _Damage = 0);
    ~Dagger() {};
    
    float GetDamage() override;
    string GetName() override;

private:

    string Name;
    float Damage;

};

