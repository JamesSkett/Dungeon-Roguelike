#pragma once
#include <math.h>

namespace engine
{
	void PrintMessage();

	struct Vector2
	{
		float x, y;

		Vector2(float x, float y);
		Vector2 Add(Vector2& other);
		Vector2 operator+(Vector2& other);
		Vector2& Multiply(float scalar);
		Vector2 operator*=(float scalar);
		float Magnitude();
	};

	std::ostream& operator<<(std::ostream& stream, Vector2& other);
}