#pragma once

#include "Vector2.h"

class GameObject
{
private:

public:
	Vector2 position;
	Vector2 scale;
	Vector2 rotation;

	GameObject();
	virtual ~GameObject();

	virtual void Update();
};

