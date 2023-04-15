// ============================================================
// | COP3003 Final Group Project - Main						  |
// | Authors: Jeremy Clark, Rainier St. Fort, Markendy Pierre |
// | File: main.cpp                                           |
// ============================================================


// =============
// Include files
// =============

#include "main.h"


// Needed for random number generator.
#include <cstdlib> // random numbers
#include <ctime> // seed random

// Needed for Sleep function on Windows Operating system.
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif// End of items needed for Sleep function.

// ================
// Global Constants
// ================

const int STAT_DIE = 4;
const int ENEMY_LVL_DIE = 5;

const int STAY = 0;
const int NORTH = 1;
const int SOUTH = 2;
const int EAST = 3;
const int WEST = 4;



// ==========================
// Global Variables and Flags
// ==========================

// Initialize exit as false.
bool exitFlag = false;
int enemyLevelArray[5] = { -2, -1, 0, 1, 2};


void do_battle();
void wait(float seconds);
string get_string();
int get_integer();
int roll_attribute();
void print();

// ==================
// Class Declarations
// ==================


// Weapon Class

class Weapon {

private:
	string name;
	int attackBonus = 0;
public:

	// Default Constructor
	
	Weapon() = default;

	// Weapon Constructor
	Weapon(string weaponName, int value) {
		name = weaponName;
		attackBonus = value;
	}// End of Weapon Constructor

	// Public Member Functions
	string get_name() {
		string s = name;
		return s;
	}

	int get_attack_bonus() {
		int value = attackBonus;
		return value;
	}
};// End of Weapon Class

// Weapon Objects
Weapon noWeapon("No Weapon", 0);
Weapon woodSword("Wooden Sword", 1);
Weapon ironSword("Iron Sword", 3);



// Armor Class
class Armor{
private:
	string name;
	int defenseBonus = 0;
public:

	// Armor Constructor
	Armor() = default;
	Armor(string armorName, int value) {
		name = armorName;
		defenseBonus = value;
	}// End of Armor Constructor

	// Public Member Functions
	string get_name() {
		string s = name;
		return s;
	}

	int get_defense_bonus() {
		int value = defenseBonus;
		return value;
	}
};

// Armor Objects
Armor noArmor("No Armor", 0);
Armor leatherArmor("Leather Armor", 2);
Armor chainArmor("Chainmail Armor", 4);

class Character {
public:
	string name;
	int level = 1;
};

class Player: public Character {
private:
	// Base Attributes
	int maxHealth;
	int currentHealth;
	int strength;
	int stamina;
	int speed;

	// Combat Attributes
	int attack;
	int defense;
	
	// Location Data
	int xPosition;
	int yPosition;
	int direction = STAY;

	Weapon equippedWeapon;
	Armor equippedArmor;

public:

	// Constructor
	Player() {
		cout << "What is your character's name?: ";
		name = get_string();
		wait(1);
		cout << "Initializing " << name << "'s attributes." << endl;
		level = 1;
		wait(0.75);
		cout << "Rolling strength";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << "." << endl;
		strength = roll_attribute();
		wait(0.75);
		cout << "Rolling stamina";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << "." << endl;
		stamina = roll_attribute();
		wait(0.75);
		cout << "Initializing speed";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << ".";
		wait(0.25);
		cout << "." << endl;
		speed = roll_attribute();
		equippedArmor = noArmor;
		equippedWeapon = noWeapon;
		initialize_combat_attribues();
		currentHealth = maxHealth;
		set_position(25, 10);
		cout << endl << "Your character, " << name << " has been created!" << endl;
	}

	void set_max_health(int value) {
		maxHealth = value;
	}

	int get_max_health() {
		int n = maxHealth;
		return n;
	}

	void set_current_health(int value) {
		currentHealth = value;
	}

	int get_current_health() {
		int n = currentHealth;
		return n;
	}
	void initialize_combat_attribues() {
		maxHealth = (strength * strength)/(50/level)+ 25;
		attack = (strength + equippedWeapon.get_attack_bonus());
		defense = (stamina + equippedArmor.get_defense_bonus());
	}
	friend void print(Player p);

	void set_position(int x, int y) {
		xPosition = x;
		yPosition = y;
	}

	int get_x_position() {
		int n = xPosition;
		return n;
	}
	int get_y_position() {
		int n = yPosition;
		return n;
	}

	void print_position() {
		cout << "Position: (" << this->xPosition << ", " << this->yPosition << ")" << endl;
	}

	void set_direction() {
		cout << "What direction would you like to go?" << endl;
		if (this->yPosition < 50) {
			cout << "1. North" << endl;
		}

		if (this->xPosition > 0) {
			cout << "2. South" << endl;
		}
		if (this->yPosition < 50) {
			cout << "3. East" << endl;
		}

		if (this->yPosition > 0) {
			cout << "2. West" << endl;
		}
		cout << "0. Stay Put" << endl;
		
		cin >> direction;

	}

	void go_north() {
		this->yPosition += 1;
		cout << "Going north!" << endl;
	}
	void go_south() {
		this->yPosition -= 1;
		cout << "Going south!" << endl;
	}
	void go_east() {
		this->xPosition += 1;
		cout << "Going east!" << endl;
		
	}

	void go_west() {
		this->yPosition -= 1;
		cout << "Going west!" << endl;
	}

	int get_direction() {
		int n = direction;
		return n;
	}

};// End Player Class

class Enemy : public Character {
private:
	int attack;
	int baseAttack;
	int defense;
	int baseDefense;
	int speed;
	int baseSpeed;
	int maxHealth;
	int currentHealth;

public:
	string name;
	int level;

	// Default Constructor
	Enemy() = default;

	// Constructor
	Enemy(string s, int baseattack, int basedefense, int basespeed) {
		name = s;
		level = 0;
		attack = 0;
		baseAttack = baseattack;
		defense = 0;
		baseDefense = basedefense;
		baseSpeed = basespeed;
		speed = 0;
		maxHealth = 0;
		currentHealth = maxHealth;
	}
	friend void print(Enemy e);
	void create_instance(Player p) {
		int n = rand() % STAT_DIE;
		if (p.level + n < 1) {
			level = 1;
		}
		else {
			level = p.level + n;
		}
		maxHealth = level * 2 + 25;
		currentHealth = maxHealth;
		attack = level + baseAttack;
		defense = level + baseDefense;
		speed = level + baseSpeed;
	}
};// End Enemy Class



Enemy wolf("Wolf", 2, 0, 2);
Enemy rat("Rat", 0, 0, 3);
Enemy ogre("Ogre", 2, 1, 0);

Enemy monsterArray[3]{wolf, rat, ogre};
// =============================
// Forward Function Declarations
// =============================

Enemy encounter(Player p);
bool roll_battle();
void travel(Player & p);
void move(Player & p);



int main(){
	cout << "Welcome!" << endl;
	Sleep(1000);
	Player Player1;
	Player1.set_direction();
	


	while (exitFlag == false) {
		cout << "This is my main game loop!" << endl;
		wait(0.5);
		print(Player1);
		wait(1);
		travel(Player1);
		
	}
}


// ====================
// Function Definitions
// ====================


string get_string() {
	string s;
	cin >> s;
	return s;
}// End of get_string

int get_integer() {
	int n;
	cin >> n;
	return n;
}// End of get_integer

int roll_attribute() {
	int n = rand() % STAT_DIE + 1;
	return n;
}


void do_battle() {
	string p1 = "Player";

}// End of do_battle


void wait(float seconds) {
	int milliseconds = int(seconds * 1000);
	Sleep(milliseconds);
}// End Wait

void print(Player p) {
	cout << endl;
	wait(0.5);
	cout << "====================" << endl;
	cout << p.name << ", Level " << p.level << endl;
	cout << "====================" << endl;
	cout << "HP:  " << p.currentHealth << " / " << p.maxHealth << endl;
	cout << "STR: " << p.strength << "\tSTA: " << p.stamina << "\tSPD: " << p.speed << endl;
	cout << "ATK: " << p.attack   << "\tDEF: " << p.defense << endl;
}

void print(Enemy e) {
	cout << endl;
	wait(0.5);
	cout << "====================" << endl;
	cout << e.name << ", Level " << e.level << endl;
	cout << "====================" << endl;
	cout << "HP:  " << e.currentHealth << " / " << e.maxHealth << endl;
	cout << "ATK: " << e.attack        << "\tDEF: " << e.defense << "\tSPD: " << e.speed << endl;
}

Enemy encounter(Player p) {
	int i = rand() % 3;
	Enemy e = monsterArray[i];
	cout << "You've encountered an enemy " << e.name << "!\n" << endl;
	e.create_instance(p);
	print(e);
	return e;
}

bool roll_battle() {
	int n = rand() % 100 + 1;
	cout << "You rolled " << n << "!" <<endl;
	wait(1);
	if (n <= 12) {
		return true;
	}
	else {
		return false;
	}
}

void move(Player & p) {
	switch (p.get_direction()) {
	case STAY:
		break;
	case NORTH:
		if (p.get_y_position() < 50) {
			p.go_north();

		}
		else { cout << "You have reached the northern boundary."; }
		break;
	case SOUTH:
		if (p.get_y_position() > 0) {
			p.go_south();

		}
		else { cout << "You have reached the southern boundary."; }
		break;
	case EAST:
		if (p.get_x_position() < 50) {
			p.go_east();

		}
		else { cout << "You have reached the eastern boundary."; }
		break;
	case WEST:
		if (p.get_x_position() > 0) {
			p.go_west();

		}
		else { cout << "You have reached the western boundary."; }
		break;
	}
}

void travel(Player & p) {
	p.print_position();
	if (p.get_x_position() == 50 || p.get_x_position() == 0 || p.get_y_position() == 0 || p.get_x_position() == 50) {
		p.set_direction();
	}
	move(p);
	bool fight = roll_battle();
	if (fight == true) {
		Enemy enemy1 = encounter(p);
	}
	else {
		cout << "No Battle.";
	}
}
