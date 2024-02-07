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

/*	Заповнює пустий вектор пустими структурами персонажей
*	@param vec вектор який наповнити
*	@param quantity кількість персонажей яка буде добавлена
*/	
void FillVectorCharacterStruct(std::vector<CharacterStruct>& vec, int quantity);

//	@return повертає випадковий класс
chClass randClass();

/*	Заповнює вектор рандомними значеннями для персонажей
*	@param vec вектор який потрібно заповнити
*/
void FillVectorRandomCharacter(std::vector<CharacterStruct>& vec);

/*	Виводить в консоль всіх персонажей в середені вектора
*	@param vec вектор структур <CharacterStruct>
*/
void ShowAllCharactersInVector(const std::vector<CharacterStruct>& vec);

/*	Виводить ID сильнішого персонажу
*	@param vec вектор структур <CharacterStruct> в якому шукати
*	@return int ID персонажу, якщо такого немає то -1
*/	
int StrongestCharacterInArray(const std::vector<CharacterStruct>& vec);

/*	Виводить в консоль найсильнішого в кожному класі
* 	@param vec вектор структур <CharacterStruct> в якому шукати
*/
void ShowStrongestCharactersInUnicClass(const std::vector<CharacterStruct>& vec);

/*	Виводить в консоль інформацію про персонажа
*	@param character приймає структуру <CharacterStruct> персонажа
*/
void PrintCharacter(const CharacterStruct& character);




