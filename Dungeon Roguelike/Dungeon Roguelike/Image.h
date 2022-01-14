#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class Image
{
public:
	Image(float x, float y, const char* filePath);

	//Getters
	float GetXPos() const;
	float GetYPos() const;
	float GetRotation() const;

	//Setters
	void SetPos(float x, float y);
	void SetRotation(float value);

	void UpdatePosition(float dx, float dy);
	void UpdateRotation(float increment);

	void Draw();

	~Image();

private:
	float m_x, m_y, m_rotation, m_scale;

	ALLEGRO_BITMAP* bitmap;
};

