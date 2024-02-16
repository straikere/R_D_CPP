// 
//  ������ �������� 13
// 
//  1.�������� ��������, ��� ������ � ����������, ���� ��� ��������� ��������� ��:
//  
//  *���
//  *ʳ������ �������
//  *����(���� � ���� �� ���� : ���, ���)
//  
//  
//  2.���� � ��������� � ������� ��������� �������� �����, ��� ����� ��������� �����.
//  
//  *���� ���� ��������� ���, �� ����� ����� ����� �������� ������� ����� �� ������
//  *���� ���� ��������� ���, �� ����� ������� ����� �������� ������� �����, � ���� �� �������� �����
//  
//  
//  3.�������� �� ������� :
//  
//  *������ �� ��������� �������� �����������
//  *�� ��������� ���� ������ ������� :
//  
//  
//  ���� � ���� ���������� ����� 30 % �������, �� ��������� ���� ���� ���������� �� �������� ��������� �����������
//  ���� ���� ���������� ����� ����� �� 2����������, �� � 50 % ���������, �� ���� ���� �� �������� �������
//

#include <iostream>
#include <ctime>
#include "HW13.h"

using std::cin, std::cout;

void Homework13() {

    //regular random
    srand(time(NULL));

    std::string CharacterName;
    cout << "������ ��� ���������: ";
    cin >> CharacterName;

    //default Character Stats
    float CharacterHealth = 100;
    float CharacterMaxHealth = 100;

    cout << "������ ������'� ���������: ";
    cin >> CharacterHealth;
    CharacterMaxHealth = CharacterHealth;

    CharacterClass MyCharacterClass = ChoseClass();

    bool IsDead = false;
    int Damage = 0;
    float Procentage = 100;
    float Power;

    switch (MyCharacterClass)
    {
    case Mage:
        cout << "����� ��������� ��� (����� ����� ����� �������� ������� �����)\n";
        cout << "���� ����� ����� �� 2����������, �� � 50% ���������, �� ���� ���� �� �������� �������\n";

        //Mage power
        Power = 10;

        cout << "���� ��������� = " << Power << '\n';

        while (!IsDead)
        {
            cout << "--------------------------------------------------------\n" ;
            cout << "������ ����� ��� ������ ���������: ";
            cin >> Damage;

            //���� ����� �����
            DamageToMage(Damage,CharacterHealth,Power);

            //������� ���� ��������� �����
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //������?
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "� ��������� ���������� " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, �� = " << CharacterHealth << '\n';
            }
        }
        break;

    case Warrior:
        cout << "����� ��������� ��� (����� ������� ����� �������� ������� �����, � ���� �� �������� �����)\n";
        cout << "���� � ���� ����� 30% �������, �� ��������� ���� ���� ���������� �� �������� ��������� �����������\n";

        //��������� � ����
        Power = 10;

        cout << "���� ��������� = " << Power << '\n';

        while (!IsDead)
        {
            cout << "--------------------------------------------------------\n";
            cout << "������ ����� ��� ������ ���������: ";
            cin >> Damage;

            Procentage = DamageToWarrior(Damage,CharacterHealth,CharacterMaxHealth,Power);            

            //������?
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "� ��������� ���������� " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, �� = " << CharacterHealth << '\n';
            }
        }
        break;
    }

    cout << "--------------------------------------------------------\n";
    cout << "�� ������!\n";
    cout << "��'� ��������� " << CharacterName << '\n';
    cout << "����������� ������'� ��������� " << CharacterMaxHealth << '\n';
    cout << "The End!" << '\n';

}

CharacterClass ChoseClass() {
    int ChClassInt;
    CharacterClass ChClassStruct;
    while (true)
    {
        cout << "������� ���� ��������� 1 -- ���, 2 -- ���: ";
        cin >> ChClassInt;
        ChClassStruct = static_cast<CharacterClass>(ChClassInt);
        if (ChClassStruct < CharacterClass::MAX && ChClassStruct >= 1)
        {
            return ChClassStruct;
        }
        cout << "��� �� �����, �������� ��� ���\n";
    }
}

void DamageToMage(int& Damage, float &CharacterHealth,const float &Power) {
    if ((Damage % 2) == 0)
    {
        cout << "����� " << Damage << " �����, ����� = " << 2 * Damage << '\n';

        Damage = 2 * Damage;

        //���� ����� ����� 2*��������� � ��� ������� "rand() % 2" �� ������� ������� �� 0 �� 1 �� � 50% ���������
        if (Damage > (2 * Power) && rand() % 2)
        {
            cout << "�����! ��� �� �������� �����!\n";
        }
        else
        {
            CharacterHealth = CharacterHealth - Damage;
        }
    }
    else
    {
        cout << "����� " << Damage << " �� �����, ����� = " << Damage << '\n';

        //���� ����� ����� ��������� � ��� �������
        if (Damage > (2 * Power) && rand() % 2)
        {
            cout << "�����! ��� �� �������� �����!\n";
        }
        else
        {
            CharacterHealth = CharacterHealth - Damage;
        }
    }
}

float DamageToWarrior(int& Damage, float& CharacterHealth,const float &CharacterMaxHealth, const float &Power) {

    float Procentage;

    Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

    if ((Damage % 2) == 0)
    {
        cout << "����� " << Damage << " �����, ����� = " << 0 << '\n';
        return Procentage;
    }
    else
    {
        cout << "����� " << Damage << " �� �����, ����� = " << 3 * Damage << '\n';
        Damage = (3 * Damage);

        //���� ������ 30% ������'�
        if (Procentage < (30))
        {
            cout << "����� �������� �� " << Power;
            Damage = Damage - static_cast<int>(Power);

            //������ �� ��������� ��������
            if (Damage < 0)
            {
                Damage = 1;
            }
            cout << ", ����� = " << Damage << '\n';
        }
        CharacterHealth = CharacterHealth - Damage;
    }
    Procentage = (CharacterHealth / CharacterMaxHealth) * 100;
    return Procentage;
}