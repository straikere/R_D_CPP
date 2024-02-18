#include "Sword.h"

Sword::Sword(string _Name, float _Damage, DamageModifier* Dmg) {
	DmgModifirer = Dmg;
	Name = _Name;
	Damage = _Damage;
}

//ўоб не порушувати принцип LSP але розширити класс Sword € зробив це
float Sword::GetDamage() {
	if (DmgModifirer) return DmgModifirer->CalculateDamage(Damage);
	return Damage;
}

string Sword::GetName() {
	return Name;
}
