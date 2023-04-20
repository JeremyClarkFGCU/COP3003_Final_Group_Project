#ifndef ROLLS_H
#define ROLLS_H
// =============
// Include files
// =============

// Libraries needed for random number generator.
#include <cstdlib> // random numbers
#include <ctime> // seed random
#include "timer.h" // 
#include "classes.h"
#include "function_defs.h"

int roll_attribute() {
	int n = rand() % STAT_DIE + 1;
	return n;
}

bool roll_battle(Player p) {
	print("rolling for battle.\n");
	wait(1.0);
	if (p.get_direction() == STAY) {
		int n = rand() % 100 + 1;
		cout << "You rolled " << n << "!" << endl;
		if (n <= 12) {
			print("Battle Flag set to true.\n");
			wait(1.0);
			return true;
		}
		else {
			print("Battle Flag set to false.\n");
			wait(1.0);
			return false;
		}
	}
	else {
		return false;
	}
}

int monster_roll() {
	int sample = sizeof(monsterArray)/sizeof(Enemy);
	cout << "Sample size: " << sample << endl;
	int r = rand() % 100;
	float f = rand() % 100;
	f /= 1000;
	wait(f);
	int s = rand() % 99;
	int i = r*s % sample;
	cout << "Rolled " << i << "!" << endl;
	return i;
}

#endif

