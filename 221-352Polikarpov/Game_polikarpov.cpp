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
	for (int i = 0; i < vec.size(); i++) {
		vec[i].cube_1 = toss_cube(1, 6);
		vec[i].cube_2 = toss_cube(1, 6);
		vec[i].cube_3 = toss_cube(1, 6);
		if (pl[i].cube_1 == vec[i].cube_1 == vec[i].cube_1) {
			i--;
		}
	}
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = 0; j < vec.size() - 2; j++) {
			if (vec[j].cube_1 + vec[j].cube_2 + vec[j].cube_3 > vec[j + 1].cube_1 + vec[j + 1].cube_2 + vec[j + 1].cube_3) {
				Player change = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = change;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		vec[i].order = i + 1;
	}
}


void kingsburg::phase246_advisor()
{
	void advisor_help(); // заглушка по требованиям



}

void kingsburg::advisor_help()
{
	for (int i = 0; i < player_number; i++) {
		if (vec[i].advisor == 1) {
			vec[i].victory_score += 1;
		}
		else if ([i].advisor == 2) {
			vec[i].gold += 1;
		}
		else if (vec[i].advisor == 3) {
			vec[i].wood += 1;
		}
		else if (vec[i].advisor == 4) {
			std::cout << "Золото или дерево? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				vec[i].gold += 1;
			}
			else if (num == 2) {
				vec[i].wood += 1;
			}
		}
		else if (vec[i].advisor == 5) {
			vec[i].military_register += 1;
		}
		else if (vec[i].advisor == 6) {
			vec[i].stone -= 1;
			vec[i].wood += 1;
			vec[i].gold += 1;
		}
		else if (vec[i].advisor == 7) {
			vec[i].stone += 1;
			vec[i].tokens += 2;
		}
		else if (vec[i].advisor == 8) {
			vec[i].gold += 2;
		}
		else if (vec[i].advisor == 9) {
			vec[i].wood += 1;
			std::cout << "Золото или Камень? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				vec[i].gold += 1;
			}
			else if (num == 2) {
				vec[i].stone += 1;
			}
		}
		else if (vec[i].advisor == 10) {
			vec[i].victory_score += 2;
		}
		else if (vec[i].advisor == 11) {
			vec[i].stone += 1;
			std::cout << "Золото или дерево? Введите 1 или 2 соответственно" << std::endl;
			int num;
			std::cin >> num;
			if (num == 1) {
				vec[i].gold += 1;
			}
			else if (num == 2) {
				vec[i].wood += 1;
			}
		}
		else if (vec[i].advisor == 12) {
			vec[i].stone += 1;
			vec[i].tokens += 2;
			vec[i].gold += 1;
		}
		else if (vec[i].advisor == 13)
		{
			vec[i].stone += 3;
		}
		else if (vec[i].advisor == 14)
		{
			vec[i].victory_score -= 1;
			vec[i].gold += 3;
		}
		else if (vec[i].advisor == 15)
		{
			vec[i].wood += 1;
			vec[i].stone += 1;
			vec[i].gold += 1;
		}
		else if (vec[i].advisor == 16)
		{
			vec[i].gold += 3;
		}
		else if (vec[i].advisor == 17)
		{
			vec[i].stone += 2;
			vec[i].victory_score += 3;
		}
		else if (vec[i].advisor == 18) {
			vec[i].stone += 1;
			vec[i].gold += 1;
			vec[i].wood += 1;
			vec[i].victory_score += 1;
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
			fout << "Игрок № " << i + 1 << ":" << '\n' << this->vec[i].name << '\t' << "Кол-во золота: " << this->vec[i].gold << '\t';
			fout << "Кол-во дерева: " << this->vec[i].wood << '\t' << "Кол-во камня: " << this->vec[i].stone << '\n';
			fout << '\n' << "Количество жетонов:" << this->vec[i].tokens << '\t' << "Значение воинского реестра: " << this->vec[i].military_register << '\t';
		}
		return true;
	}
	fout.close();
	return false;
}


bool kingsburg::load_game(const char* filename)
{
	std::ifstream fin(filename);
	if (fin.is_open()) {
		fin >> this->player_number;
		for (int i = 0; i < this->player_number; i++) {
			Player new_game;
			fin >> new_game.name >> new_game.gold >> new_game.wood >> new_game.stone >> new_game.tokens >> new_game.military_register;
			pl.push_back(new_game);
		}
		return true;
		fin.close();
	}

	return false;
}

void kingsburg::building(const char* building, Player pa)
{
	if (building == "Собор") {
		pa.victory_score += (pa.gold + pa.wood + pa.stone) / 2;
		pa.buildings = 1;
	}
	else if (building == "Ферма") {
		pa.military_register--;
		pa.buildings = 1;
		if (pa.buildings != 0) {
			pa.gold--;
			pa.wood -= 3;
			pa.stone--;
		}
	}
	else if (building == "Крепость") {
		pa.victory_score++;
		pa.buildings = 1;
	}
	else if (building == "Башня") {
		pa.buildings = true;
	}
	else if (building == "Посольство") {
		pa.victory_score++;
	}




