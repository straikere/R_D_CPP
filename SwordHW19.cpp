#include "SwordHW19.h"

SwordHW19::SwordHW19(string name, float damage, unique_ptr<DamageModifier> damageModifier ) {
	this->m_name = name;
	this->m_damage = damage;
	this->m_damageModifier = move(damageModifier);
}

string SwordHW19::GetName() {
	return m_name;
}

float SwordHW19::GetDamage() {
	return m_damage;
}