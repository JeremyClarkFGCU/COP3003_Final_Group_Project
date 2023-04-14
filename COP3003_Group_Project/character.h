//Header File for Character Classes and Sub-Classes
#ifndef CHARACTER_H
#define CHARACTER_H


// ==============================================
// Character Class
// ==============================================
class Character {
public:
	std::string name;
	int level;
}; // END Character class


// ==============================================
// Player Class: Sub-Class of Character
// ==============================================

class Player : public Character {
private:

	// Base Attributes
	int maxHealth;
	int strength;
	int stamina;
	int speed;

	// Battle Attributes
	int attack;
	int defense;

	// Position Data
	int xPosition;
	int yPosition;



public:

	Weapon equippedWeapon;

	std::string get_name() {

	}
};
#endif
