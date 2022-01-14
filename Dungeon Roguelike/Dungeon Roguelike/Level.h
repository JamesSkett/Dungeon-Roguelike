#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

class Tile;

//The level stores the data for the level and the enemy list, and does a lot
//of the core game logic
class Level
{
public:
	Level();

	void Load(const char* fileName, std::vector<Tile*>& tiles);
	void CreateFloor(float x, float y, std::vector<Tile*>& tiles);
	void CreateWall(float x, float y, std::vector<Tile*>& tiles);

	void print();

	void movePlayer(char input, Player &player);
	void updateEnemies(Player &player);


	//Getters
	char getTile(int x, int y);

	//Setters
	void setTile(int x, int y, char tile);



private:
	void processPlayerMove(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void digHole(Player &player, int targetX, int targetY);

	//stores the level information
	std::vector <std::string> m_levelData;
	std::vector <Enemy> m_enemy;

	float m_tileOffset = 64.f;
};

