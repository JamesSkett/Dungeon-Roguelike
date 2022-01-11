#pragma once
#include "Tile.h"

class Wall : public Tile
{
public:
	Wall(float x, float y, bool walkable, const char* filePath);

	~Wall();
private:

};

