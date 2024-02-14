#include "AdditionDamageModifier.h"

AdditionDamageModifier::AdditionDamageModifier(float addition) {
	this->addition = addition;
}

float AdditionDamageModifier::CalculateDamage (float Damage) {
	float ret = Damage + addition;
	if (ret <= 0)
	{
		return 1; // шкода не мінусова і не нуль
	}
	return ret;
}
