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

//  Знищує будівлю і повідобляє в консоль ID знищенної будівлі
void Building::Destroy() 
{
	IsDestroy = true;
	std::cout << "Будівля знищенна її ID: " << ID << '\n';
}

/*	Зістарює будівлю
*	@param years на скількі зістарити
*	@return нічого не робить якщо будівля знищенна
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

/*	Поточні роки будівлі
*	@return роки будівлі,
*			-1 якщо будівля знищенна
*/
int Building::GetAge() {
	if (IsDestroy == true) return -1;
	return Age;
}

/*	Поточна вартісь будівлі
*	@return вартісь будівлі,
*			-1 якщо будівля знищенна
*/
int Building::GetCost() {
	if (IsDestroy == true) return -1;
	return (InitialCost*(MaxAge-Age))/(MaxAge);
}
