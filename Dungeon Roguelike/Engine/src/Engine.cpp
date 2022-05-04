#include "Engine.h"
#include <iostream>

namespace engine
{
	void engine::PrintMessage()
	{
		std::cout << "Hello World" << std::endl;
	}

	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{

	}

	Vector2 Vector2::Add(Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Vector2::operator+(Vector2& other)
	{
		return Add(other);
	}

	Vector2& Vector2::Multiply(float scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}

	Vector2 Vector2::operator*=(float scalar)
	{
		return Multiply(scalar);
	}

	float Vector2::Magnitude()
	{
		return sqrtf((x * x) + (y * y));
	}

	std::ostream& operator<<(std::ostream& stream, Vector2& other)
	{
		stream << other.x << ", " << other.y << std::endl;
		return stream;
	}

}


