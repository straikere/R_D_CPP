#pragma once

class DamageModifier
{
public:
	virtual float CalculateDamage(float Damage) = 0; //Поки без CurrentHealth, я писав чому :D
};

