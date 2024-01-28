//
//	Домашнє завдання 14
// 
//	1. Написати програму, яка запитує і запам’ятовує числа, які дорівнюють кількості шкоди(або лікуванню, якщо число від’ємне).
// 
//	2. Розробити для цих даних функції статистики :
// 
//	*Під якими номерами нам завдали найбільшу шкоду
//	*Під якими номерами нам завдали нам найменше шкоди
//	*Під якими номерами нам завдали лікування
//	*Скільки всього нам нанесли шкоди / лікування(в параметр функції потрібно передати обраний варіант : лікування, або шкода)
//	*Чи є хтось, хто нічого нам не зробив(значення дорівнює нулю)
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
    cout << "Режим статистики, виберіть варіант\n"
        "Під якими номерами нам завдали найбільшу шкоду -- 1\n"
        "Під якими номерами нам завдали нам найменше шкоди -- 2\n"
        "Під якими номерами нам завдали лікування -- 3\n"
        "Скільки всього нам нанесли шкоди / лікування -- 4\n"
        "Чи є хтось, хто нічого нам не зробив -- 5\n"
        "Вихід -- 0\n"
        "Ваш варіант: ";
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
            cout << "Ввід не вірний, повторіть ваш ввід\n";
            break;
        }
        cout << endl;
        cout << "Ваш варіант: ";
    }
}



void FillArrayHealOrDmg(vector<int> &arr) 
{
    int number;
    string str;
    cout << "Введіть шкоду (додатні числа) або відновлення (від'ємні числа) здоров'я\n"
            "Для виходу з режиму вводу натисніть Enter або введіть букву\n";
    for (int i = 0;; i++)
    {
        getline(cin, str, '\n');
        if(str.empty())
        {
            cout << "Ви вийшли з режиму вводу\n\n";
            //cin.clear();
            //cin.ignore(32767, '\n');
            return;
        }
        try {
            number = stoi(str);
        }
        catch (exception& e) {
            cout << "Ви вийшли з режиму вводу\n\n";
            return;
        }
        arr.resize(i + 1);
        arr[i] = number;
    }
}

bool ArrayIsValid(const vector<int>& arr)
{
    cout << "Запущена перевірка массива на валідність!\n\n";
    if (arr.empty())
    {
        cout << "Помилка! Данні відсутні данний массив пустий\n\n";
        return 0;
    }
    cout << "Массив валідний\n\n";
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
        cout << "Шкода відсутня\n\n";
        return;
    }

    cout << "Максимальна шкода: " << MaxDmg << endl;
    cout << "Номер в послідовності: ";

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
        cout << "Шкода відсутня\n\n";
        return;
    }

    cout << "Мінімальна шкода " << MinDmg << endl;
    cout << "Номер в послідовності: ";

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
    cout << "Нам не наніс шкоду номер: ";
    int i = 0;
    do
    {
        if (arr[i] == 0) {
            cout << "Нам не наніс шкоду номер: ";
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