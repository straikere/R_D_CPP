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
#include <map>
#include <string>
#include "HW15.h"

static std::random_device rd;

using std::cout, std::endl, std::vector;

void Homework15() {

	// ��������� ������ 
	vector<CharacterStruct> CharacterArray;

	// ���������� ������ 10 ������� �����������
	FillVectorCharacterStruct(CharacterArray, 10);

	// ���������� ���� ��������� � ������ ���������� ����������
	FillVectorRandomCharacter(CharacterArray);
	cout << endl;

	// �����������
	cout << "����������� �������� �� ID: " << StrongestCharacterInArray(CharacterArray) << '\n';

	//�������� � ������� ������������ � ������� ����
	ShowStrongestCharactersInUnicClass(CharacterArray);

	// �������� ��� ����� ���������
	ShowAllCharactersInVector(CharacterArray);
}

//	������� ���������� �����
chClass randClass() {
	std::vector<chClass> ALL_CHARACTER_CLASSES({ chClass::Archer,chClass::Healer, chClass::Mage, chClass::Warrior });

	std::uniform_int_distribution<size_t> dis(0, ALL_CHARACTER_CLASSES.size() - 1);
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
void ShowAllCharactersInVector(const std::vector<CharacterStruct>& vec) {

	for (int i = 0; i < vec.size(); i++)
	{
		PrintCharacter(vec[i]);
	}

}

//	�������� ID ��������� ���������
int StrongestCharacterInArray(const vector<CharacterStruct>& vec) {

	float maxPower = 0;
	int id;

	for (int i = 0; i < vec.size(); i++)
	{
		if ((vec[i].melee + vec[i].ranged)>maxPower)
		{
			id = vec[i].id;
			maxPower = vec[i].melee + vec[i].ranged;
		}
	}
	if (maxPower==0) return -1;

	return id;
}

//	�������� � ������� ������������ � ������� ����
void ShowStrongestCharactersInUnicClass(const vector<CharacterStruct>& vec) {

	std::map<chClass, int> classMap;
	float dmg[chClass::MAX - 1]{};

	for (int i = 1; i < chClass::MAX; i++)
	{
		classMap.insert({static_cast<chClass>(i), -1});
	}

	for (int i = 0; i < vec.size(); i++)
	{
		switch (vec[i].ch_class)
		{
		case Mage:
			if ((vec[i].melee + vec[i].ranged) > dmg[0])
			{
				dmg[0] = vec[i].melee + vec[i].ranged;
				classMap[vec[i].ch_class] = vec[i].id;
			}
			break;
		case Archer:
			if ((vec[i].melee + vec[i].ranged) > dmg[1])
			{
				dmg[1] = vec[i].melee + vec[i].ranged;
				classMap[vec[i].ch_class] = vec[i].id;
			}
			break;
		case Healer:
			if ((vec[i].melee + vec[i].ranged) > dmg[2])
			{
				dmg[2] = vec[i].melee + vec[i].ranged;
				classMap[vec[i].ch_class] = vec[i].id;
			}
			break;
		case Warrior:
			if ((vec[i].melee + vec[i].ranged) > dmg[3])
			{
				dmg[3] = vec[i].melee + vec[i].ranged;
				classMap[vec[i].ch_class] = vec[i].id;
			}
			break;
		}


	}
	cout << "\n--��� ����������� � ����� �����--\n \n";
	for (auto& pair : classMap)
	{
		if (pair.second >= 0)
		{
			PrintCharacter(vec[pair.second]);
		}
	}
	cout << "------------------------------------\n \n";
}


//	�������� � ������� ���������� ��� ���������
void PrintCharacter(const CharacterStruct& character) {
	std::map<chClass, std::string> enumMap = { {Archer, "Archer"},{Healer, "Healer"}, {Mage, "Mage"}, { Warrior, "Warrior"} };
	std::string str;
	try
	{
		str = enumMap.at(character.ch_class);
	}
	catch (const std::exception&)
	{
		cout << "������a, ������� �� ���� ���� ���������. ��� �������� ���������� �������� � ��� ���� ��������\n";
		return;
	}
	std::cout << "ID: " << character.id << std::endl;
	std::cout << "Class: " << str << std::endl;
	std::cout << "Melee: " << character.melee << std::endl;
	std::cout << "Ranged: " << character.ranged << std::endl;
	std::cout << "Power sum: " << character.ranged + character.melee << std::endl;
	std::cout << endl;

}