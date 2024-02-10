#include "Sword.h"

Sword::Sword(string _Name) {
	Name = _Name;
}

Sword::~Sword() {

}

float Sword::GetDamage() {
	return 0;
}

string Sword::GetName() {
	return Name;
}