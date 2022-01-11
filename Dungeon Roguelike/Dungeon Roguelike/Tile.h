#pragma once

#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

class Tile
{
public:
	Tile(float x, float y, bool walkable, const char* filePath);
	Tile() = default;
	void Draw();

	void GetPosition(float& x, float& y) const;

	~Tile();

private:
	float m_x, m_y;
	bool m_walkable;

	const char* m_filePath;

	ALLEGRO_BITMAP* image;

};

