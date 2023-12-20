#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Planet
{
private:
	sf::Vector2f currentVelocity;
public:
	float radius;
	float mass;
	float gravity;
	
	sf::Color colour;
	
	sf::Vector2f initalVelocity;

	Planet(float r, float m, float g, sf::Color c, sf::Vector2f initalVelocity);
	virtual ~Planet();

	void UpdateVelocity(Planet* allPlanets[], float timeStep);
};

