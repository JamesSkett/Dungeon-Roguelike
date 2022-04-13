#pragma once
#include <string>
#include <vector>

#include <allegro5/allegro5.h>

class Tile;
class Renderer;
class Player;
class Level;
class MainMenu;

class GameSystem
{
public:
	//constructor
	GameSystem(const char* levelFileName);
	~GameSystem();

	//main game functions
	void playGame();
	void playerMove();
	void deathScreen();

private:
	Player* m_player;
	Level* m_level;
	//MainMenu m_mainMenu;

	ALLEGRO_TIMER* m_timer;
	ALLEGRO_EVENT_QUEUE* m_queue;

	Renderer* renderer;
	std::vector<Tile*> m_vTiles;
};

