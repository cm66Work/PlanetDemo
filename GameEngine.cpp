#include "GameEngine.h"

// functions
void GameEngine::InitVariables()
{
	this->window = nullptr;

	// game logic
	this->points = 0;

	// GameObjects.
	//this->gameObjects = std::vector<GameObject>();

	// create a planet.
	//Planet* planet = new Planet();
	//this->gameObjects.push_back(planet);
	//
	//GameObject* gameObject = new GameObject();
	//this->gameObjects.push_back(gameObject);


	// create the EnemiesManager and add it to the managed
	// GameObjects.
	//EnemiesManager* enemiesManager = new EnemiesManager(
	//	10, 2.f, this
	//);
	//this->gameObjects.push_back(enemiesManager);
}

void GameEngine::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(
		this->videoMode,
		"Planet Demo",
		sf::Style::Titlebar | sf::Style::Close
	);

	this->window->setFramerateLimit(60);
}


// constructor -- called when we create the object in memory.
GameEngine::GameEngine()
{
	this->InitVariables();
	this->InitWindow();
}

// Destructor -- called when object is released from memory.
GameEngine::~GameEngine()
{
	delete this->window;
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

	// update all GameObjects
	this->UpdateGameObjects();
}

void GameEngine::UpdateGameObjects()
{
	if (gameObjects.size() <= 0)
		return;

	for (int i = 0; i < gameObjects.size(); i++)
	{
		// loop through all GameObject Update() each frame.
		gameObjects[i]->Update();
	}
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

	// finally display the updated render to the player.
	this->window->display();
}

void GameEngine::RenderGameObjects()
{
	for (auto& gameObject : this->gameObjects)
	{
		this->window->draw(gameObject->shape);
	}
}
