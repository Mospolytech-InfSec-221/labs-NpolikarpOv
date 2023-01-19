#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class kingsburg
{
public:
public:
	struct Player {
		int ID;
		std::string name = " ";
		int gold = 0;
		int wood = 0;
		int stone = 0;
		int money = 0; //жетоны
		int cube1 = 0;
		int cube2 = 0;
		int cube3 = 0;
		int add_cube = 0; // доп белый кубик
		int advisor = 0; // наличение советника
		int military_register = 0; // значение воинского реестра
		int po = 0; // кол-во победных очков
		std::vector<int> build = {};// вектор построек
		int count_building;
		bool poslannik = 0;
		Player() {
			this->name;
			this->gold;
			this->wood;
			this->stone;
			this->money;
			this->cube1;
			this->cube2;
			this->cube3;
			this->add_cube;
			this->advisor;
			this->military_register;
			this->po;
			this->build;
		}
		Player(std::string name) {
			this->name = name;
		}
	};
	int player_number;
	std::string advisors[17] = { "Шут", "Сквайр", "Зодчий", "Купец", "Сержант", "Алхимик", "Звездочет", "Казначей", "Охотница", "Генерал", "Оружейник", "Герцогиня", };
	std::vector<Player> vec; // вектор игроков
	int count_players;
	int year;
	int phase;
	const char* enemy_name;
	kingsburg(); // конструктор по умолчанию
	~kingsburg(); // деструктор
	kingsburg(int count_players); // конструктор инициализирующий	
	kingsburg(const Game_Nurov& temp); // копирующий конструктор
	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void defense_level(const char* enemy_name, int king_help);
};

