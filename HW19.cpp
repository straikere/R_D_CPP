#include <iostream>
#include "CharacterHW19.h"
#include "Dagger.h"
#include "Sword.h"
#include "AdditionDamageModifier.h"
#include "MultiplicationDamageModifier.h"
#include <vector>

using std::cout, std::move;

void Homework19() {

	unique_ptr<CharacterHW19> warrior = make_unique<CharacterHW19>("Warrior");
	unique_ptr<CharacterHW19> thief = make_unique<CharacterHW19>("Thief");
	unique_ptr<CharacterHW19> shadow = make_unique<CharacterHW19>("Shadow");
	unique_ptr<CharacterHW19> empty = make_unique<CharacterHW19>("");

	unique_ptr<DamageModifier> mdm = make_unique<MultiplicationDamageModifier>(1.5);

	unique_ptr<Weapon> sword = make_unique<Sword>("BIG DESTRUCTOR",30, make_unique<MultiplicationDamageModifier>(2));
	unique_ptr<Weapon> swordForThief = make_unique<Sword>("Little Sword",11,mdm);
	unique_ptr<Weapon> dagger = make_unique<Dagger>("Fast penetrator", 15);



	warrior->SetWeapon(sword);
	thief->SetWeapon(dagger);
	shadow->SetWeapon(dagger);
	

	std::vector<unique_ptr<CharacterHW19>> characterVec;

	characterVec.push_back(move(warrior));
	characterVec.push_back(move(thief));
	characterVec.push_back(move(shadow));
	characterVec.push_back(move(empty));


	cout << "--------------------\n";

	for (unique_ptr<CharacterHW19>& character : characterVec)
	{
		if (character->GetWeapon())
		{
			cout << "Weapon Name " << character->GetWeapon()->GetName() << '\n';
			cout << "Weapon Damage " << character->GetWeapon()->GetDamage() << '\n';
			//cout << "Modified weapon damage " << character->GetModifiedDamage() << '\n';
			cout << "--------------------\n";
		}
	}


}

//character->SetCurrentHeals(CalculateDamage(character->GetCurrentHealth(), weapon-GetDamage()));

