#pragma once
#include<string>

using std::string;

struct chStruct
{
	string name;
	float power;
};

/*	������� ������� ������� � ���� �� �� ������
*	@param ClanName ������ ����� �����
*	@return ������� ������� � ����,
*			-1 ���� ��'� �� ��������
*/
int GetPlayerCount(const string& ClanName);

/*	������� ��������� ������� �� �������
*	@param FirstClanName ������ ����� ����� �
*	@param SecondClanName ������ ����� ����� B
*	@return 0 ����,
*			1 ������ ������ (�) ����,
*			-1 ������ ������ (B) ����,
*			10 ���� � �����, 
*			11 ���� B �����
*/
int ClanFight(const string& FirstClanName, const string& SecondClanName);

//	���� ��� ���������� teamMap
void InputMenu();

//	���� ���� �� ������ � teamMap ������� ��� � ������
void AddPlayerToTeam();