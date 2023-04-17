// ==============================================
// | battle.h									|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Battle Mechanics	|
// ==============================================

#ifndef BATTLE_H
#define BATTLE_H

#include "classes.h"

Enemy encounter(Player p) {
	int x = monster_roll();
	cout << "\n Index: " << x <<  "\n" << endl;
	int i = rand() % 3;
	Enemy e = monsterArray[i];
	cout << "\nYou've encountered an enemy " << e.name << "!\n" << endl;
	e.create_instance(p);
	print(e);
	return e;
}

void do_battle(bool flag, Player p) {
	if (flag == true) {
		Enemy enemy1 = encounter(p);
		print("Battle!");
	}
	else {
		print("No Battle!");
	}
}
#endif