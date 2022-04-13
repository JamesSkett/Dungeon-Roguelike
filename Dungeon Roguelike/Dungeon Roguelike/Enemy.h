#pragma once
#include "Player.h"
class Enemy
{
public:
	//constructor
	Enemy(char tile);

	char getTile() { return _tile; }

	//gets AI move command
	char getMove(int playerX, int playerY);

private:
	char _tile;

	
};

