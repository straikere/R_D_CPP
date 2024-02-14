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
	//ÿκωξ Damage ασδε β³δΊμνθμ
	return abs(Damage * multiplicator);
}