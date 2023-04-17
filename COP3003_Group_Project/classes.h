// ==============================================
// | classes.h									|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Entity Classes for game.	|
// ==============================================

#ifndef CLASSES_H
#define CLASSES_H



// ==================
// Weapon Class
// ==================

class Weapon {

private:
	std::string name;
	int attackBonus = 0;
public:

	// Default Constructor

	Weapon() = default;

	// Weapon Constructor
	Weapon(std::string weaponName, int value) {
		name = weaponName;
		attackBonus = value;
	}// End of Weapon Constructor

	// Public Member Functions
	std::string get_name() {
		std::string s = name;
		return s;
	}

	int get_attack_bonus() {
		int value = attackBonus;
		return value;
	}
};// End of Weapon Class


// ==================
// Armor Class
// ==================
class Armor {
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

	// Public Member Functions of Armor
	string get_name() {
		string s = name;
		return s;
	}

	int get_defense_bonus() {
		int value = defenseBonus;
		return value;
	}
};// End of Armor Class
// =================================================================================



// ==================
// CHARACTER CLASS
// ==================

class Character {
public:
	string name;
	int level = 1;
};



// ==================
// PLAYER CLASS
// ==================
class Player : public Character {
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

	friend void print(Player p);// Makes print(class) a friend function.

		friend void print(Player p);// Makes print(class) a friend function.



	// Player  Class Constructor
	// =========================

		Player() = default;

	Player::Player(int i) { // Player constructor
		cout << "What is your character's name?: ";
		name = get_string();
		wait(1);
		cout << "\nInitializing " << name << "'s attributes." << endl;
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
		initialize_combat_attribues();
		currentHealth = maxHealth;
		set_position(25, 10);
		wait(0.75);
		cout << endl << "Your character, " << name << " has been created!\n" << endl;
	}// End of Player constructor.


	void set_max_health(int value) {
		maxHealth = value;
	}// Set Player max Health

	int get_max_health() {
		int n = maxHealth;
		return n;
	}// Returns Player Max Health

	void set_current_health(int value) {
		currentHealth = value;
	}// Set Player Current Health

	int get_current_health() {
		int n = currentHealth;
		return n;
	}


	void initialize_combat_attribues() {// Set strength, stamina, and speed.
		maxHealth = (strength * strength) / (50 / level) + 25;
		attack = (strength + equippedWeapon.get_attack_bonus());
		defense = (stamina + equippedArmor.get_defense_bonus());
	}



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

	int get_direction() { // get's current player direction.
		int n = direction;
		return n;
	}// End get_direction

	void set_direction() { // Set direction of player movement.
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
			cout << "4. West" << endl;
		}
		cout << "\n0. Stay Put" << endl;

		cin >> direction;

	}// End set direction

	// PLAYER MOVEMENT - Changes Position

	void go_north() { // Move player in positive Y-direction.
		this->yPosition += 1;
		cout << "Going north!" << endl;
	}// End go_north


	void go_south() { // Move player in negative Y-direction.
		this->yPosition -= 1;
		cout << "Going south!" << endl;
	}//End go_south


	void go_east() {// Move player in the positive X-direction.
		this->xPosition += 1;
		cout << "Going east!" << endl;
	}//End go_east

	void go_west() {// Move player in the negative X-direction.
		this->yPosition -= 1;
		cout << "Going west!" << endl;
	}// End go_west


// Player Member Functions for equipment handling

	void equip(Weapon weapon) {
		equippedWeapon = weapon;
		cout << "You've equipped " << equippedWeapon.get_name() << endl;
	}

	void equip(Armor armor) {
		equippedArmor = armor;
		cout << "You've equipped " << equippedArmor.get_name() << endl;
	}

};// End Player Class



//============
// Enemy Class
//============
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

// =================================================================================

// =========================
// INITIALIZE ENTITY OBJECTS
// =========================


// Weapon Objects
// ==============

Weapon noWeapon("No Weapon", 0);
Weapon woodSword("Wooden Sword", 1);
Weapon ironSword("Iron Sword", 3);

// Armor Objects
// =============

Armor noArmor("No Armor", 0);
Armor leatherArmor("Leather Armor", 2);
Armor chainArmor("Chainmail Armor", 4);


// Create monsters
// ===============

Enemy wolf("Wolf", 2, 0, 2);
Enemy rat("Rat", 0, 0, 3);
Enemy ogre("Ogre", 2, 1, 0);

Enemy monsterArray[3]{ wolf, rat, ogre };

// ===============================
// Forward Function Declarations 2
// ===============================

// The following functions need to be declared immediately after Classes are defined.

Enemy encounter(Player p);
bool travel(Player& p);
void move(Player& p);
void do_battle(bool battleFlag, Player p);

#endif