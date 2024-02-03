//
//	Домашнє завдання 16
// 
//	1.Зчитати з консолі в наступному форматі декілька команд:
//	
//		Назва клану(string)
//		Ім’я гравця(string)
//		Сила гравця(float)
// 
//	2.Зберегти данні в мапі, де ключем є назва клану
//	
//	3.Розробити фунцію, яка повертає кількість гравців у клані за її назвою
//	
//		Int GetPlayerCount(constr string& ClanName);
// 
//	4.Розробити функцію, яка повертає результат поєдинку між кланами.
//	
//		Int ClanFight(constr string& FirstClanName, const string& SecondClanName);
// 
//			Функція повертає :
//			⁃ 0, якщо нічия
//			
//			⁃ 1, якщо переміг перший клан
//			
//			⁃ -1, якщо переміг другий клан
//		
//		Умова перемоги : сумарна сила членів клану більша за сумарну силу іншого клану
//	
//

#include"HW16.h"

static map<string, vector<chStruct>> teamMap;

void Homework16() {

	InputMenu();
	
	//teamMap.insert({ "Gayss", vector<chStruct>{{"asd", 34.2f}}});
	
	//std::cout << a["Gays"].push_back(vector<chStruct>{{"asdd"}});


	std::cout << std::endl;
}

int GetPlayerCount(const string& ClanName) {
	return -1;
}

int ClanFight(const string& FirstClanName, const string& SecondClanName) {
	return -2;
}

void InputMenu() {
	int switch_on;
	for (;;)
	{
		std::cout << "Створити команду та персонажа? 1 -- Так, 0 -- Вихід: ";
		std::cin >> switch_on;
		std::cout << '\n';
		switch (switch_on)
		{
		case 1:
			AddPlayerToTeam();
			break;
		case 0:
			return;
			break;
		default:
			std::cout << "Ввід не вірний, повторіть ваш ввід\n";
			break;
		}
		std::cout << '\n';
	}
}

void AddPlayerToTeam() {
	string teamName;
	std::cout << "Введіть ім'я команди: ";
	std::cin >> teamName;

	if (teamMap.find(teamName) != teamMap.end())
	{
		std::cout << "Така команда знайдена, додавання буде виконано пізніше\n";
	}
	else {
		std::cout << "Така команда не знайдена, і буде стоврено команду з таким ім'ям\n";
	}

	string playerName;
	std::cout << "Введіть ім'я гравця: ";
	std::cin >> playerName;

	float playerPower;
	std::cout << "Введіть силу гравця: ";
	std::cin >> playerPower;


	if (teamMap.find(teamName) != teamMap.end())
	{
		teamMap.find(teamName)->second.push_back(chStruct(playerName, playerPower));
	}
	else {
		teamMap.insert({ teamName, vector<chStruct>{{playerName,playerPower}} });
	}

}