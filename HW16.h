#pragma once
#include<string>

using std::string;

struct chStruct
{
	string name;
	float power;
};

/*	повертає кількість гравців у клані за її назвою
*	@param ClanName приймає назву клану
*	@return кількість гравців у клані,
*			-1 якщо ім'я не знайдено
*/
int GetPlayerCount(const string& ClanName);

/*	повертає результат поєдинку між кланами
*	@param FirstClanName приймає назву клану А
*	@param SecondClanName приймає назву клану B
*	@return 0 нічия,
*			1 переміг перший (А) клан,
*			-1 переміг другий (B) клан,
*			10 клан А неіснує, 
*			11 клан B неіснує
*/
int ClanFight(const string& FirstClanName, const string& SecondClanName);

//	меню для заповнення teamMap
void InputMenu();

//	додає клан та гравця в teamMap викликає ввід з консолі
void AddPlayerToTeam();