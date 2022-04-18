#pragma once

#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

class Image;

class Tile
{
public:
	Tile(float x, float y, bool walkable, const char* filePath);
	Tile() = default;
	void Draw() const;

	Image* GetImage() const;
	bool IsWalkable() const;

	~Tile();

private:
	bool m_walkable;

	Image* image;

};

