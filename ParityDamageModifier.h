#pragma once
#include "DamageModifier.h"
class ParityDamageModifier :
    public DamageModifier
{
public:

    ParityDamageModifier(float multiplicator);
    ~ParityDamageModifier() {};

    float CalculateDamage(float Damage) override;

private:

    float multiplicator;
    bool Toggle;

};

