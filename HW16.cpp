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

//Вписати тут ture для авто дебага
#define DEBUG_ON false

#if DEBUG_ON
	static map<string, vector<chStruct>> teamMap{	{"A", vector<chStruct>{{"Name1", 100},{"Name2",100},{"Name3",100}}},				//power sum 300 Team A 
													{"B", vector<chStruct>{{"Name1", 300},{"Name2",200}}},								//power sum 500 Team B
													{"C", vector<chStruct>{{"Name1", 500}}},											//power sum 500 Team C
													{"D", vector<chStruct>{{"Name1", 200},{"Name2",200},{"Name3",200},{"Name4",200}}},	//power sum 800 Team D
	};
#else
	static map<string, vector<chStruct>> teamMap;
#endif // DEBUG_ON


void Homework16() {

	if (DEBUG_ON)
	{
		std::cout << "GetPlayerCount: " << GetPlayerCount("A") << '\n'; // 3
		std::cout << "GetPlayerCount: " << GetPlayerCount("B") << '\n'; // 2
		std::cout << "GetPlayerCount: " << GetPlayerCount("C") << '\n'; // 1
		std::cout << "GetPlayerCount: " << GetPlayerCount("D") << '\n'; // 4

		std::cout << "ClanFight B vs C: " << ClanFight("B", "C") << '\n'; // 0 нічья
		std::cout << "ClanFight D vs C: " << ClanFight("D", "C") << '\n'; // 1 D winner
		std::cout << "ClanFight A vs B: " << ClanFight("A", "B") << '\n'; // -1 B winner
		std::cout << "ClanFight E vs B: " << ClanFight("E", "B") << '\n'; // error 10
		std::cout << "ClanFight A vs F: " << ClanFight("A", "F") << '\n'; // error 11
	}
	else
	{

		InputMenu();

		std::cout << "GetPlayerCount введіть назву клану: ";
		string clanName;
		std::cin >> clanName;
		std::cout << "PlayerCount in Clan "<< clanName << " = " << GetPlayerCount(clanName) << '\n';

		string clanA,clanB;
		std::cout << "Битва кланів введіть назву першого клану: ";
		std::cin >> clanA;

		std::cout << "Битва кланів введіть назву другого клану: ";
		std::cin >> clanB;

		std::cout << "Результат битви кланів: " << ClanFight(clanA, clanB) << '\n';
	}
}

int GetPlayerCount(const string& ClanName) {
	if (teamMap.find(ClanName) != teamMap.end())
	{
		return teamMap.find(ClanName)->second.size();
	}
	return -1;
}

int ClanFight(const string& FirstClanName, const string& SecondClanName) {
	if (teamMap.find(FirstClanName) == teamMap.end())
	{
		std::cout << "\nПомилка Клану А неіснує код помилки: ";
		return 10;
	}
	else if (teamMap.find(SecondClanName) == teamMap.end())
	{
		std::cout << "\nпомилка Клану B неіснує код помилки: ";
		return 11;
	}

	float maxPowerTeamA = 0;
	float maxPowerTeamB = 0;
	for (int i = 0; i < teamMap[FirstClanName].size(); i++)
	{
		maxPowerTeamA += teamMap.find(FirstClanName)->second[i].power;
	}

	for (int i = 0; i < teamMap[SecondClanName].size(); i++)
	{
		maxPowerTeamB += teamMap.find(SecondClanName)->second[i].power;

	}

	if (maxPowerTeamA>maxPowerTeamB)
	{
		return 1;
	}
	else if (maxPowerTeamB>maxPowerTeamA)
	{
		return -1;
	}
	else
	{
		return 0;

	}
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