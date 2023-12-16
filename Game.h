#pragma once

#include <SFML/Graphics.hpp>

/// <summary>
/// Class that acts as the game engine
/// </summary>
class Game
{
private:
	// Variables
	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;

	void InitVariables();
	void InitWindow();

public:
	Game(); // creator
	virtual ~Game(); // destructor

	// accessors
	const bool IsRunning() const;

	// functions
	void PollEvents();
	void Update();
	void Render();
};

