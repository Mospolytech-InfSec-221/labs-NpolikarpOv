#include "kingsburg.h"




Game_polikarpov::Game_polikarpov(int count_players)
{
	player_number = count_players;
	for (int i = 0; i < player_number; i++) {
		std::string name;
		std::cin >> name;
		Player(name);
	}
}

void Game_polikarpov::phase1()
{
	if (year == 1) {
		std::cout << "Выберите ресурсы";

		std::cin <<
	}
}
