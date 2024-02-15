#pragma once
#include "DamageModifier.h"
class MultiplicationDamageModifier :
    public DamageModifier
{
public:

    MultiplicationDamageModifier(float _multiplicator);
    ~MultiplicationDamageModifier() {};

    float CalculateDamage(float Damage);

private:

    float multiplicator;

};

