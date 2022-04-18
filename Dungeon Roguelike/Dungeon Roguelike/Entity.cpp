#include "Entity.h"
#include "Image.h"

Entity::Entity()
{
}

Entity::Entity(float x, float y, const char* filePath)
	: m_image(new Image(x, y, filePath))
{
}


Image*& Entity::GetImage()
{
	return m_image;
}

Entity::~Entity()
{
	delete m_image;
}
