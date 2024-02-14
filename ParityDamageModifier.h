#pragma once
#include "DamageModifier.h"
class ParityDamageModifier :
    public DamageModifier
{
public:

    ParityDamageModifier(float multiplicator);

    float CalculateDamage(float Damage);

private:

    float multiplicator;

};

