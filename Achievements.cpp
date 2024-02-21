#include "Achievements.h"
#include <iostream>

using std::cout;

void Achievements::onNotify(const EventData& data, Event event) {
	switch (event)
	{
	case Event::DEAD:
		if (!data.isHero && !m_BossIsDead)
		{
			m_BossIsDead = true;
			unlock(Achievement::BossIsDead);
		}
		break;
	case Event::SKILL_USE:
		if (data.isHero && !m_secondLife)
		{
			m_secondLife = true;
			unlock(Achievement::SecondLife);
		}
		break;
	case Event::PIKUP:
		if (data.isHero && !m_FirstWeapon)
		{
			m_FirstWeapon = true;
			unlock(Achievement::FirstWeapon);
		}
		break;
	default:
		break;
	}
}

void Achievements::unlock(Achievement achievement) {
	switch (achievement)
	{
	case Achievement::BossIsDead:
		cout << "\nAchievement Get: You Kill The Boss!\n";
		break;
	case Achievement::SecondLife:
		cout << "\nAchievement Get: You are reincarnated!\n";
		break;
	case Achievement::FirstWeapon:
		cout << "\nAchievement Get: Your pickup first weapon!\n";
		break;
	default:
		break;
	}
}