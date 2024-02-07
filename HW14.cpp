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
#include <string>
#include "HW14.h"

using std::cout, std::cin;

void Homework14() {
   
    vector<int> HealOrDmgArray;

    FillArrayHealOrDmg(HealOrDmgArray);

    if (!ArrayIsValid(HealOrDmgArray)) return;
    
    StatisticMenu(HealOrDmgArray);
    
}

void StatisticMenu(const vector<int>& HODArray)
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
    while (true)
    {
        cin >> switch_on;
        cout << '\n';
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
            cout << "������ ������ ��� ������� ����� -- 1\n"
                    "������ ������ ��� ������� �������� -- 2\n"
                    "������ ����� �� ��������: ";
            cin >> switch_on;
            cout << '\n';
            switch (switch_on)
            {
            case 1:
                AllDamageOrHeal(HODArray, true);
                break;
            case 2:
                AllDamageOrHeal(HODArray, false);
                break;
            default:
                cout << "��� �� �����, ���������� � ����\n";
                break;
            }

            break;
        case 5:
            NonDamageTarget(HODArray);
            break;
        case 0:
            return;
            break;
        default:
            cout << "��� �� �����, �������� ��� ���\n";
            break;
        }
        cout << '\n';
        cout << "��� ������: ";
    }
}

void FillArrayHealOrDmg(vector<int> &arr) 
{
    //"������" �in
    std::cin.ignore(32767, '\n');
    int number;
    std::string str;
    cout << "������ ����� (������ �����) ��� ���������� (��'��� �����) ������'�\n"
            "��� ������ � ������ ����� �������� Enter ��� ������ �����\n";
    while (true)
    {
        //���� � ����� ������� � str 
        getline(cin, str, '\n');
        //���� ������ �����
        if(str.empty())
        {
            cout << "�� ������ � ������ �����\n\n";
            return;
        }
        //���������� ������ � int
        try {
            number = stoi(str);
        }
        catch (std::exception& e) {
            //���� ������� ������� �������� � �����
            cout << "�� ������ � ������ �����\n\n";
            return;
        }
        arr.push_back(number);
    }
}

bool ArrayIsValid(const vector<int>& arr)
{
    cout << "�������� �������� ������� �� ��������!\n\n";
    //���� �� ������ �� ��� ������ � ��� ���� ����
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
    //������ �������� ����� � ������ ���� � MaxDmg
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i]>MaxDmg)
        {
            MaxDmg = arr[i];
        }
    }
    //���� ��� ���� �� ������� ��� �� ����
    if (MaxDmg == 0)
    {
        cout << "����� �������\n";
        return;
    }
    //���� ��� ��
    cout << "����������� �����: " << MaxDmg << '\n';
    cout << "����� � �����������: ";

    //���� ��������� ����� � ��������� ������� ����� � ����������� ��� ����
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == MaxDmg)
        {
            cout << i + 1 << " ";
        }
    }

    cout << '\n';
}

void MinDamage(const vector<int>& arr) 
{
    int MinDmg = 0;
    int i = 0;
    // ������ ����� ����� ��� ����� ���� �� �������� ���� � MinDmg
    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            MinDmg = arr[i];
            break;
        }
    }
    // ���������� � ���� ������� �� ������� �������� ����� � ���� ��� � ����� ��� ������ �� MinDmg � ����� ����, �� ������� ���� � MinDmg
    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0 && arr[i] < MinDmg)
        {
            MinDmg = arr[i];
        }
    }
    // ���� � ����� ���� �������� �����
    if (MinDmg == 0)
    {
        cout << "����� �������\n";
        return;
    }
    // ���� � �������� �����
    cout << "̳������� ����� " << MinDmg << '\n';
    cout << "����� � �����������: ";
    //���� ��������� ����� � ��������� ������� ����� � ����������� ��� ����
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == MinDmg)
        {
            cout << i + 1 << " ";
        }
    }

    cout << '\n';
}

void Heal(const vector<int>& arr) 
{
    bool bDoOnce = true;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            //���� ��� ��� ��� ����� �������
            if (bDoOnce)
            {
                cout << "��� ��������� �� �������: ";
                bDoOnce = false;
            }
            cout << i + 1 << " ";
        }
    }
    // ���� ��� ���� �� �������� �����
    if (bDoOnce)
    {
        cout << "� ����������� ���� ���� ��� ������� ��� ������'�";
    }

    cout << '\n';
}

void AllDamageOrHeal(const vector<int>& arr, bool isDamage = true) 
{
    int sum = 0;
    // ��� ����� ��� ���
    if (isDamage)
    {
        // � ���� ���������� ����� � ������ �������� �� ����� 0
        for (auto number : arr)
        {
            if (number > 0)
            {
                sum += number;
            }
        }
        // ���� ����� �� �������
        if (sum == 0)
        {
            cout << "� ����������� ���� �����!\n";
        }
        else
        {
            cout << "������ �����: " << sum << '\n';
        }
    }
    else {
        // �� ���� �� ���� ��� �������
        for (auto number : arr)
        {
            if (number < 0)
            {
                sum += number;
            }
        }
        if (sum == 0)
        {
            cout << "� ����������� ���� ��������!\n";
        }
        else
        {
            cout << "������ ��������: " << sum * -1 << '\n';
        }
    }
}

void NonDamageTarget(const vector<int>& arr) 
{

    bool bDoOnce = true;
    // ������ ��� � �����
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            if (bDoOnce)
            {
                cout << "��� �� ���� ����� �����: ";
                bDoOnce = false;
            }

            cout << i + 1 << " ";
        }
    }
    // ���� ���� �������
    if (bDoOnce)
    {
        cout << "� ����������� ���� ���� ��� ���� ��� 0 �����";
    }
    cout << '\n';
}