#pragma once
#include "DamageModifier.h"
class AdditionDamageModifier :
    public DamageModifier
{
public:

    AdditionDamageModifier(float addition);

    float CalculateDamage (float Damage);

private:

    float addition;

};

