#pragma once

#include <iostream>
#include <vector>
#include <ctime>
 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "GameObject.h"

/// <summary>
/// Class that acts as the game engine
/// </summary>
class GameEngine
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	// mouse position relative to the game window.
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// game logic
	int points;

	// game objects
	// keep track of all GameObjects so that we can 
	// loop over their Update methods during runtime.
	std::vector<GameObject*> gameObjects;

	// private functions
	void InitVariables();
	void InitWindow();

public:
	GameEngine(); // creator
	virtual ~GameEngine(); // destructor

	// accessors
	const bool IsRunning() const;
	const sf::Vector2f GetMousePosition();
	const sf::RenderWindow* GetRenderWindow();

	// functions
	void PollEvents();
	void UpdateMousePosition();
	void Update();
	void UpdateGameObjects();
	void Render();
	void RenderGameObjects();

	
};

