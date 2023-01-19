#include "kingsburg.h"


int main() {
	setlocale(LC_ALL, "RUS");
	kingsburg new_game(3);
	new_game.phase1();
	new_game.phase3();
	new_game.phase5();
	new_game.phase7();
}