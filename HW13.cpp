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
#include <Windows.h>
#include <ctime>

using namespace std;

//enum наших классів починаєтся з 1
enum CharacterClass
{
    Mage = 1,
    Warrior
};


void Homework13() {


    //локалізація консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //постійний рандом
    srand(time(NULL));

    //Об'являєм змінну на ім'я персонажа
    string CharacterName;

    cout << "Введіть імя персонажа: ";

    //Вводимо ім'я персонажа
    cin >> CharacterName;

    //Об'являєм змінну на здоров'я та максимальне здоров'я персонажа (по замовчуванню 100)
    float CharacterHealth = 100, CharacterMaxHealth = 100;
    cout << "Введіть здоров'я персонажа: ";

    //Вводимо здоров'я
    cin >> CharacterHealth;

    //Макс здоровя = здоровю, для обчислення %
    CharacterMaxHealth = CharacterHealth;

    //ініціалізуємо enum
    CharacterClass MyCharacterClass;

    //ініціалізуємо інтову змінну для классів
    int CharacterClassInt;

    //Цикл доки правельно не буде введений Класс персонажу
    for (bool i = true; i == true;)
    {
        cout << "Виберіть клас персонажа 1 -- Маг, 2 -- Воїн: ";
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
            cout << "Ввід не вірний, повторіть ваш ввід" << endl;
            break;
        }

    }


    //змінна для смерті
    bool IsDead = false;

    //змінна для шкоди
    int Damage = 0;

    //Змінна для відцотків
    float Procentage = 100;

    //Змінна для "потужності"
    float Power;

    switch (MyCharacterClass)
    {
    case Mage:
        cout << "Класс персонажа Маг (кожне парне число наносить подвійну шкоду)" << endl;
        cout << "Якщо шкода більша за 2хпотужності, то є 50% ймовірності, що вона йому не зменшить здоров’я" << endl;

        //Потужність у Мага
        Power = 10;

        cout << "Ваша потужність = " << Power << endl;

        //Цикл на смерть
        while (!IsDead)
        {
            cout << "--------------------------------------------------------" << endl;
            cout << "Введіть шкоду для вашого персонажа: ";
            cin >> Damage;

            //Якщо шкода парна
            if ((Damage % 2) == 0)
            {
                cout << "Шкода " << Damage << " парна, шкода = " << 2 * Damage << endl;
                Damage = 2 * Damage;

                //Якщо шкода більше 2*потужності і вам повезло "rand() % 2" має діапазон рантому від 0 до 1 що є 50% вірогідності
                if (Damage > (2 * Power) && rand() % 2)
                {
                    cout << "Удача! Вам не нанесено шкоди!" << endl;
                }
                else
                {
                    CharacterHealth = CharacterHealth - Damage;
                }
            }
            else
            {
                cout << "Шкода " << Damage << " не парна, шкода = " << Damage << endl;

                //Якщо шкода більше потужності і вам повезло
                if (Damage > (2 * Power) && rand() % 2)
                {
                    cout << "Удача! Вам не нанесено шкоди!" << endl;
                }
                else
                {
                    CharacterHealth = CharacterHealth - Damage;
                }
            }

            //Вираховуємо відцотки після отримання урону
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //Перевіряємо чи вмерли
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "У персонажа залишилося " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, це = " << CharacterHealth << endl;
            }
        }
        break;

    case Warrior:
        cout << "Класс персонажа Воїн (кожне непарне число наносить потрійну шкоду, а парні не наносять шкоду)" << endl;
        cout << "Якщо у воїна менше 30% здоров’я, то наносимий йому урон зменшується на величину параметру “потужність”" << endl;

        //Потужність у Воїна
        Power = 10;

        cout << "Ваша потужність = " << Power << endl;

        //Цикл на смерть
        while (!IsDead)
        {
            cout << "--------------------------------------------------------" << endl;
            cout << "Введіть шкоду для вашого персонажа: ";
            cin >> Damage;

            //Вираховуємо відцотки до отримання урону
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //Якщо шкода парна
            if ((Damage % 2) == 0)
            {
                cout << "Шкода " << Damage << " парна, шкода = " << 0 << endl;
            }
            else
            {
                cout << "Шкода " << Damage << " не парна, шкода = " << 3 * Damage << endl;
                Damage = (3 * Damage);

                //Якщо меньше 30% здоров'я
                if (Procentage < 30)
                {
                    cout << "Шкоду зменшено на " << Power;
                    Damage = Damage - Power;

                    //Захист від мінусового значення
                    if (Damage < 0)
                    {
                        Damage = 1;
                    }
                    cout << ", шкода = " << Damage << endl;
                }
                CharacterHealth = CharacterHealth - Damage;
            }

            //Вираховуємо відцотки після отримання урону
            Procentage = (CharacterHealth / CharacterMaxHealth) * 100;

            //Перевіряємо чи вмерли
            if (Procentage <= 0)
            {
                IsDead = !IsDead;
            }
            else
            {
                cout << "У персонажа залишилося " << (CharacterHealth / CharacterMaxHealth) * 100 << "% HP, це = " << CharacterHealth << endl;
            }
        }
        break;
    }

    //якщо ми тут то це точно смерть
    cout << "--------------------------------------------------------" << endl;
    cout << "Ви вмерли!" << endl;
    cout << "Ім'я персонажа " << CharacterName << endl;
    cout << "Встановлене здоров'я персонажа " << CharacterMaxHealth << endl;
    cout << "The End!" << endl;

}