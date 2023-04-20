// ==============================================
// | function_defs.h							|
// | Authors; Rainier St. Fort, Markendy Pierre	|
// | Desc: function definitions	|
// ==============================================
#ifndef FUNCTION_DEFS_H
#define FUNCTION_DEFS_H

#include "menu.h"


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
    cout << "Displaying " << name << "'s Attributes" << endl;
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
    cout << "Displaying " << e.name << "'s Attributes" << endl;
    cout << endl;
    wait(0.5);
    cout << "====================" << endl;
    cout << e.name << ", Level " << e.level << endl;
    cout << "====================" << endl;
    cout << "HP:  " << e.currentHealth << " / " << e.maxHealth << endl;
    cout << "ATK: " << e.attack << "\tDEF: " << e.defense << "\tSPD: " << e.speed << endl;
} // End print Enemy class

void print(Player p, Enemy e) {
    cout << "========================================" << endl;
    cout << p.name << "\t\t\t" << e.name << endl;
    cout << "Level " << p.level << "\t\t\tLevel " << e.level << endl;
    cout << "HP: " << p.get_current_health() << " / " << p.get_max_health();
    cout << "\t\t\tHP: " << e.get_current_health() << " / " << e.get_max_health() << endl;
}

void print(string s) { // print Overload -  Display string to user.
    cout << "\n" << s << endl;
}// End print string




bool check_for_boundary(Player & p) { // Checks player position to determine if at edge of map.
    if (p.get_x_position() == 50 || p.get_x_position() == 0 || p.get_y_position() == 0 || p.get_x_position() == 50) {
        return true;
    }
    else { return false; }
} // End of check_for_boundary.


void move(Player & p) {
    switch (p.get_direction()) {
    case STAY:
        in_game_menu(p);
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

bool travel(Player & p) {
    wait(0.5);
    bool at_boundary = check_for_boundary(p);
    if (at_boundary == true) {
        cout << p.name << " currently at a boundary." << endl;
        p.set_direction();
    }
    else {
        cout << p.name << " is not on the move." << endl;
        move(p);
        if (p.get_direction() == 0) {
            cout << p.name << " is idle." << endl;
            p.set_direction();
        }
    }
    print(p);
    p.print_position();
    bool fightFlag = roll_battle(p);
    return fightFlag;
}

bool check_game_over(Player p) {
    if (p.get_current_health() <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void dot_dot_dot() {
    wait(0.25);
    cout << ".";
    wait(0.25);
    cout << ".";
    wait(0.25);
    cout << "." << endl;
}


void splash() {
    cout << "  / $$$$$$   /$$$$$$$   / $$$$$$"  << endl;
    cout <<" / $$__  $$ | $$__  $$ / $$___ $$"  << endl;
    cout <<" | $$   __/ | $$    $$ | $$    __/" << endl;
    cout <<" | $$$$$$   | $$$$$$$/ | $$"        << endl;
    cout <<"   ____  $$ | $$____/  | $$"        << endl;
    cout <<"  / $$    $$| $$       | $$    $$"  << endl;
    cout <<"  | $$$$$$/ | $$       | $$$$$$ /"  << endl;
    cout <<"    ______/ |__ /        ______/"   << endl;
    cout << endl;
    cout << endl;
            cout << " /$$$$$$   / $$$$$$$   / $$ / $$ / $$$$$$$$ / $$ / $$/ $$$$$$$$/ $$ / $$ / $$$$$$$  / $$$$$$$$" << endl;
            cout << "/ $$__  $$ | $$__  $$  | $$ | $$ | $$_____/| $$$ | $$|__  $$ _/| $$ | $$ | $$___ $$ | $$_____/" << endl;
            cout << "| $$    $$ | $$     $$ | $$ | $$ | $$      | $$$$| $$   | $$   | $$ | $$ | $$    $$ | $$" << endl;
            cout << "| $$$$$$$$ | $$   | $$ | $$ / $$/| $$$$$   | $$ $$ $$   | $$   | $$ | $$ | $$$$$$$/ | $$$$$" << endl;
            cout << "| $$__  $$ | $$   | $$    $$ $$/ | $$__/   | $$  $$$$   | $$   | $$ | $$ | $$__  $$ | $$__/" << endl;
            cout << "| $$ | $$  | $$  | $$      $$$/  | $$ | $$   $$$ | $$   | $$   | $$ | $$ | $$  | $$ | $$" << endl;
            cout << "| $$ | $$  | $$$$$$$ /      $/   | $$$$$$$$| $$    $$   | $$   | $$$$$$/ | $$  | $$ | $$$$$$$$" << endl;
            cout << "| __/  |__/|_______ /      _/    |________/|__ /  __/   |__ /    ______/ |__/  |__/ |________/" << endl;
}

void game_over() {
    system("cls");
    wait(2.0);
    cout << endl << endl;
    cout << "  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$        /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$"  << endl;
    cout << " /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/       /$$__  $$| $$   | $$| $$_____/| $$__  $$" << endl;
    cout << "| $$   __/| $$    $$| $$$$  /$$$$| $$            | $$    $$| $$   | $$| $$      | $$    $$" << endl;
    cout << "| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         | $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/" << endl;
    cout << "| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         | $$  | $$    $$ $$/ | $$__/   | $$__  $$" << endl;
    cout << "| $$    $$| $$  | $$| $$   $ | $$| $$            | $$  | $$     $$$/  | $$      | $$    $$" << endl;
    cout << "|  $$$$$$/| $$  | $$| $$  /  | $$| $$$$$$$$      |  $$$$$$/      $/   | $$$$$$$$| $$  | $$" << endl;
    cout << "  ______/ |__/  |__/|__/     |__/|________/        ______/      _/    |________/|__/  |__/" << endl;
}

#endif
