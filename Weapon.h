#pragma once
#include <string>

using std::string;

class Weapon
{
public:
	Weapon();
	~Weapon();

	virtual float GetDamage() = 0;
	virtual string GetName() = 0;
};

