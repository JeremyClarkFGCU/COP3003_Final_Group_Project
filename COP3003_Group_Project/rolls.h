#ifndef ROLLS_H
#define ROLLS_H
// =============
// Include files
// =============



// Needed for random number generator.
#include <cstdlib> // random numbers
#include <ctime> // seed random
#include "timer.h" // 
#include "classes.h"

int roll_attribute() {
	int n = rand() % STAT_DIE + 1;
	return n;
}

bool roll_battle() {
	int n = rand() % 100 + 1;
	cout << "You rolled " << n << "!" << endl;
	if (n <= 12) {
		return true;
	}
	else {
		return false;
	}
}

int monster_roll() {
	int sample = sizeof(monsterArray)/sizeof(Enemy);
	cout << sample;
	return sample;
}

#endif

