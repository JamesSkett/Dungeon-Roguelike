#pragma once
#include "Player.h"
#include "Level.h"
#include "MainMenu.h"
#include <string>

#include <allegro5/allegro5.h>

class Tile;
class Renderer;

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

	ALLEGRO_TIMER* m_timer;
	ALLEGRO_EVENT_QUEUE* m_queue;

	Renderer* renderer;
	Tile* tile;
};

