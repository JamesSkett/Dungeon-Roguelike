#pragma once
#include <math.h>
#include <iostream>

namespace engine
{
	struct Vector2
	{
		float x, y;

		Vector2(float x, float y);
		Vector2 Add(const Vector2& other);
		Vector2 operator+(const Vector2& other);
		Vector2& Multiply(float scalar);
		Vector2 operator*=(float scalar);
		float Magnitude();
	};

	float DotProduct(const Vector2& v1, const Vector2& v2);
	std::ostream& operator<<(std::ostream& stream, const Vector2& other);
}