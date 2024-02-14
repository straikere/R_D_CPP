#include "Sword.h"

Sword::Sword(string _Name, float _Damage) {
	Name = _Name;
	Damage = _Damage;
}

float Sword::GetDamage() {
	return Damage;
}

string Sword::GetName() {
	return Name;
}