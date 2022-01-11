#include "Wall.h"

Wall::Wall(float x, float y, bool walkable, const char* filePath) :
	Tile(x, y, walkable, filePath)
{

}

Wall::~Wall()
{
}
