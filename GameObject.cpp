#include <iostream>


#include "GameObject.h"

GameObject::GameObject()
{
	this->size = Vector2(100.f, 100.f);

	this->circleShape.setRadius(this->size.x);
	this->circleShape.setFillColor(this->shapeColour);
}

GameObject::~GameObject()
{
}


void GameObject::Update()
{
	return;
}
