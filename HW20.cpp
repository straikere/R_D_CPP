#include "CharacterHW19.h"
#include "SwordHW19.h"
#include <iostream>

void Homework20() {

	CharacterHW19 hero("Main Character");

	unique_ptr<Weapon> weapon = make_unique<SwordHW19>();
	unique_ptr<Weapon> weapon1 = make_unique<SwordHW19>();
	unique_ptr<Weapon> weaponForBoss = make_unique<SwordHW19>();

	hero.SetWeapon(weapon); //ачівка буде тут
	hero.Reincarnation(); //ачівка буде тут
	// на цьому герої вже не відпрацюють
	hero.Reincarnation();
	hero.SetWeapon(weapon1);
	hero.Reincarnation();
	hero.ApplyDamage(300); //ачівка не відпрацює бо це герой

	std::cout << "\n---------Boss----------\n";

	CharacterHW19 boss("Butcher", 200, false);

	boss.SetWeapon(weaponForBoss);// не відпрацює ачівка за First weapon бо це не герой
	boss.ApplyDamage(300); //ачівка відпрацює бо це не герой

	std::cout << "\n-----------------------\n";
}