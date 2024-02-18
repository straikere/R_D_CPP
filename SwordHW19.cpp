#include "SwordHW19.h"

SwordHW19::SwordHW19(string name) {
	this->m_name = name;
	this->m_damage = 0;
	this->m_damageModifier = nullptr;
}

SwordHW19::SwordHW19(string name, float damage) : SwordHW19(name) {
	this->m_damage = 15;
}
SwordHW19::SwordHW19(string name, float damage, unique_ptr<DamageModifier>& damageModifier) : SwordHW19(name, damage) {
	this->m_damageModifier = move(damageModifier);
}

string SwordHW19::GetName() {
	return m_name;
}

float SwordHW19::GetDamage() {
	return m_damage;
}