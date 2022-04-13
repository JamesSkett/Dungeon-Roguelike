#include "Tile.h"
#include "Image.h"

Tile::Tile(float x, float y, bool walkable, const char* filePath)
{
	m_walkable = walkable;

	image = new Image(x, y, filePath);
}

void Tile::Draw()
{
	image->Draw();
}

Image* Tile::GetImage()
{
	return image;
}

bool Tile::IsWalkable() const
{
	return m_walkable;
}

Tile::~Tile()
{
	delete image;
}
