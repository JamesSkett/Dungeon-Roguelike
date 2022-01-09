#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

using namespace std;

//The level stores the data for the level and the enemy list, and does a lot
//of the core game logic
class Level
{
public:
	Level();

	void load(string fileName, Player &player);
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

private:
	//stores the level information
	vector <string> _levelData;
	vector <Enemy> _enemy;
};

