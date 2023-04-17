
// ==============================================
// | function_defs.h							|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: function definitions	|
// ==============================================
#ifndef FUNCTION_DEFS_H
#define FUNCTION_DEFS_H

// ====================
// Function Definitions
// ====================


string get_string() { // Get string input from user.
	string s;
	cin >> s;
	return s;
}// End of get_string

int get_integer() { //get an integer input from user.
	int n;
	cin >> n;
	return n;
}// End of get_integer


//===========================
// Polymorphism				|
// Overloaded print function|
//===========================

void print(Player p) { // print Overload - Display player attributes to user.
	cout << endl;
	wait(0.5);
	cout << "====================" << endl;
	cout << p.name << ", Level " << p.level << endl;
	cout << "====================" << endl;
	cout << "HP:  " << p.currentHealth << " / " << p.maxHealth << endl;
	cout << "STR: " << p.strength << "\tSTA: " << p.stamina << "\tSPD: " << p.speed << endl;
	cout << "ATK: " << p.attack << "\tDEF: " << p.defense << endl;
} // End print Player class

void print(Enemy e) { // print Overload -  Display enemy attributes to user.
	cout << endl;
	wait(0.5);
	cout << "====================" << endl;
	cout << e.name << ", Level " << e.level << endl;
	cout << "====================" << endl;
	cout << "HP:  " << e.currentHealth << " / " << e.maxHealth << endl;
	cout << "ATK: " << e.attack << "\tDEF: " << e.defense << "\tSPD: " << e.speed << endl;
} // End print Enemy class

void print(string s) { // print Overload -  Display string to user.
	cout << "\n" << s << endl;
}// End print string



bool check_for_boundary(Player & p) { // Checks player position to determine if at edge of map.
	if (p.get_x_position() == 50 || p.get_x_position() == 0 || p.get_y_position() == 0 || p.get_x_position() == 50 || p.get_direction() == 0) {
		return true;
	}
	else { return false; }
} // End of check_for_boundary.


void move(Player& p) {
	switch (p.get_direction()) {
	case STAY:
		break;
	case NORTH:
		if (p.get_y_position() < 50) {
			p.go_north();

		}
		else { print("You have reached the northern boundary."); }
		break;
	case SOUTH:
		if (p.get_y_position() > 0) {
			p.go_south();

		}
		else { print("You have reached the southern boundary."); }
		break;
	case EAST:
		if (p.get_x_position() < 50) {
			p.go_east();

		}
		else { print("You have reached the eastern boundary."); }
		break;
	case WEST:
		if (p.get_x_position() > 0) {
			p.go_west();

		}
		else { print("You have reached the western boundary."); }
		break;
	}
}

bool travel(Player& p) {
	print("\n");
	p.print_position();
	wait(1.0);
	print("\n");
	bool at_boundary = check_for_boundary(p);
	if (at_boundary == true) {
		p.set_direction();
	}
	else {
		move(p);
	}
	bool fightFlag = roll_battle();
	return fightFlag;
}


#endif