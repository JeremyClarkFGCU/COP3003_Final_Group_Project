// ==============================================
// | menu.h										|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains operations for game menus	|
// ==============================================

#ifndef IN_GAME_MENU
#define IN_GAME_MENU

#include "function_defs.h"
#include "classes.h"


using namespace std;

void start_menu() {
	cout << "Choose an option:\n" << endl;
	cout << "1. New Game" << endl;
	cout << "0. Quit" << endl;
	int choice = get_integer();

	switch (choice) {
	case 0:
		exitFlag = true;
		break;
	case 1:
		break;
	}
}

void select_weapon(Player & p) {
	cout << "You currently have " << p.get_weapon_name() << " equipped.\n";
	cout << "Equip one of the following?" << endl;
	int i = 0;
	for (Weapon weapon : weaponArray) {
		cout << i << ". " << weapon.get_name() << endl;
		++i;
	}
	int c = get_integer();
	p.equip(weaponArray[c]);
}// Menu to select and equip new weapon.

void select_armor(Player & p) {
	cout << "You currently have " << p.get_armor_name() << " equipped.\n";
	cout << "Equip one of the following?\n";
}// Menu to select and equip new armor.

void equipment_menu(Player & p) {
	system("cls");
	cout<< "Select Equipment:"<< endl;
	cout << endl;
	cout << "1. Weapon" << endl;
	cout << "2. Armor" << endl;
	int equipmentChoice = get_integer();

	switch(equipmentChoice){
		case 1:
			select_weapon(p);
			break;
		case 2:
			select_armor(p);
			break;
		case 0:
			break;
	};
}

void in_game_menu(Player& p) {

	cout << "Menu:" << endl;
	cout << "1. Character Stats" << endl;
	cout << "2. Equipment" << endl;
	cout << "3. Use Items" << endl;
	cout << "0. Exit" << endl;

	int menuChoice = get_integer();

	switch (menuChoice) {
	case 1:
		system("cls");
		print(p);
		cout << endl << endl;
			cout<< "Enter 0 to go back" << endl;
			int goBack;
			cin >> goBack;
		break;
	case 2:
		equipment_menu(p);
		break;

	case 0:
		break;
	}
}

#endif




