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
#include <Windows.h>
#include <ctime>

using namespace std;

//enum ����� ������ ��������� � 1
enum CharacterClass
{
    Mage = 1,
    Warrior
};


void Homework13() {


    //���������� ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //�������� ������
    srand(time(NULL));

    //��'������ ����� �� ��'� ���������
    string CharacterName;

    cout << "������ ��� ���������: ";

    //������� ��'� ���������
    cin >> CharacterName;

    //��'������ ����� �� ������'� �� ����������� ������'� ��������� (�� ������������ 100)
    float CharacterHealth = 100, CharacterMaxHealth = 100;
    cout << "������ ������'� ���������: ";

    //������� ������'�
    cin >> CharacterHealth;

    //���� ������� = �������, ��� ���������� %
    CharacterMaxHealth = CharacterHealth;

    //���������� enum
    CharacterClass MyCharacterClass;

    //���������� ������ ����� ��� ������
    int CharacterClassInt;

    //���� ���� ��������� �� ���� �������� ����� ���������
    for (bool i = true; i == true;)
    {
        cout << "������� ���� ��������� 1 -- ���, 2 -- ���: ";
        cin >> CharacterClassInt;
        switch (CharacterClassInt)
        {
        case 1:
        {
            MyCharacterClass = Mage;
            i = false;
            break;
        }
        case 2:
        {
            MyCharacterClass = Warrior;
            i = false;
            break;
        }
        default:
            cout << "��� �� �����, �������� ��� ���" << endl;
            break;
        }

    }


    //����� ��� �����
    bool IsDead = false;

    //����� ��� �����
    int Damage = 0;

    //����� ��� �������
    float Procentage = 100;

    //����� ��� "���������"
    float Power;

    switch (MyCharacterClass)
    {
    case Mage:
        cout << "����� ��������� ��� (����� ����� ����� �������� ������� �����)" << endl;
        cout << "���� ����� ����� �� 2����������, �� � 50% ���������, �� ���� ���� �� �������� �������" << endl;

        //��������� � ����
        Power = 10;

        cout << "���� ��������� = " << Power << endl;

        //���� �� ������
        while (!IsDead)
        {
            cout << "--------------------------------------------------------" << endl;
            cout << "������ ����� ��� ������ ���������: ";
            cin >> Damage;

            //���� ����� �����
            if ((Damage % 2) == 0)
            {
                cout << "����� " << Damage << " �����, ����� = " << 2 * Damage << endl;
                Damage = 2 * Damage;

                //���� ����� ����� 2*��������� � ��� ������� "rand() % 2" �� ������� ������� �� 0 �� 1 �� � 50% ���������
                if (Damage > (2 * Power) && rand() % 2)
                {
                    cout << "�����! ��� �� �������� �����!" << endl;
                }
                else
                {
                    CharacterHealth = CharacterHealth - Damage;
                }
            }
            else
            {
                cout << "����� " << Damage << " �� �����, ����� = " << Damage << endl;

                //���� ����� ����� ��������� � ��� �������
                if (Damage > (2 * Power) && rand() % 2)
                {
                    cout << "�����! ��� �� �������� �����!" << endl;
                }
                else
                {
                    CharacterHealth = CharacterHealth - Damage;
                }
            }

            //���������� ������� ���� ��������� �����
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //���������� �� ������
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "� ��������� ���������� " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, �� = " << CharacterHealth << endl;
            }
        }
        break;

    case Warrior:
        cout << "����� ��������� ��� (����� ������� ����� �������� ������� �����, � ���� �� �������� �����)" << endl;
        cout << "���� � ���� ����� 30% �������, �� ��������� ���� ���� ���������� �� �������� ��������� �����������" << endl;

        //��������� � ����
        Power = 10;

        cout << "���� ��������� = " << Power << endl;

        //���� �� ������
        while (!IsDead)
        {
            cout << "--------------------------------------------------------" << endl;
            cout << "������ ����� ��� ������ ���������: ";
            cin >> Damage;

            //���������� ������� �� ��������� �����
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //���� ����� �����
            if ((Damage % 2) == 0)
            {
                cout << "����� " << Damage << " �����, ����� = " << 0 << endl;
            }
            else
            {
                cout << "����� " << Damage << " �� �����, ����� = " << 3 * Damage << endl;
                Damage = (3 * Damage);

                //���� ������ 30% ������'�
                if (Procentage < 30)
                {
                    cout << "����� �������� �� " << Power;
                    Damage = Damage - Power;

                    //������ �� ��������� ��������
                    if (Damage < 0)
                    {
                        Damage = 1;
                    }
                    cout << ", ����� = " << Damage << endl;
                }
                CharacterHealth = CharacterHealth - Damage;
            }

            //���������� ������� ���� ��������� �����
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //���������� �� ������
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "� ��������� ���������� " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, �� = " << CharacterHealth << endl;
            }
        }
        break;
    }

    //���� �� ��� �� �� ����� ������
    cout << "--------------------------------------------------------" << endl;
    cout << "�� ������!" << endl;
    cout << "��'� ��������� " << CharacterName << endl;
    cout << "����������� ������'� ��������� " << CharacterMaxHealth << endl;
    cout << "The End!" << endl;

}