#pragma once

#include <stdio.h>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

class Tile;

class Renderer
{
public:
	Renderer();

	void Init();

	~Renderer();

private:
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_DISPLAY* disp;
	ALLEGRO_FONT* font;

	Tile* tile;
};

