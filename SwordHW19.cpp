#include "SwordHW19.h"

SwordHW19::SwordHW19() {
	this->m_name = "Sword";
	this->m_damage = 1;
	this->m_damageModifier = {};
}

SwordHW19::SwordHW19(string name) : SwordHW19() {
	this->m_name = name;
}

SwordHW19::SwordHW19(string name, float damage) : SwordHW19(name) {
	this->m_damage = damage;
}

SwordHW19::SwordHW19(string name, float damage, shared_ptr<DamageModifier>& damageModifier) : SwordHW19(name, damage) {
	this->m_damageModifier = damageModifier;
}

string SwordHW19::GetName() {
	return m_name;
}

float SwordHW19::GetDamage() {
	if (shared_ptr<DamageModifier> sharedDmgModifirer = m_damageModifier.lock()) {
		return sharedDmgModifirer->CalculateDamage(m_damage);
	}
	return m_damage;
}