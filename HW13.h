#pragma once

enum CharacterClass
{
    Mage = 1,
    Warrior,
    MAX
};

// ������� ��������� ������ ������������
CharacterClass ChoseClass();

/*  ����� �� ����
* 
*   ����� ����� ����� �������� ������� ����� �� ������
*   ����� ����� �� 2����������, �� � 50 % ���������, �� ���� ���� �� �������� �������
* 
*   @param Damage ����� ��� ������ �������
*   @param CharacterHealth ��������� ������'� ���������
*   @param Power �������� ���������
*/
void DamageToMage(int& Damage, float& CharacterHealth, const int& Power);

/*  ����� �� ����
* 
*   ����� ������� ����� �������� ������� �����, � ���� �� �������� �����
*   ���� ���������� ����� 30 % �������, �� ��������� ���� ���������� �� �������� ��������� �����������
* 
*   @param Damage ����� ��� ������ �������
*   @param CharacterHealth ��������� ������'� ���������
*   @param CharacterMaxHealth ����������� ������'� ���������
*   @param Power �������� ���������
* 
*   @return ������� �� ������� ��� ����������
*/
float DamageToWarrior(int& Damage, float& CharacterHealth, const float& CharacterMaxHealth, const int& Power);