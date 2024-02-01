#pragma once
#include <iostream> 
#include <vector>

enum chClass 
{ 
	Mage = 1,
	Archer,
	Healer,
	Warrior 
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

//
void FillVectorRandomCharacter(std::vector<CharacterStruct>& vec);

//	�������� � ������� ��� ���������� � ������� �������
void ShowAllCharactersInVector(std::vector<CharacterStruct>& vec);

//	�������� � ������� ���������� ��� ���������
void PrintCharacter(CharacterStruct* character);



void FillCharacterTest();

void FillCharacterTestFloat();




