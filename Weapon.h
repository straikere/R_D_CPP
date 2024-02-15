#pragma once
#include <string>

using std::string;

class Weapon {
public:
	virtual float GetDamage() = 0;
	virtual string GetName() = 0;
	virtual ~Weapon() {};
};

