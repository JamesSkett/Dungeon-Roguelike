#pragma once


#include <allegro5/allegro5.h>

class Tile;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

class Renderer
{
public:
	Renderer();

	~Renderer();

	static ALLEGRO_DISPLAY* disp;
	static ALLEGRO_TRANSFORM camera;


	void CameraUpdate(float* cameraPosition, float x, float y, int width, int height, float endTileX, float endTileY);

	float* GetCameraPos();

private:
	float cameraPosition[2] = { 0, 0 };

};

