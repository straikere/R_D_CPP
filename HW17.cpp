//
//	������ �������� 16
// 
//	��� ���������� ���� �������� ���� Building �� ���������� �������
//	
//		Id: int (������� ���� ��������� ��� ��� �������)
//		MaxAge: int � ����������� ������� ����, ��� �� ������ ��������
//		Initial Cost: int � ��������� ������� �����
// 
//	� ����� ������ ������ ���� ������� �������-�����:
//	
//	Int GetCost();
//		* ������� ������� ������� �����. �� ������ ����� ������� ����� ���������� �����: 0 ���� � initial cost, 
//		  MaxAge ���� � 0$, MaxAge/2 � InitialCost/2
//	
//	void ToAge(int years);
//		* ������ ���� ������� ������� �������� ������ �� year ����
//		* ���� ������ ���������� �����, �� �� ������������ ��, �� ���� ������� ��������� �������� ������ Destroy();
// 
//	void Destroy();
//		* �������� �������, ��� � ������� ��������� ������ �� ���� id ���� ��������
//	
//
#include "Building.h"
#include <iostream>
using std::cout;

void Homework17() {

	Building build1; //defoult 10 yeras, 10000$
	Building build2(14,30000);
	Building build3(5,1000);

	cout << "-----------------������� �������� ����-----------------\n";

	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n'; 
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n'; 
	
	cout << "---------------ǳ������ �� 10 13 5 ����--------------\n";

	build1.ToAge(10);
	build2.ToAge(13);
	build3.ToAge(5);

	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n';
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n';

	cout << "---------------ǳ������ �� �� 5 1 1 ��--------------\n";

	build1.ToAge(5);
	build2.ToAge(1);
	build3.ToAge(1);
	
	cout << "Build 1 Cost = " << build1.GetCost() << " Age = " << build1.GetAge() << '\n';
	cout << "Build 2 Cost = " << build2.GetCost() << " Age = " << build2.GetAge() << '\n';
	cout << "Build 3 Cost = " << build3.GetCost() << " Age = " << build3.GetAge() << '\n';

	return;
}

