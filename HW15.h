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

/*	Заповнює пустий вектор пустими структурами персонажей
*	@param vec вектор який наповнити
*	@param quantity кількість персонажей яка буде добавлена
*/	
void FillVectorCharacterStruct(std::vector<CharacterStruct>& vec, int quantity);

//	@return повертає випадковий класс
chClass randClass();

//
void FillVectorRandomCharacter(std::vector<CharacterStruct>& vec);

//	Виводить в консоль всіх персонажей в середені вектора
void ShowAllCharactersInVector(std::vector<CharacterStruct>& vec);

//	Виводить в консоль інформацію про персонажа
void PrintCharacter(CharacterStruct* character);



void FillCharacterTest();

void FillCharacterTestFloat();




