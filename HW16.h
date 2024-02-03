#pragma once
#include<string>
#include<map>
#include<vector>
#include<iostream>

using std::string, std::map, std::vector;

struct chStruct
{
	string name;
	float power;
};

int GetPlayerCount(const string& ClanName);

int ClanFight(const string& FirstClanName, const string& SecondClanName);

void InputMenu();

void AddPlayerToTeam();