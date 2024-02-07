#pragma once

enum CharacterClass
{
    Mage = 1,
    Warrior,
    MAX
};

// Повертає структуру обрану користувачем
CharacterClass ChoseClass();

/*  Шкода до Мага
* 
*   кожне парне число наносить подвійну шкоду від заданої
*   шкода більша за 2хпотужності, то є 50 % ймовірності, що вона йому не зменшить здоров’я
* 
*   @param Damage Шкода яку хочемо нанести
*   @param CharacterHealth Актуальне здоров'я персонажа
*   @param Power Потужніть персонажа
*/
void DamageToMage(int& Damage, float& CharacterHealth, const int& Power);

/*  Шкода до Воїна
* 
*   кожне непарне число наносить потрійну шкоду, а парні не наносять шкоду
*   якщо залишилося менше 30 % здоров’я, то наносимий урон зменшується на величину параметру “потужність”
* 
*   @param Damage Шкода яку хочемо нанести
*   @param CharacterHealth Актуальне здоров'я персонажа
*   @param CharacterMaxHealth Максимальне здоров'я персонажа
*   @param Power Потужніть персонажа
* 
*   @return відцоток від здоровя яке залишилося
*/
float DamageToWarrior(int& Damage, float& CharacterHealth, const float& CharacterMaxHealth, const int& Power);