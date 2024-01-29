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

//Функція Домашнього Завдання 14
void Homework14() {
    //об'являємо масив типа вектор
    vector<int> HealOrDmgArray;
    //викликаємо функцію заповнення масиву числами які вводить користувач
    FillArrayHealOrDmg(HealOrDmgArray);
    //перевірка на валідність масиву
    if (!ArrayIsValid(HealOrDmgArray)) return;
    //меню функцій
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
            cout << "Скільки всього нам нанесли шкоди -- 1\n"
                    "Скільки всього нам нанесли лікування -- 2\n"
                    "Введіть шкода чи лікування: ";
            cin >> switch_on;
            cout << endl;
            switch (switch_on)
            {
            case 1:
                AllDamageOrHeal(HODArray, true);
                break;
            case 2:
                AllDamageOrHeal(HODArray, false);
                break;
            default:
                cout << "Ввід не вірний, повернення в меню\n";
                break;
            }

            break;
        case 5:
            NonDamageTarget(HODArray);
            break;
        case 0:
            i = false;
            return;
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
    //"чистим" сin
    std::cin.ignore(32767, '\n');
    int number;
    string str;
    cout << "Введіть шкоду (додатні числа) або відновлення (від'ємні числа) здоров'я\n"
            "Для виходу з режиму вводу натисніть Enter або введіть букву\n";
    for (int i = 0;; i++)
    {
        //данні з вводу записуєм в str 
        getline(cin, str, '\n');
        //якщо строка пуста
        if(str.empty())
        {
            cout << "Ви вийшли з режиму вводу\n\n";
            return;
        }
        //переводимо строку в int
        try {
            number = stoi(str);
        }
        catch (exception& e) {
            //якщо зловили помилку виходемо з вводу
            cout << "Ви вийшли з режиму вводу\n\n";
            return;
        }
        //якщо все ок, то ресайзем массив і присваюємо значення в нього по індексу
        arr.resize(i + 1);
        arr[i] = number;
    }
}


bool ArrayIsValid(const vector<int>& arr)
{
    cout << "Запущена перевірка массива на валідність!\n\n";
    //якщо він пустий то нам робити з ним немає чого
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
    //шукаємо найбільше число і пишемо його в MaxDmg
    for (int i = 0; i < arr.size(); i++) 
    {
        if (arr[i]>MaxDmg)
        {
            MaxDmg = arr[i];
        }
    }
    //якщо все таки не знайшли або це нуль
    if (MaxDmg == 0)
    {
        cout << "Шкода відсутня\n";
        return;
    }
    //якщо все ок
    cout << "Максимальна шкода: " << MaxDmg << endl;
    cout << "Номер в послідовності: ";

    //якщо однакових чисел з найбільшим дамагом більше в послідовності чим одне
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
    // шукаємо перше число яке більше нуля та записуємо його в MinDmg
    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            MinDmg = arr[i];
            break;
        }
    }
    // продовжуємо з того моменту як знайшли найменше число і якщо далі є число яке меньше за MinDmg і більше нуля, то ставемо його в MinDmg
    for (; i < arr.size(); i++)
    {
        if (arr[i] > 0 && arr[i] < MinDmg)
        {
            MinDmg = arr[i];
        }
    }
    // Якщо в масиві немає мінімальної шкоди
    if (MinDmg == 0)
    {
        cout << "Шкода відсутня\n";
        return;
    }
    // якщо є мінімальна шкода
    cout << "Мінімальна шкода " << MinDmg << endl;
    cout << "Номер в послідовності: ";
    //якщо однакових чисел з найменшим дамагом більше в послідовності чим одне
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
    bool bDoOnce = true;
    
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            //якщо хоч раз нас хтось похіляв
            if (bDoOnce)
            {
                cout << "Нас вилікували під номером: ";
                bDoOnce = false;
            }
            cout << i + 1 << " ";
        }
    }
    // якщо нас таки не похіляли ніразу
    if (bDoOnce)
    {
        cout << "В послідовності немає того хто відновив нам здоров'я";
    }

    cout << endl;
}


void AllDamageOrHeal(const vector<int>& arr, bool isDamage = true) 
{
    int sum = 0;
    // або дамаг або хіл
    if (isDamage)
    {
        // в тупу перебираємо масив і сумуємо значення які більше 0
        for (auto number : arr)
        {
            if (number > 0)
            {
                sum += number;
            }
        }
        // якщо нічого не знайшли
        if (sum == 0)
        {
            cout << "В послідовності немає шкоди!\n";
        }
        else
        {
            cout << "Всього шкоди: " << sum << endl;
        }
    }
    else {
        // те саме що вище але навпаки
        for (auto number : arr)
        {
            if (number < 0)
            {
                sum += number;
            }
        }
        if (sum == 0)
        {
            cout << "В послідовності немає лікування!\n";
        }
        else
        {
            cout << "Всього лікування: " << sum * -1 << endl;
        }
    }
}


void NonDamageTarget(const vector<int>& arr) 
{

    bool bDoOnce = true;
    // шукаємо нулі в масиві
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            if (bDoOnce)
            {
                cout << "Нам не наніс шкоду номер: ";
                bDoOnce = false;
            }

            cout << i + 1 << " ";
        }
    }
    // якщо немає ніодного
    if (bDoOnce)
    {
        cout << "В послідовності немає того хто наніс нам 0 шкоди";
    }
    cout << endl;
}