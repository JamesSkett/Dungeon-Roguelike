#pragma once

class Image;

class Entity
{
private:
	Image* m_image;

public:
	Entity();
	Entity(float x, float y, const char* filePath);

	Image*& GetImage();

	~Entity();
};

