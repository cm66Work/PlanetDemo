#include "Planet.h"

Planet::Planet(float r, float m, float g, sf::Color c, sf::Vector2f initalVelocity)
{
	radius = r;
	mass = m;
	gravity = g;
	colour = c;

	this->initalVelocity = initalVelocity;
}


Planet::~Planet()
{
}

void Planet::UpdateVelocity(Planet* allPlanets[], float timeStep)
{
}
