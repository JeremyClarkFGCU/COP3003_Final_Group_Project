// ==============================================
// | classes.h									|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: Contains Entity Classes for game.	|
// ==============================================


#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
// ==================
// Weapon Class
// ==================
class Weapon {

private:

	std::string name;
	int attackBonus = 0;

public:

	// Default Constructor - Compiler wasn't happy.
	Weapon() = default;

	// Weapon Constructor
	Weapon(std::string weaponName, int value) {
		name = weaponName;
		attackBonus = value;
	}// End of Weapon Constructor

	// Public Member Functions
	std::string get_name() {return name;}
	int get_attack_bonus() {return attackBonus;}

};// End of Weapon Class


// ==================
// Armor Class
// ==================
class Armor {
private:
	string name;
	int defenseBonus = 0;

public:

	// Armor Constructors
	Armor() = default; // Compiler wanted this.
	Armor(string armorName, int value) {
		name = armorName;
		defenseBonus = value;
	}// End of Armor Constructor

	// Public Member Functions of Armor
	string get_name() { return name; }
	int get_defense_bonus() { return defenseBonus;}

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

	// Player  Class Constructor
	Player() = default;

	Player::Player(int i) { // Player constructor
		cout << "What is your character's name?: ";
		name = get_string();
		system("cls");
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
		wait(1.5);
		system("cls");
		cout << endl << "Your character, " << name << " has been created!\n" << endl;
	}// End of Player constructor.
	

	// Public Member Functions

	void set_max_health(int value) {maxHealth = value;}// Set Player max Health
	int get_max_health() {	return maxHealth;}// Returns Player Max HP

	void set_current_health(int value) {currentHealth = value;}// Set Player Current Health
	int get_current_health() {return currentHealth;} // Returns Player current HP

	void set_strength(int i) { strength = i;}
	int get_strength() { return strength; }

	void set_stamina(int i) { stamina = i; }
	int get_stamina() { return stamina; }

	void set_speed(int i) { speed = i; }
	int get_speed() { return speed;}


	void calculate_attack() {
		attack = (strength + equippedWeapon.get_attack_bonus());
	}
	int get_attack() { return attack; }

	void calculate_defense() {
		defense = (stamina + equippedArmor.get_defense_bonus());
	}
	int get_defense() { return defense; }

	void initialize_combat_attribues() {// Set strength, stamina, and speed.
		maxHealth = (((strength * strength) % 50) / 2)  + 25;
		calculate_attack();
		calculate_defense();
	} // End initialize_combat_attributes

	void set_position(int x, int y) {
		xPosition = x;
		yPosition = y;
	}

	int get_x_position() {	return xPosition;}
	int get_y_position() {	return yPosition;}

	void print_position() {
		cout << "Position: (" << this->xPosition << ", " << this->yPosition << ")" << endl;
	}

	int get_direction() {	return direction;}// End get_direction

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

	string get_armor_name() {
		return equippedArmor.get_name();
	}

	string get_weapon_name() {
		return equippedWeapon.get_name();
	}

	void equip(Weapon weapon) {
		equippedWeapon = weapon;
		calculate_attack();
		cout << "You've equipped " << equippedWeapon.get_name() << endl;
	}

	void equip(Armor armor) { // Overload equip to handle objects of class Armor
		equippedArmor = armor;
		calculate_defense();
		cout << "You've equipped " << equippedArmor.get_name() << endl;
	}

};// End Player Class


//============
// Enemy Class
//============
class Enemy : public Character {
private:
	int maxHealth;
	int currentHealth;
	int baseAttack;
	int attack;
	int baseDefense;
	int defense;
	int speed;
	int baseSpeed;


public:

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
		int n = rand() % ENEMY_LEVEL_DIE;
		n -= 2;
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
	string get_name() { return name; }

	int get_current_health() { return currentHealth; }
	void set_current_health(int i) { currentHealth = i; }

	int get_max_health() { return maxHealth; }

	int get_attack() { return baseAttack; }
	int get_defense() { return baseDefense; }
	int get_speed() { return speed; }
};// End Enemy Class ======================


// =========================
// INITIALIZE ENTITY OBJECTS
// =========================

// Weapon Objects
// ==============
Weapon noWeapon("No Weapon, No-Hands", 0);
Weapon ironSword("Iron Sword, One-Hand", 3);
Weapon mace("Mace, One-Hand", 2);
Weapon dagger("Dagger, One-Hand", 2);
Weapon lance("Lance, Both-Hands", 4);
Weapon pike("Pike, Both-Hands", 3);
Weapon halberd("Halberd, Both-Hands", 4);

Weapon weaponArray[7]{ noWeapon, ironSword, mace, dagger, lance, pike,halberd };

// Armor Objects
Armor noArmor("No Armor", 0);
Armor clothArmor("No Armor", 1);
Armor leatherArmor("Leather Armor", 2);
Armor mailArmor("Chainmail Armor", 4);
Armor plateArmor("Leather Armor", 6);

Armor armorArray[5]{ noArmor, clothArmor, leatherArmor, mailArmor, plateArmor };


// Create monsters
// ========================================
Enemy wolf("Wolf", 2, 0, 2);
Enemy rat("Rat",1,0,3);
Enemy ogre("Ogre", 2, 2, 1);
Enemy lizard("Lizard", 2, 1, 3);
Enemy giant("Giant", 3, 3, 0);
Enemy dragon("Dragon", 5, 5, 2);

// Array of possible monster encounters.
Enemy monsterArray[6]{ wolf, rat, ogre, lizard, giant, dragon};

// ===============================
// Forward Function Declarations 2
// ===============================

// The following functions were needed by the compiler to be declared
// after Classes are defined, since they were passed Classes as arguments.
Enemy encounter(Player p);
bool travel(Player& p);
void move(Player& p);

#endif