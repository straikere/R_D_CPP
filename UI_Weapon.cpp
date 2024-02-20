#include "UI_Weapon.h"


UI_Weapon::UI_Weapon(const shared_ptr<Weapon>& weapon) {
	m_Weapon = weapon;
}

void UI_Weapon::PrintWeaponName() {
	if (shared_ptr<Weapon> sharedWeapon = m_Weapon.lock())
	{
		cout << "Weapon Name " << sharedWeapon->GetName() << '\n';
	}
}

