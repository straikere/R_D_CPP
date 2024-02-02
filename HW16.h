#pragma once
#include<string>
#include<map>
#include<vector>

struct MyStruct
{
	string clanName;
	string name;
	float power;

};

using std::string, std::map, std::vector;

int GetPlayerCount(const string& ClanName);

int ClanFight(const string& FirstClanName, const string& SecondClanName);