#include "kingsburg.h"




Game_polikarpov::Game_polikarpov()
{
	std::cout << "Write the numbers of players" << std::endl;
	std::cin >> player_number;
	for (int i = 0; i < player_number; i++) {

		Player gamer;
		std::string name;
		std::cin >> name;
		gamer.name = name;
		vec.push_back(gamer);
	}
}

Game_polikarpov::Game_polikarpov()
{
	std::cout << "Деструктор";
}

Game_polikarpov::Game_polikarpov(int count_players)
{

	player_number = count_players;
	for (int i = 0; i < player_number; i++) {
		std::cout << "Write the name" << std::endl;
		Player gamer;
		std::string name;
		std::cin >> name;
		gamer.name = name;
		vec.push_back(gamer);
	}
}

void Game_polikarpov::phase1()
{
	if (year == 1) {
		std::string res;
		std::cout << "Введите выбор ресурсов" << std::endl;
		std::cin >> res;
		if (year == 1) {
			for (int i = 0; i < player_number; i++) {
				std::cout << "Player " << vec[i].name << "Choose the resource";
				std::cin >> res;
				if (res == "Дерево") {
					vec[i].wood += 1;
				}
				else if (res == "Золото") {
					vec[i].gold += 1;
				}
				else if (res == "Камень") {
					vec[i].stone += 1;
				}
			}
		}
	}
	else {
		std::sort(this->vec.begin(), this->vec.end(), [](Player first, Player second) {
			if (first.count_building != second.count_building) {
				return first.count_building > second.count_building;
			}
			else {
				return ((first.gold + first.wood + first.stone) > (second.gold + second.wood + second.stone));
			}
			});
		std::vector<Player> new_vec = { this->vec[0] }; //вектор нуждающихся игроков
		for (int i = 0; i < this->vec.size() - 1; i++) {
			if ((this->vec[i].gold + this->vec[i].stone + this->vec[i].wood) == (this->vec[i + 1].gold + this->vec[i + 1].stone + this->vec[i + 1].wood)) {
				new_vec.push_back(this->vec[i + 1]);
			}
		}
		// заполнили вектор нуждающихся игроков
		if (new_vec.size() == this->vec.size()) { // для первого года
			// каждому даём по одному ресурсу
			for (int i = 0; i < this->vec.size(); i++) {
				vec[i].gold++;
				vec[i].wood++;
				vec[i].stone++;
			}
		}
		else { // для следующих лет
			// бросает белый кубик
		}
	}
}

void Game_polikarpov::phase3() {
	std::sort(this->vec.begin(), this->vec.end(), [](Player first, Player second) {return first.count_building > second.count_building; });
	std::vector<Player> new_vec = { this->vec[0] }; //вектор поощерённых игроков
	for (int i = 0; i < this->vec.size() - 1; i++) {
		if (this->vec[i].count_building == this->vec[i + 1].count_building) {
			new_vec.push_back(this->vec[i + 1]);
		}
	}
	for (int i = 0; i < new_vec.size(); i++) {
		for (int j = 0; j < this->vec.size(); j++) {
			if (new_vec[i].name == this->vec[j].name) {
				this->vec[j].po++;
			}
		}
	}
}


void Game_polikarpov::phase5() {
	std::sort(this->vec.begin(), this->vec.end(), [](Player first, Player second) {
		if (first.count_building != second.count_building) {
			return first.count_building > second.count_building;
		}
		else {
			return ((first.gold + first.wood + first.stone) > (second.gold + second.wood + second.stone));
		}
		});
	std::vector<Player> new_vec = { this->vec[0] }; //вектор нуждающихся игроков
	for (int i = 0; i < this->vec.size() - 1; i++) {
		if ((this->vec[i].gold + this->vec[i].stone + this->vec[i].wood) == (this->vec[i + 1].gold + this->vec[i + 1].stone + this->vec[i + 1].wood)) {
			new_vec.push_back(this->vec[i + 1]);
		}
	}
	for (int i = 0; i < new_vec.size(); i++) {
		new_vec[i].poslannik = 1;
	}
}

void Game_polikarpov::phase7() {
	for (int i = 0; i < this->count_players; i++) {
		vec[i].military_register += (vec[i].gold + vec[i].wood + vec[i].stone) / 2;
	}
}

void Game_polikarpov::defense_level(const char* enemy_name, int king_help)
{

}
