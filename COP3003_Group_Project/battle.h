// ==============================================
// | battle.h									|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Battle Mechanics	|
// ==============================================

#ifndef BATTLE_H
#define BATTLE_H

#include "classes.h"
#include "timer.h"

Enemy encounter(Player p) {
	int x = monster_roll();
	Enemy e = monsterArray[x];
	cout << "\nYou've encountered an enemy " << e.get_name() << "!\n" << endl;
	e.create_instance(p);
	print(e);
	return e;
} // End encounter

void attack(Player & p, Enemy & e) {
	print("Attacking!");
	wait(0.75);
	if (e.get_speed() > p.get_speed()) {// If enemy is faster.
		int damage = e.level + e.get_attack() - p.get_defense();
		if (damage < 1) { damage = 1; }
		p.set_current_health(p.get_current_health() - damage);
		cout << "Enemy " << e.name << " dealt " << damage << " damage to " << p.name << "!" << endl;
		wait(0.75);
		if (p.get_current_health() > 0) {
			damage = p.level + p.get_attack() - e.get_defense();
			if (damage < 1) { damage = 1; }
			e.set_current_health(e.get_current_health() - damage);
			cout << p.name << " dealt " << damage << " damage to enemy " << e.name << "!" << endl;
			wait(0.75);
		}
		else {
		}
	} // End enemy is faster
	else { // Player speed is == or greater.
		int damage = p.level + p.get_attack() - e.get_defense();
		if (damage < 1) { damage = 1; }
		e.set_current_health(e.get_current_health() - damage);
		cout << p.name << " dealt " << damage << " damage to enemy " << e.name << "!" << endl;
		wait(0.75);
		if (e.get_current_health() > 0) {
			damage = e.level + e.get_attack() - p.get_defense();
			if (damage < 1) { damage = 1; }
			p.set_current_health(p.get_current_health() - damage);
			cout << "Enemy " << e.name << " dealt " << damage << " damage to " << p.name << "!" << endl;
			wait(0.75);
		}
		else {
			print("You won the battle!");
		}
	} // End Player is faster.
}

void do_battle(bool flag, Player & p) {
	if (flag == true) {
		Enemy e = encounter(p);
		while (p.get_current_health() > 0 && e.get_current_health() > 0) {// Battle Loop
			print("Battle!");
			print(p, e);
			attack(p, e);
		}// End Battle Loop
	}
	else {
		print("No Battle!");
	}
} // End do_battle





#endif