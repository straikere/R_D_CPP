#pragma once
#include <vector>

using std::vector;

/*	�������� ������ ������� ����� �����������
*	@param arr ������ ���� ������ ��������� 
*/
void FillArrayHealOrDmg(vector<int>& arr);

/*	�������� �� ������ �����
*	@param arr ������ ���� ������ ���������
*	@return 0, ������ ������
*			1, ������ �������
*/
bool ArrayIsValid(const vector<int>& arr);

/*	�������� � ������� ������ �� ������� �������� �����
*	@param arr ������ � ����� ������
*/
void MaxDamage(const vector<int>& arr);

/*	�������� � ������� ������ �� ������� ��� �������� �����
*	@param ������ � ����� ������ �������� �����
*/
void MinDamage(const vector<int>& arr);

/*	�������� � ������� ������ �� �������
*	@param arr ������ � ����� ������ ��������
*/
void Heal(const vector<int>& arr);

/*	�������� � ������� ��� ����� ��� ��������
*	@param arr ������ � ����� ������ ����
*	@param isDamage	true, �������� �����
*					false, �������� ��������
*/
void AllDamageOrHeal(const vector<int>& arr, bool isDamage);

/*	�������� � ������� ������ �� ������� 0 �����
*	@param arr ������ � ����� ������ ����
*/
void NonDamageTarget(const vector<int>& arr);

/*	����� ����������
*	@param HODArray ������ � ���� ������ ���������
*/
void StatisticMenu(const vector<int>& HODArray);