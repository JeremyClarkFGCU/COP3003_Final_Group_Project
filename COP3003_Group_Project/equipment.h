#ifndef EQUIPMENT_H
#define EQUIPMENT_H

// ==============================================
// Weapon Class
// ==============================================
class Weapon {
private:
	int attackBonus;
public:
	//Public Attributes
	std::string name;

	// Constructor
	Weapon(std::string name, int x) {
		attackBonus = x;
		name = name;
	}

	// Member Functions
	int get_attack_bonus() {
		int bonusValue = attackBonus;
		return attackBonus;
	}
};
#endif