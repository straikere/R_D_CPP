#pragma once
#include "Weapon.h"
class Dagger :
    public Weapon

{
public:
    Dagger();
    ~Dagger();

    float GetDamage();
    string GetName();
};

