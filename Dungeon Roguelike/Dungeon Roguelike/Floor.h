#pragma once
#include "Tile.h"
class Floor : public Tile
{
public:
	Floor(float x, float y, bool walkable, const char* filePath);

	~Floor();
private:

};

