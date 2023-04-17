
// ==============================================
// | game.h										|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Gameplay Mechanics			|
// ==============================================
#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "rolls.h" // Needed for rolling random numbers.
#include "timer.h"
#include "classes.h"
#include "function_defs.h"
#include "battle.h"



class Game {
private:
	Player player;
	bool battleFlag;
	int turn = 0;

public:
	void initialize() {
		cout << "Welcome! Setting up the game." << endl;
		wait(1.0);
		player = Player(1);
		wait(0.75);
		print(player);
		wait(0.75);
		print("\n");
		player.equip(noArmor);
		wait(0.75);
		player.equip(noWeapon);
		print("\n");
		wait(1.5);
		player.set_direction();

	}

	void run() {
		while (exitFlag == false) {
			turn += 1;
			wait(0.75);
			print("\nStarting Main Game Loop\n");
			wait(0.75);
			cout << "Turn: " << turn << endl;
			wait(2.0);
			battleFlag = false;
			print("Battle Flag set to false!");
			wait(0.75);
			print(player);
			wait(1.0);
			battleFlag = travel(player);
			do_battle(battleFlag, player);
		}
	}

};


#endif