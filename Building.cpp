#include "Building.h"
#include <iostream>

int Building::NextID = 0;

Building::Building(int _MaxAge, int _InitialCost)
	: MaxAge{ _MaxAge }, InitialCost{ _InitialCost }
{
	ID = NextID;
	InitialCost = _InitialCost;
	MaxAge = _MaxAge;
	Age = 0;
	IsDestroy = false;
	++NextID;
}

Building::~Building() {

}

//  ����� ������ � ��������� � ������� ID �������� �����
void Building::Destroy() 
{
	IsDestroy = true;
	std::cout << "������ �������� �� ID: " << ID << '\n';
}

/*	ǳ������ ������
*	@param years �� ����� ��������
*	@return ����� �� ������ ���� ������ ��������
*/
void Building::ToAge(int years) {
	if (IsDestroy == true) return;
	if (Age+years > MaxAge)
	{
		//Age += years;
		Destroy();
		return;
	}
	Age += years;
}

/*	������ ���� �����
*	@return ���� �����,
*			-1 ���� ������ ��������
*/
int Building::GetAge() {
	if (IsDestroy == true) return -1;
	return Age;
}

/*	������� ������ �����
*	@return ������ �����,
*			-1 ���� ������ ��������
*/
int Building::GetCost() {
	if (IsDestroy == true) return -1;
	return (InitialCost*(MaxAge-Age))/(MaxAge);
}
