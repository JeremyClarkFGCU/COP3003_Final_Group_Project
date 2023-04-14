// COP3003_Group_Project.cpp : Defines the entry point for the application.
//
#include "main.h"
#include <iostream>










int main()
{
	std::cout << "This is my main function" << std::endl;

	Character Character1;
	Character1.name = "Mister Man";
	Character1.level = 1;

	std::cout << "My Character's name is " << Character1.name << std::endl;
	std::cout << "My Characer's level is " << Character1.level;

	return 0;
}
