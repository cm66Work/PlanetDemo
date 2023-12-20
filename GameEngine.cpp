#include "GameEngine.h"

// functions
void GameEngine::InitVariables()
{
	this->window = nullptr;
	this->videoMode = new sf::VideoMode();
}

void GameEngine::InitWindow()
{
	this->videoMode->height = 600;
	this->videoMode->width = 800;
	this->window = new sf::RenderWindow(
		*videoMode,
		"Planet Demo",
		sf::Style::Titlebar | sf::Style::Close
	);

	this->window->setFramerateLimit(60);
}

void GameEngine::InitPlanets()
{
	// Create the planets.
	planets.push_back(new Planet(10.f, 10.f, 1.f, sf::Color::Cyan, sf::Vector2f(0,0)));
}


// constructor -- called when we create the object in memory.
GameEngine::GameEngine()
{
	this->InitVariables();
	this->InitWindow();
	this->InitPlanets();
}

// Destructor -- called when object is released from memory.
GameEngine::~GameEngine()
{
	delete this->window;
	delete this->videoMode;
}

// accessors
const bool GameEngine::IsRunning() const
{
	return this->window->isOpen();
}

const sf::Vector2f GameEngine::GetMousePosition()
{
	return this->mousePosView;
}

const sf::RenderWindow* GameEngine::GetRenderWindow()
{
	return this->window;
}


// functions
void GameEngine::PollEvents()
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

void GameEngine::UpdateMousePosition()
{
	/*
	* @return void
	* 
	* Updates the mouse position:
	*	* mouse position relative to the window (Vector2i)
	*/
	this->mousePosWindow = 
		sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->
		mapPixelToCoords(this->mousePosWindow);
}

void GameEngine::Update()
{
	this->PollEvents();

	// update the mouse position
	this->UpdateMousePosition();

	// update the planets
	this->UpdatePlanets();
}

void GameEngine::UpdatePlanets()
{
}

void GameEngine::Render()
{
	/* 
	* renders the game objects.
	* clear old frame
	* render objects
	* display frame in window.
	*/

	this->window->clear();

	RenderPlanets();

	// finally display the updated render to the player.
	this->window->display();
}

void GameEngine::RenderPlanets()
{
	for (Planet* p : planets)
	{
		sf::CircleShape* planetShap = new sf::CircleShape(p->radius);
		planetShap->setFillColor(p->colour);
		planetShap->setPosition((sf::Vector2f)this->window->getSize() * 0.5f);
		this->window->draw(*planetShap);
	}
}
