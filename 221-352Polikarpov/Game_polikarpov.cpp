#include "kingsburg.h"




kingsburg::Game_polikarpov()
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

kingsburg::Game_polikarpov()
{
	std::cout << "Деструктор";
}

kingsburg::Game_polikarpov(int count_players)
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

void kingsburg::phase1()
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

void kingsburg::phase3() {
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


void kingsburg::phase5() {
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

void kingsburg::phase7() {
	for (int i = 0; i < this->count_players; i++) {
		vec[i].military_register += (vec[i].gold + vec[i].wood + vec[i].stone) / 2;
	}
}

void kingsburg::defense_level(const char* enemy_name, int king_help)
{

}
int toss_cube(int nil, int max) {

	srand(time(NULL));

	// Получить случайное число - формула 
	int num = nil + rand() % (max - nil + 1);

	return num;
}

void kingsburg::phase246_bonus()
{
	for (int i = 0; i < pl.size(); i++) {
		pl[i].cube_1 = toss_cube(1, 6);
		pl[i].cube_2 = toss_cube(1, 6);
		pl[i].cube_3 = toss_cube(1, 6);
		if (pl[i].cube_1 == pl[i].cube_1 == pl[i].cube_1) {
			i--;
		}
	}
	for (int i = 0; i < pl.size() - 1; i++) {
		for (int j = 0; j < pl.size() - 2; j++) {
			if (pl[j].cube_1 + pl[j].cube_2 + pl[j].cube_3 > pl[j + 1].cube_1 + pl[j + 1].cube_2 + pl[j + 1].cube_3) {
				Player change = pl[j];
				pl[j] = pl[j + 1];
				pl[j + 1] = change;
			}
		}
	}
	for (int i = 0; i < pl.size(); i++) {
		pl[i].order = i + 1;
	}
}


void kingsburg::phase246_advisor()
{
	void advisor_help(); // заглушка по требованиям



}

void kingsburg::advisor_help()
{
	for (int i = 0; i < player_number; i++) {
		if (pl[i].advisor == 1) {
			pl[i].victory_score += 1;
		}
		else if (pl[i].advisor == 2) {
			pl[i].gold += 1;
		}
		else if (pl[i].advisor == 3) {
			pl[i].wood += 1;
		}
		else if (pl[i].advisor == 4) {
			std::cout << "Золото или дерево? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				pl[i].gold += 1;
			}
			else if (num == 2) {
				pl[i].wood += 1;
			}
		}
		else if (pl[i].advisor == 5) {
			pl[i].military_register += 1;
		}
		else if (pl[i].advisor == 6) {
			pl[i].stone -= 1;
			pl[i].wood += 1;
			pl[i].gold += 1;
		}
		else if (pl[i].advisor == 7) {
			pl[i].stone += 1;
			pl[i].tokens += 2;
		}
		else if (pl[i].advisor == 8) {
			pl[i].gold += 2;
		}
		else if (pl[i].advisor == 9) {
			pl[i].wood += 1;
			std::cout << "Золото или Камень? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				pl[i].gold += 1;
			}
			else if (num == 2) {
				pl[i].stone += 1;
			}
		}
		else if (pl[i].advisor == 10) {
			pl[i].victory_score += 2;
		}
		else if (pl[i].advisor == 11) {
			pl[i].stone += 1;
			std::cout << "Золото или дерево? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				pl[i].gold += 1;
			}
			else if (num == 2) {
				pl[i].wood += 1;
			}
		}
		else if (pl[i].advisor == 12) {
			pl[i].stone += 1;
			pl[i].tokens += 2;
			pl[i].gold += 1;
		}
		else if (pl[i].advisor == 13)
		{
			pl[i].stone += 3;
		}
		else if (pl[i].advisor == 14)
		{
			pl[i].victory_score -= 1;
			pl[i].gold += 3;
		}
		else if (pl[i].advisor == 15)
		{
			pl[i].wood += 1;
			pl[i].stone += 1;
			pl[i].gold += 1;
		}
		else if (pl[i].advisor == 16)
		{
			pl[i].gold += 3;
		}
		else if (pl[i].advisor == 17)
		{
			pl[i].stone += 2;
			pl[i].victory_score += 3;
		}
		else if (pl[i].advisor == 18) {
			pl[i].stone += 1;
			pl[i].gold += 1;
			pl[i].wood += 1;
			pl[i].victory_score += 1;
		}

	}
}

bool kingsburg::save_game(const char* filename)
{
	std::ofstream fout;
	fout.open(filename, std::ios_base::binary);
	if (fout.is_open()) {
		fout << "Кол-во игроков: ";
		fout << this->players << '\n';
		for (int i = 0; i < this->players; i++) {
			fout << "Игрок № " << i + 1 << ":" << '\n' << this->pl[i].name << '\t' << "Кол-во золота: " << this->pl[i].gold << '\t';
			fout << "Кол-во дерева: " << this->pl[i].wood << '\t' << "Кол-во камня: " << this->pl[i].stone << '\n';
			fout << '\n' << "Количество жетонов:" << this->pl[i].tokens << '\t' << "Значение воинского реестра: " << this->pl[i].military_register << '\t';
		}
		return true;
	}
	fout.close();
	return false;
}


