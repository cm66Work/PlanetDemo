#pragma once
class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float _x, float _y);
	Vector2(const Vector2& other);

	// overloads
	// return a reference to the other
	Vector2& operator=(const Vector2& other); // pos = val;
	Vector2& operator+=(const Vector2& other); // pos += val;
	// returns a brand new Vector2
	Vector2 operator+(const Vector2& other); // pos + val;
	Vector2 operator-(const Vector2& other); // pos - val;
	Vector2 operator*(const Vector2& other); // pos * val;

	bool operator==(const Vector2& other); // pos == val;
	bool operator!=(const Vector2& other); // pos != val;

	virtual ~Vector2();
};

