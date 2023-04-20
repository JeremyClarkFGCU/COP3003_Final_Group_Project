// ============================================================
// | COP3003 Final Group Project - Main						  |
// | Authors: Jeremy Clark, Rainier St. Fort, Markendy Pierre |
// | File: main.cpp                                           |
// ============================================================

// Include files
#include "main.h"
#include "game.h"

// Main Function
// =============
int main(){
	Game game1;
	game1.initialize(game1.player);
	game1.run(game1.player);
}// End Main