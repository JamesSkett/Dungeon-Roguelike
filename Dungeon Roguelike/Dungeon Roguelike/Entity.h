#pragma once

class Image;

class Entity
{
private:
	Image* m_image;

public:
	Entity();
	Entity(float x, float y, const char* filePath);

	void Draw() const;

	Image*& GetImage();

	~Entity();
};

