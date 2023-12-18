#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::~Vector2()
{
}

Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

// copy constructor.
Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}

// set constructor.
Vector2& Vector2::operator=(const Vector2& other)
{
	// set x and y to other x and y.
	x = other.x;
	y = other.y;

	// return ourselves.
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

/// <summary>
/// Returns a new Vector2 that is the answer to 
/// the current Vector2 + other. 
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Vector2 Vector2::operator+(const Vector2& other) 
{
	// do not modify the current instance,
	// return a new Vector2 that is the answer.
	Vector2 returnValue(other);
	// add x and y to returnValue x and y.
	returnValue.x += x;
	returnValue.y += y;

	// return new Vector2
	return returnValue;
}


/// <summary>
/// Returns a new Vector2 that is the answer to 
/// the current Vector2 - other. 
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Vector2 Vector2::operator-(const Vector2& other) 
{
	// do not modify the current instance,
	// return a new Vector2 that is the answer.
	Vector2 returnValue(other);
	// add x and y to returnValue x and y.
	returnValue.x -= x;
	returnValue.y -= y;

	// return new Vector2
	return returnValue;
}

/// <summary>
/// Returns a new Vector2 that is the answer to 
/// the current Vector2 * other. 
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
Vector2 Vector2::operator*(const Vector2& other) 
{
	// do not modify the current instance,
	// return a new Vector2 that is the answer.
	Vector2 returnValue(other);
	// add x and y to returnValue x and y.
	returnValue.x *= x;
	returnValue.y *= y;

	// return new Vector2
	return returnValue;
}

/// <summary>
/// Returns true if current vector is equal to other vector.
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool Vector2::operator==(const Vector2& other)
{
	return x == other.x && y == other.y;
}

/// <summary>
/// Returns true if current vector is equal to other vector.
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool Vector2::operator!=(const Vector2& other)
{
	return !operator==(other);
}




