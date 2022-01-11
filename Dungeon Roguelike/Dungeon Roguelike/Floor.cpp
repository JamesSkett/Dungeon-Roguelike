#include "Floor.h"

Floor::Floor(float x, float y, bool walkable, const char* filePath) :
	Tile(x, y, walkable, filePath)
{

}

Floor::~Floor()
{
}
