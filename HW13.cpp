// 
//  Домашнє завдання 13
// 
//  1.Написати програму, яка запитує і запам’ятовує, данні для створення персонажа грі:
//  
//  *Ім’я
//  *Кількість здоров’я
//  *Клас(один з двох на вибір : маг, воїн)
//  
//  
//  2.Доки в персонажа є здоров’я зчитувати значення шкоди, яку завдає персонажу ворог.
//  
//  *Якщо клас персонажа маг, то кожне парне число наносить подвійну шкоду від заданої
//  *Якщо клас персонажа воїн, то кожне непарне число наносить потрійну шкоду, а парні не наносять шкоду
//  
//  
//  3.Завдання із зірочкою :
//  
//  *Додати до персонажа параметр “потужність”
//  *До попередніх умов додати наступні :
//  
//  
//  Якщо у воїна залишилося менше 30 % здоров’я, то наносимий йому урон зменшується на величину параметру “потужність”
//  Якщо магу наноситься шкода більша за 2хпотужності, то є 50 % ймовірності, що вона йому не зменшить здоров’я
//

#include <iostream>
#include <ctime>
#include "HW13.h"

using std::cin, std::cout;

void Homework13() {

    //regular random
    srand(time(NULL));

    std::string CharacterName;
    cout << "Введіть імя персонажа: ";
    cin >> CharacterName;

    //default Character Stats
    float CharacterHealth = 100;
    float CharacterMaxHealth = 100;

    cout << "Введіть здоров'я персонажа: ";
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
        cout << "Класс персонажа Маг (кожне парне число наносить подвійну шкоду)\n";
        cout << "Якщо шкода більша за 2хпотужності, то є 50% ймовірності, що вона йому не зменшить здоров’я\n";

        //Mage power
        Power = 10;

        cout << "Ваша потужність = " << Power << '\n';

        while (!IsDead)
        {
            cout << "--------------------------------------------------------\n" ;
            cout << "Введіть шкоду для вашого персонажа: ";
            cin >> Damage;

            //Якщо шкода парна
            DamageToMage(Damage,CharacterHealth,Power);

            //відцотки після отримання урону
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //вмерли?
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "У персонажа залишилося " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, це = " << CharacterHealth << '\n';
            }
        }
        break;

    case Warrior:
        cout << "Класс персонажа Воїн (кожне непарне число наносить потрійну шкоду, а парні не наносять шкоду)\n";
        cout << "Якщо у воїна менше 30% здоров’я, то наносимий йому урон зменшується на величину параметру “потужність”\n";

        //Потужність у Воїна
        Power = 10;

        cout << "Ваша потужність = " << Power << '\n';

        while (!IsDead)
        {
            cout << "--------------------------------------------------------\n";
            cout << "Введіть шкоду для вашого персонажа: ";
            cin >> Damage;

            Procentage = DamageToWarrior(Damage,CharacterHealth,CharacterMaxHealth,Power);            

            //вмерли?
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "У персонажа залишилося " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, це = " << CharacterHealth << '\n';
            }
        }
        break;
    }

    cout << "--------------------------------------------------------\n";
    cout << "Ви вмерли!\n";
    cout << "Ім'я персонажа " << CharacterName << '\n';
    cout << "Встановлене здоров'я персонажа " << CharacterMaxHealth << '\n';
    cout << "The End!" << '\n';

}

CharacterClass ChoseClass() {
    int ChClassInt;
    CharacterClass ChClassStruct;
    while (true)
    {
        cout << "Виберіть клас персонажа 1 -- Маг, 2 -- Воїн: ";
        cin >> ChClassInt;
        ChClassStruct = static_cast<CharacterClass>(ChClassInt);
        if (ChClassStruct < CharacterClass::MAX && ChClassStruct >= 1)
        {
            return ChClassStruct;
        }
        cout << "Ввід не вірний, повторіть ваш ввід\n";
    }
}

void DamageToMage(int& Damage, float &CharacterHealth,const float &Power) {
    if ((Damage % 2) == 0)
    {
        cout << "Шкода " << Damage << " парна, шкода = " << 2 * Damage << '\n';

        Damage = 2 * Damage;

        //Якщо шкода більше 2*потужності і вам повезло "rand() % 2" має діапазон рантому від 0 до 1 що є 50% вірогідності
        if (Damage > (2 * Power) && rand() % 2)
        {
            cout << "Удача! Вам не нанесено шкоди!\n";
        }
        else
        {
            CharacterHealth = CharacterHealth - Damage;
        }
    }
    else
    {
        cout << "Шкода " << Damage << " не парна, шкода = " << Damage << '\n';

        //Якщо шкода більше потужності і вам повезло
        if (Damage > (2 * Power) && rand() % 2)
        {
            cout << "Удача! Вам не нанесено шкоди!\n";
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
        cout << "Шкода " << Damage << " парна, шкода = " << 0 << '\n';
        return Procentage;
    }
    else
    {
        cout << "Шкода " << Damage << " не парна, шкода = " << 3 * Damage << '\n';
        Damage = (3 * Damage);

        //Якщо меньше 30% здоров'я
        if (Procentage < (30))
        {
            cout << "Шкоду зменшено на " << Power;
            Damage = Damage - static_cast<int>(Power);

            //Захист від мінусового значення
            if (Damage < 0)
            {
                Damage = 1;
            }
            cout << ", шкода = " << Damage << '\n';
        }
        CharacterHealth = CharacterHealth - Damage;
    }
    Procentage = (CharacterHealth / CharacterMaxHealth) * 100;
    return Procentage;
}