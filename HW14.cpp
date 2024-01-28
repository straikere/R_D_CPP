//
//	������ �������� 14
// 
//	1. �������� ��������, ��� ������ � ���������� �����, �� ��������� ������� �����(��� ��������, ���� ����� �䒺���).
// 
//	2. ��������� ��� ��� ����� ������� ���������� :
// 
//	*ϳ� ����� �������� ��� ������� �������� �����
//	*ϳ� ����� �������� ��� ������� ��� �������� �����
//	*ϳ� ����� �������� ��� ������� ��������
//	*������ ������ ��� ������� ����� / ��������(� �������� ������� ������� �������� ������� ������ : ��������, ��� �����)
//	*�� � �����, ��� ����� ��� �� ������(�������� ������� ����)
//

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>


using namespace std;

void FillArrayHealOrDmg(vector<int>& arr);
bool ArrayIsValid(const vector<int>& arr);
void MaxDamage(const vector<int>& arr);
void MinDamage(const vector<int>& arr);
void Heal(const vector<int>& arr);
void AllDamageOrHeal(const vector<int>& arr, bool isDamage);
void NonDamageTarget(const vector<int>& arr);
void Menu(const vector<int>& HODArray);


void Homework14() {
    
    vector<int> HealOrDmgArray;

    FillArrayHealOrDmg(HealOrDmgArray);

    if (!ArrayIsValid(HealOrDmgArray)) return;

    Menu(HealOrDmgArray);
    
}

void Menu(const vector<int>& HODArray)
{
    int switch_on;
    cout << "����� ����������, ������� ������\n"
        "ϳ� ����� �������� ��� ������� �������� ����� -- 1\n"
        "ϳ� ����� �������� ��� ������� ��� �������� ����� -- 2\n"
        "ϳ� ����� �������� ��� ������� �������� -- 3\n"
        "������ ������ ��� ������� ����� / �������� -- 4\n"
        "�� � �����, ��� ����� ��� �� ������ -- 5\n"
        "����� -- 0\n"
        "��� ������: ";
    for (bool i = true; i == true;)
    {
        cin >> switch_on;
        cout << endl;
        switch (switch_on)
        {
        case 1:
            MaxDamage(HODArray);
            break;
        case 2:
            MinDamage(HODArray);
            break;
        case 3:
            Heal(HODArray);
            break;
        case 4:
            AllDamageOrHeal(HODArray,true);
            break;
        case 5:
            NonDamageTarget(HODArray);
            break;
        case 0:
            i = false;
            break;
        default:
            cout << "��� �� �����, �������� ��� ���\n";
            break;
        }
        cout << endl;
        cout << "��� ������: ";
    }
}



void FillArrayHealOrDmg(vector<int> &arr) 
{
    int number;
    string str;
    cout << "������ ����� (������ �����) ��� ���������� (��'��� �����) ������'�\n"
            "��� ������ � ������ ����� �������� Enter ��� ������ �����\n";
    for (int i = 0;; i++)
    {
        getline(cin, str, '\n');
        if(str.empty())
        {
            cout << "�� ������ � ������ �����\n\n";
            //cin.clear();
            //cin.ignore(32767, '\n');
            return;
        }
        try {
            number = stoi(str);
        }
        catch (exception& e) {
            cout << "�� ������ � ������ �����\n\n";
            return;
        }
        arr.resize(i + 1);
        arr[i] = number;
    }
}

bool ArrayIsValid(const vector<int>& arr)
{
    cout << "�������� �������� ������� �� ��������!\n\n";
    if (arr.empty())
    {
        cout << "�������! ���� ������ ������ ������ ������\n\n";
        return 0;
    }
    cout << "������ �������\n\n";
    return 1;
}


void MaxDamage(const vector<int>& arr) 
{
    int MaxDmg = 0;

    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i]>MaxDmg)
        {
            MaxDmg = arr[i];
        }
    }

    if (MaxDmg == 0)
    {
        cout << "����� �������\n\n";
        return;
    }

    cout << "����������� �����: " << MaxDmg << endl;
    cout << "����� � �����������: ";

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == MaxDmg)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
}

void MinDamage(const vector<int>& arr) 
{
    int MinDmg = 0;
    int i = 0;

    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            MinDmg = arr[i];
            break;
        }
    }

    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0 && arr[i] < MinDmg)
        {
            MinDmg = arr[i];
        }
    }

    if (MinDmg == 0)
    {
        cout << "����� �������\n\n";
        return;
    }

    cout << "̳������� ����� " << MinDmg << endl;
    cout << "����� � �����������: ";

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == MinDmg)
        {
            cout << i + 1 << " ";
        }
    }

    cout << endl;
}


void Heal(const vector<int>& arr) 
{


}

void AllDamageOrHeal(const vector<int>& arr, bool isDamage = true) 
{


}


void NonDamageTarget(const vector<int>& arr) 
{
    
    cout << "";
    cout << "��� �� ���� ����� �����: ";
    int i = 0;
    do
    {
        if (arr[i] == 0) {
            cout << "��� �� ���� ����� �����: ";
        }
        else if ()
        {

        }
    } while (true);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            cout << i + 1 << " ";
        }
    }
}