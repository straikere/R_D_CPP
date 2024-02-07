#pragma once
#include <vector>

using std::vector;

/*	Заповнює вектор данними вводу користувача
*	@param arr вектор який хочемо заповнити 
*/
void FillArrayHealOrDmg(vector<int>& arr);

/*	Перевіряє чи пустий масив
*	@param arr вектор який хочемо перевірити
*	@return 0, массив пустий
*			1, массив валідний
*/
bool ArrayIsValid(const vector<int>& arr);

/*	Виводить в консоль номера які завдали найбільшу шкоду
*	@param arr вектор в якому шукаємо
*/
void MaxDamage(const vector<int>& arr);

/*	Виводить в консоль номера які нанесли нам найменше шкоди
*	@param вектор в якому шукаємо мінімальну шкоду
*/
void MinDamage(const vector<int>& arr);

/*	Виводить в консоль номера які лікували
*	@param arr вектор в якому шукаємо лікування
*/
void Heal(const vector<int>& arr);

/*	Виводить в консоль всю шкоду або лікування
*	@param arr вектор в якому шукаємо данні
*	@param isDamage	true, виводить шкоду
*					false, виводить лікування
*/
void AllDamageOrHeal(const vector<int>& arr, bool isDamage);

/*	Виводить в консоль номера які нанесли 0 шкоди
*	@param arr вектор в якому шукаємо данні
*/
void NonDamageTarget(const vector<int>& arr);

/*	Режим статистики
*	@param HODArray вектор з яким будемо працювати
*/
void StatisticMenu(const vector<int>& HODArray);