#include "Game.h"

// functions
void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(
		this->videoMode,
		"Planet Demo",
		sf::Style::Titlebar | sf::Style::Close
	);
}

// constructor -- called when we create the object in memory.
Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

// Destructor -- called when object is released from memory.
Game::~Game()
{
	delete this->window;
}

// accessors
const bool Game::IsRunning() const
{
	return this->window->isOpen();
}

// functions
void Game::PollEvents()
{
	while (this->window->pollEvent(this->event));
	{
		switch (this->event.type)
		{
			// "X" button was person on the game window.
		case sf::Event::Closed:
			this->window->close();
			break;
			// "ESC" was pressed, so close the window.
		case sf::Event::KeyPressed:
			if (sf::Keyboard::Escape == this->event.key.code)
				this->window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->PollEvents();
}

void Game::Render()
{
	/* 
	* renders the game objects.
	* clear old frame
	* render objects
	* display frame in window.
	*/


	this->window->clear(sf::Color(255,0,0,255));

	// TODO:: draw game objects.

	this->window->display();
}
