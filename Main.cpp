#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "MainMenu.h"
#include "GameSystem.h"

using namespace std;

int main()
{	
	//sets up the game and loads the level
	GameSystem gameSystem("Level_1.txt");

	//main game function
	gameSystem.playGame();

	_getch();
	return 0;
}