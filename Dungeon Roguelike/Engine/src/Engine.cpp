#include "Engine.h"

namespace engine
{

	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{

	}

	Vector2 Vector2::Add(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Vector2::operator+(const Vector2& other)
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

	float DotProduct(const Vector2& v1, const Vector2& v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2& other)
	{
		stream << other.x << ", " << other.y << std::endl;
		return stream;
	}

}


