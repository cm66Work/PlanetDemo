#include <iostream>


#include "GameObject.h"

GameObject::GameObject()
{
	this->position = Vector2();
	this->size = Vector2(100.f, 100.f);
	this->scale = Vector2(1.f, 1.f);
	this->rotation = Vector2();
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	return;
}
