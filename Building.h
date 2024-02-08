#pragma once

class Building
{
public:
	Building(int _MaxAge = 30, int _InitialCost = 10000);

	~Building();

public:
	int GetCost();
	int GetAge();
	void ToAge(int years);

private:
	void Destroy();

private:
	int ID;
	int MaxAge;
	int Age;
	int InitialCost;
	bool IsDestroy;

	static int NextID;
};