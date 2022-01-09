#include "GameSystem.h"
#include <conio.h>

//Constructor sets up the game
GameSystem::GameSystem(string levelFileName)
{
	_mainMenu.displayMenu();

	_player.init(3, 0, 0);

	_level->load(levelFileName, _player);
}

GameSystem::~GameSystem()
{
	if (_level != nullptr) 	
	{
		delete _level;		
		_level = nullptr;	
	}

}

//---------------------------------------------------------------------------
//main game loop
void GameSystem::playGame()
{
	bool isDone = false;

	//loop ends when isDone = true
	while (isDone != true)
	{
		//prints the level on screen
		_level->print();
		//prints the players properties on screen
		_player.printProperties();
		//asks the player for a move command
		playerMove();
		//moves the enemy randomly after player moves
		_level->updateEnemies(_player);
		//if the player loses all their live loop ends
		if (_player._lives == 0)
		{
			isDone = true;
		}

	}
	//tells the player they are dead after all lives lost.
	deathScreen();
	//returns to main function and game ends
}

//---------------------------------------------------------------------------
//gets user input
void GameSystem::playerMove()
{
	char input;
	printf("\n\nEnter a move command (W/A/S/D), press 'E' to dig hole or Press 'Q' to quit: ");
	input = _getch();

	_level->movePlayer(input, _player);
}

//-----------------------------------------------------------------------------
//tells the player they died and prints out the player properties
void GameSystem::deathScreen()
{
	system("CLS");
	printf("           YOU DIED!\n\n");

	_player.printProperties();
	_getch();
}


