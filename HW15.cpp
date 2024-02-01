//
//	������ �������� 15
// 
//	�������� ���� ���������, � ��� ������ ������� ���
//		- ID ��������� : int
//
//		- ���� ��������� : enum
//
//		- ���� ������� (melee) �����  : float
//
//		- ���� ������ (ranged) ����� : float
//
//	�������� �������, ��� ���� �������� �� ���� ������ ����� ��������, �� ��������� id ������������ ���������. 
//		- ����������� � ���� melee �� ranged ���� ��������. 
//
//	�������� �� �������: 
//		- ��������� �������, ��� ������� ������������ � ������� ����.
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

	// ��������� ������ �������� �� heap 
	vector<CharacterStruct>* chArrPtr = new vector<CharacterStruct>;
	// ���������� ������ 10 ������� �����������
	FillVectorCharacterStruct(*chArrPtr, 10);
	// ���������� ���� ��������� � ������ ���������� ����������
	FillVectorRandomCharacter(*chArrPtr);
	// �������� ��� ����� ���������
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

	//�������� ������ � ����������
	
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

//	������� ���������� �����
chClass randClass() {
	std::uniform_int_distribution<size_t> dis(1, ALL_CHARACTER_CLASSES.size() - 1);
	chClass randomClass = ALL_CHARACTER_CLASSES[dis(rd)];
	return randomClass;
}

//	�������� ������ ������ ������� ����������� ����������
void FillVectorCharacterStruct(std::vector<CharacterStruct>& vec, int quantity) {

	for (int i = 0; i < quantity; i++)
	{
		vec.push_back(CharacterStruct());
	}
}

//	�������� ������ ���������� ���������� ��� ����������
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

//	�������� � ������� ��� ���������� � ������� �������
void ShowAllCharactersInVector(std::vector<CharacterStruct>& vec) {

	for (int i = 0; i < vec.size(); i++)
	{
		//
	}

}

//	�������� � ������� ���������� ��� ���������
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
