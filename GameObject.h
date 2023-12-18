#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Vector2.h"

class GameObject
{
private:

public:
	// GameObject Vectors.
	Vector2 position;
	Vector2 size;
	Vector2 scale;
	Vector2 rotation;

	// GameObject Graphics.
	sf::RectangleShape shape;


	GameObject();
	virtual ~GameObject();

	virtual void Update();
};

