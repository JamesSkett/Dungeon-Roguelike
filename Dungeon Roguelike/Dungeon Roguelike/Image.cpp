#include "Image.h"

#include <stdio.h>

Image::Image(float x, float y, const char* filePath)
	: pos({x, y}), m_rotation(0), m_scale(1), bitmap(al_load_bitmap(filePath))
{
	if (!bitmap)
	{
		printf("Couldnt Load image\n");
	}

	m_width = al_get_bitmap_width(bitmap);
	m_height = al_get_bitmap_height(bitmap);
}

engine::Vector2 Image::GetPos() const
{
	return pos;
}

float Image::GetRotation() const
{
	return m_rotation;
}

int Image::GetWidth() const
{
	return m_width;
}

int Image::GetHeight() const
{
	return m_height;
}

void Image::SetPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Image::SetRotation(float value)
{
	m_rotation = value;
}

void Image::UpdatePosition(float dx, float dy)
{
	pos.x += dx;
	pos.y += dy;
}

void Image::UpdateRotation(float increment)
{
	m_rotation += increment;
}

void Image::Draw() const
{
	al_draw_bitmap(bitmap, pos.x, pos.y, 0);
}

Image::~Image()
{
	al_destroy_bitmap(bitmap);
}
