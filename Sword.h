#pragma once
#include "Weapon.h"
class Sword :
    public Weapon
{
public:
    Sword(string _Name);
    ~Sword();
    float GetDamage();
    string GetName();

private:
    string Name;
};

