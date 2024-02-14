#include "Dagger.h"

Dagger::Dagger(string _Name, float _Damage) {
	Name = _Name;
	Damage = _Damage;
}

float Dagger::GetDamage() {
	return Damage;
}

string Dagger::GetName() {
	return Name;
}