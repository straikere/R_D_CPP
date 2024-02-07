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

/*	повертає кількість гравців у клані за її назвою
*	@param ClanName приймає назву клану
*	@return кількість гравців у клані 
*			-1 якщо ім'я не знайдено
*/
int GetPlayerCount(const string& ClanName);

/*	повертає результат поєдинку між кланами
*	@param FirstClanName приймає назву клану А
*	@param SecondClanName приймає назву клану B
*	@return 0, якщо нічия
*			1, якщо переміг перший (А) клан
*			-1, якщо переміг другий (B) клан
*			10, якщо клану А неіснує 
*			11, якщо Клану B неіснує
*/
int ClanFight(const string& FirstClanName, const string& SecondClanName);

//	меню для заповнення teamMap
void InputMenu();

//	додає клан та гравця в teamMap викликає ввід з консолі
void AddPlayerToTeam();