#pragma once

#include <SFML/Graphics.hpp>

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

	// colours
	sf::Color shapeColour = sf::Color::Cyan;

	// GameObject Graphics.
	sf::CircleShape circleShape;


	GameObject();
	virtual ~GameObject();

	// gets updated every frame
	virtual void Update();
};

