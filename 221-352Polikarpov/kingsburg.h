#pragma once
#include <vector>
#include <algorithm>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h>
#include <fstream>

using namespace std;
class kingsburg
{
	struct Player
	{
		const char* name;
		int gold = 0;
		int wood = 0;
		int stone = 0;
		int tokens = 0;
		int order = 0;
		int cube_1 = 0;
		int cube_2 = 0;
		int cube_3 = 0;
		int add_cube = 0;
		bool advisor;
		int military_register;
		int victory_score;
		int buildings;
		std::vector <bool> building;



	};

	int players;
	int player_number;
	int year;
	const char* enemy;
	int phase;

	vector<char> advisor;
	vector<char> whos_advinsor;
	vector<Player> pl; // век игроков

	kingsburg();
	kingsburg(int count_players);
	kingsburg(const kingsburg& temp);
	~kingsburg();

	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();

	void defense_level(const char* enemy_name, int king_help);

	void phase246();
	void phase246_bonus();

	void phase246_advisor();
	void advisor_help();

	bool save_game(const char* filename);

};


