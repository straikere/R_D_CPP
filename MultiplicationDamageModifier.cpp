#include "MultiplicationDamageModifier.h"
#include <cmath>

MultiplicationDamageModifier::MultiplicationDamageModifier(float _multiplicator) {
	multiplicator = _multiplicator;
}

float MultiplicationDamageModifier::CalculateDamage(float Damage) {
	if (multiplicator==0)
	{
		return Damage;
	}
	//���� Damage ���� ������
	return abs(Damage * multiplicator);
}