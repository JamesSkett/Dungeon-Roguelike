#include "Tile.h"

Tile::Tile(float x, float y, bool walkable, const char* filePath)
{
	m_x = x;
	m_y = y;
	m_walkable = walkable;
	m_filePath = filePath;

	image = al_load_bitmap(m_filePath);
	if (!image)
	{
		printf("Couldnt Load image\n");
	}
}

void Tile::Draw()
{
	al_draw_bitmap(image, m_x, m_y, 0);
}

void Tile::GetPosition(float& x, float& y) const
{
	x = m_x;
	y = m_y;
}

Tile::~Tile()
{
	al_destroy_bitmap(image);
}
