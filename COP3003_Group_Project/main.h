// ==========================================================
// Main Header File for Final Group Project
// Authors: Jeremy Clark, Markendy Pierre, Rainier St. Fort.
// ==========================================================


#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

// ==============================================
// Header Includes
// ==============================================

#include <iostream>



using namespace std;


// ================
// Global Constants
// ================


// Dice for random rolls
const int STAT_DIE = 5;
const int ENEMY_LEVEL_DIE = 5;


// Case constants for directional movement.
const int STAY = 0;
const int NORTH = 1;
const int SOUTH = 2;
const int EAST = 3;
const int WEST = 4;

// Case constants for battle menu
const int ATTACK = 1;
const int DEFEND = 2;
const int ITEM = 3;
const int RUN = 4;

// ================
// Global Variables
// ================



int enemyLevelArray[5] = { -2, -1, 0, 1, 2 };


// ==============================================
// Flags
// ==============================================

bool exitFlag = false;// Initialize exit as false.



// ==============================================
// Forward Declarations for Functions
// ==============================================
string get_string();
int get_integer();
int roll_attribute();
void print();
void create_equipment();




#endif