#include "Sword.h"
#include <memory>

using std::unique_ptr, std::make_unique;

Sword::Sword(string _Name, float _Damage, DamageModifier* Dmg) {
	DmgModifirer = Dmg;
	Name = _Name;
	Damage = _Damage;
}

Sword::Sword(string _Name = "Sword", float _Damage = 0, unique_ptr<DamageModifier> uniqDmgModifirer) {
	this->uniqDmgModifirer = move(uniqDmgModifirer);
	Name = _Name;
	Damage = _Damage;
}

//ўоб не порушувати принцип LSP але розширити класс Sword € зробив це
float Sword::GetDamage() {
	if (DmgModifirer) return DmgModifirer->CalculateDamage(Damage);
	if (uniqDmgModifirer) return uniqDmgModifirer->CalculateDamage(Damage);
	return Damage;
}

string Sword::GetName() {
	return Name;
}
