#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Engine.h"

class Image
{
public:
	Image(float x, float y, const char* filePath);

	//Getters
	engine::Vector2 GetPos() const;
	float GetRotation() const;
	int GetWidth() const;
	int GetHeight() const;

	//Setters
	void SetPos(float x, float y);
	void SetRotation(float value);

	void UpdatePosition(float dx, float dy);
	void UpdateRotation(float increment);

	void Draw() const;

	~Image();

private:
	float m_rotation, m_scale;
	engine::Vector2 pos = { 0, 0 };
	ALLEGRO_BITMAP* bitmap;
	int m_width, m_height;

};

