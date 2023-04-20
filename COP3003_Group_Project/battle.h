// ==============================================
// | battle.h									|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Battle Mechanics			|
// ==============================================

#ifndef BATTLE_H
#define BATTLE_H

#include "classes.h"
#include "timer.h"
#include "menu.h"

//=======================
// MOVE TO MENU
// BATTLE MENU
//=======================


Enemy encounter(Player p) {
	int x = monster_roll();
	Enemy e = monsterArray[x];
	system("cls");
	cout << "\nYou've encountered an enemy " << e.get_name() << "!\n" << endl;
	e.create_instance(p);
	print(e);
	wait(1.5);
	return e;
} // End encounter

void attack(Player& p, Enemy& e){
	system("cls");
	print(p, e);
	print("Attacking!");
	wait(0.75);
	if (e.get_speed() > p.get_speed()) {// If enemy is faster.
		int damage = e.level + e.get_attack() - p.get_defense();
		if (damage < 1) { damage = 1; }
		p.set_current_health(p.get_current_health() - damage);
		system("cls");
		print(p, e);;cout << endl;
		cout << "Enemy " << e.name << " dealt " << damage << " damage to " << p.name << "!" << endl;
		wait(0.75);
		if (p.get_current_health() > 0) {
			damage = p.level + p.get_attack() - e.get_defense();
			if (damage < 1) { damage = 1; }
			e.set_current_health(e.get_current_health() - damage);
			system("cls");
			print(p, e);cout << endl;
			cout << p.name << " dealt " << damage << " damage to enemy " << e.name << "!" << endl;
			wait(0.75);
		}
		else {
			system("cls");
			print("You lost the battle.");
			print(p);
			wait(2.0);
		}
	} // End enemy is faster
	else { // Player speed is == or greater.
		int damage = p.level + p.get_attack() - e.get_defense();
		if (damage < 1) { damage = 1; }
		e.set_current_health(e.get_current_health() - damage);
		system("cls");
		print(p, e);;cout << endl;
		cout << p.name << " dealt " << damage << " damage to enemy " << e.name << "!" << endl;
		wait(0.75);
		if (e.get_current_health() > 0) {
			damage = e.level + e.get_attack() - p.get_defense();
			if (damage < 1) { damage = 1; }
			p.set_current_health(p.get_current_health() - damage);
			system("cls");
			print(p, e);;cout << endl;
			cout << "Enemy " << e.name << " dealt " << damage << " damage to " << p.name << "!" << endl;
			wait(0.75);
		}
		else {
			system("cls");
			print("You won the battle!");
			print(p);
			wait(2.0);
		}
	} // End Player is faster.
}

void battle_menu(Player & p, Enemy & e) {
	print("What would you like to do?");
	cout << ATTACK << ". Attack" << endl;
	cout << DEFEND << ". Defend" << endl;
	cout << ITEM   << ". Item" << endl;
	cout << RUN    << ". Run" << endl;
	int battleChoice = get_integer();

	switch (battleChoice) {
	case ATTACK:
		attack(p, e);
		break;
	case DEFEND:
		system("cls");
		print("Defend feature coming soon!");
		wait(1.5);
		break;
	case ITEM:
		system("cls");
		print("Items feature coming soon!");
		wait(1.5);
		break;
	case RUN:
		system("cls");
		print("Escape feature coming soon!");
		wait(1.5);
		break;
	}
}// End battle_menu

void do_battle(bool flag, Player & p) {
	if (flag == true) {
		Enemy e = encounter(p);
		while (p.get_current_health() > 0 && e.get_current_health() > 0) {// Battle Loop
			system("cls");
			print(p, e);
			battle_menu(p, e);
		}// End Battle Loop
	}
	else {
		print("No Battle!");
	}
} // End do_battle





#endif