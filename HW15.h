#pragma once
#include <vector>

using std::vector;

enum chClass 
{ 
	Mage = 1,
	Archer,
	Healer,
	Warrior,
	MAX
};

struct CharacterStruct
{
	int id;
	chClass ch_class;
	float melee;
	float ranged;
};

/*	�������� ������ ������ ������� ����������� ����������
*	@param vec ������ ���� ���������
*	@param quantity ������� ���������� ��� ���� ���������
*/	
void FillVectorCharacterStruct(std::vector<CharacterStruct>& vec, int quantity);

//	@return ������� ���������� �����
chClass randClass();

/*	�������� ������ ���������� ���������� ��� ����������
*	@param vec ������ ���� ������� ���������
*/
void FillVectorRandomCharacter(std::vector<CharacterStruct>& vec);

/*	�������� � ������� ��� ���������� � ������� �������
*	@param vec ������ �������� <CharacterStruct>
*/
void ShowAllCharactersInVector(const std::vector<CharacterStruct>& vec);

/*	�������� ID ��������� ���������
*	@param vec ������ �������� <CharacterStruct> � ����� ������
*	@return int ID ���������, ���� ������ ���� �� -1
*/	
int StrongestCharacterInArray(const std::vector<CharacterStruct>& vec);

/*	�������� � ������� ������������ � ������� ����
* 	@param vec ������ �������� <CharacterStruct> � ����� ������
*/
void ShowStrongestCharactersInUnicClass(const std::vector<CharacterStruct>& vec);

/*	�������� � ������� ���������� ��� ���������
*	@param character ������ ��������� <CharacterStruct> ���������
*/
void PrintCharacter(const CharacterStruct& character);




