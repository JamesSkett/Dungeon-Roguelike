#pragma once
#include "Player.h"
#include "Level.h"
#include "MainMenu.h"
#include <string>

using namespace std;

class GameSystem
{
public:
	//constructor
	GameSystem(string levelFileName);
	~GameSystem();

	//main game functions
	void playGame();
	void playerMove();
	void deathScreen();

private:
	Player _player;
	Level* _level = new Level;
	MainMenu _mainMenu;

};

