#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	//constructor
	Enemy(float x, float y, const char* filePath);

	char getTile() { return _tile; }

	//gets AI move command
	char getMove(int playerX, int playerY);

private:
	char _tile;

	
};

