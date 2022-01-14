#include "Image.h"

#include <stdio.h>

Image::Image(float x, float y, const char* filePath)
{
	m_x = x;
	m_y = y;
	m_rotation = 0;
	m_scale = 1;

	bitmap = al_load_bitmap(filePath);
	if (!bitmap)
	{
		printf("Couldnt Load image\n");
	}
}

float Image::GetXPos() const
{
	return m_x;
}

float Image::GetYPos() const
{
	return m_y;
}

float Image::GetRotation() const
{
	return m_rotation;
}

void Image::SetPos(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Image::SetRotation(float value)
{
	m_rotation = value;
}

void Image::UpdatePosition(float dx, float dy)
{
	m_x += dx;
	m_y += dy;
}

void Image::UpdateRotation(float increment)
{
	m_rotation += increment;
}

void Image::Draw()
{
	al_draw_bitmap(bitmap, m_x, m_y, 0);
}

Image::~Image()
{
	al_destroy_bitmap(bitmap);
}
