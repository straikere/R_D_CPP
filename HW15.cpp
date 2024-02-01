//
//	Домашнє завдання 15
// 
//	Створити свою структуру, в якій будуть наступні дані
//		- ID персонажа : int
//
//		- Клас персонажа : enum
//
//		- Сила близкьої (melee) атаки  : float
//
//		- Сила дальної (ranged) атаки : float
//
//	Створити функцію, яка буде приймати на вхід вектор даних структур, та повертати id найсильнішого персонажа. 
//		- Найсильніший – сума melee та ranged атак найбільша. 
//
//	Завдання із зірочкою: 
//		- Розробити функцію, яка поверне найсильнішого в кожному класі.
// 
//	
#include <iostream>
#include <vector>
#include <random>
#include "HW15.h"

static std::vector<chClass> ALL_CHARACTER_CLASSES({chClass::Archer,chClass::Healer, chClass::Mage, chClass::Warrior });
static std::random_device rd;

using namespace std;

void Homework15() {

	// створюємо вектор структур на heap 
	vector<CharacterStruct>* chArrPtr = new vector<CharacterStruct>;
	// заповнюємо вектор 10 пустими персонажами
	FillVectorCharacterStruct(*chArrPtr, 10);
	// заповнюємо пусті структури в векторі рандомними значеннями
	FillVectorRandomCharacter(*chArrPtr);
	// виводимо всіх наших персонажів
	ShowAllCharactersInVector(*chArrPtr);

	// ???
	PrintCharacter(chArrPtr->data());
	PrintCharacter(chArrPtr->data()+1);
	// equal
	PrintCharacter((*chArrPtr).data());
	PrintCharacter((*chArrPtr).data() + 1);

	//cout << endl;

	delete chArrPtr;
	chArrPtr = nullptr;

	//приклади роботи з структурою
	
	CharacterStruct gay;
	gay.id = 1;
	gay.ch_class = Archer;
	gay.melee = 4;
	gay.ranged = 11;
	PrintCharacter(&gay);
	
	CharacterStruct* yayPtr = new CharacterStruct();
	yayPtr->id = 500;
	yayPtr->ch_class = Archer;
	yayPtr->melee = 200;
	yayPtr->ranged = 32;

	PrintCharacter(yayPtr);

	delete yayPtr;
	yayPtr = nullptr;
	
}

//	Повертає випадковий класс
chClass randClass() {
	std::uniform_int_distribution<size_t> dis(1, ALL_CHARACTER_CLASSES.size() - 1);
	chClass randomClass = ALL_CHARACTER_CLASSES[dis(rd)];
	return randomClass;
}

//	Заповнює пустий вектор пустими структурами персонажей
void FillVectorCharacterStruct(std::vector<CharacterStruct>& vec, int quantity) {

	for (int i = 0; i < quantity; i++)
	{
		vec.push_back(CharacterStruct());
	}
}

//	Заповнює вектор рандомними значеннями для персонажей
void FillVectorRandomCharacter(std::vector<CharacterStruct>& vec) {

	std::uniform_real_distribution<float> distFloat(1.0f, 10.0f);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].id = i;
		vec[i].ch_class = randClass();
		vec[i].melee = distFloat(rd);
		vec[i].ranged = distFloat(rd);
	}
}

//	Виводить в консоль всіх персонажей в середені вектора
void ShowAllCharactersInVector(std::vector<CharacterStruct>& vec) {

	for (int i = 0; i < vec.size(); i++)
	{
		//
	}

}

//	Виводить в консоль інформацію про персонажа
void PrintCharacter(CharacterStruct* character) {

	std::cout << "ID: " << character->id << std::endl;
	std::cout << "Class: " << character->ch_class << std::endl;
	std::cout << "Melee: " << character->melee << std::endl;
	std::cout << "Ranged: " << character->ranged << std::endl;
	std::cout << "Power sum: " << character->ranged + character->melee << std::endl;
	std::cout << endl;

}








CharacterStruct FillCharacter(CharacterStruct& character) {

	std::uniform_int_distribution<int> distrib(1, 9);
	for (int i = 0; i < 10; i++)
	{
		std::cout << distrib(rd) << std::endl;
	}
	return character;
}

void FillCharacterTest() {

	std::uniform_int_distribution<int> distrib(1, 9);

	for (int i = 0; i < 10; i++)
	{
		std::cout << distrib(rd) << std::endl;	
	}
}

void FillCharacterTestFloat() {

	std::uniform_real_distribution<float> distrib(0.0f, 1.0f);

	for (int i = 0; i < 10; i++)
	{
		std::cout << distrib(rd) << std::endl;
	}
}


//characterArray.push_back(CharacterStruct());
//characterArray.push_back(CharacterStruct());
//characterArray[0].id = 123;
//characterArray[1].id = 124;

//stack !overflow 
//int* a = new int[500000000];
//delete[] a;
//a = nullptr;
