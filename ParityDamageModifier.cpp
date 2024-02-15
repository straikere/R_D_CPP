#include "ParityDamageModifier.h"
#include <cmath>

ParityDamageModifier::ParityDamageModifier(float multiplicator) {
	this->multiplicator = multiplicator;
	Toggle = true;
}

float ParityDamageModifier::CalculateDamage(float Damage) {
	if (Toggle)
	{
		Toggle = !Toggle;
		if (multiplicator == 0)
		{
			return Damage;
		}
		//���� Damage ���� ������
		return abs(Damage * multiplicator);
	}
	else
	{
		Toggle = !Toggle;
		return abs(Damage);
	}

	
}