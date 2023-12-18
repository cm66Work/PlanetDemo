#include "GameEngine.h"

// functions
void GameEngine::InitVariables()
{
	this->window = nullptr;

	// game logic
	this->points = 0;
	this->enemySpawnTimer = 0.f;
	this->enemySpawnTimerMax = 2.f;
	this->maxEnemies = 5;

	// GameObjects.
	//this->gameObjects = std::vector<GameObject>();

	// create a planet.
	Planet* planet = new Planet();
	this->gameObjects.push_back(planet);
	
	GameObject* gameObject = new GameObject();
	this->gameObjects.push_back(gameObject);
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

void GameEngine::InitEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Cyan);
}

// constructor -- called when we create the object in memory.
GameEngine::GameEngine()
{
	this->InitVariables();
	this->InitWindow();
	this->InitEnemies();
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

void GameEngine::SpawnEnemies()
{
	/**
		@return void

		Spawns enemies and sets their colours and positions.
			- sets a random position.
			- sets a random colour.
			- adds enemy to the vector.
	*/

	this->enemy.setPosition(
		static_cast<float>(rand() %
		static_cast<int>(
			this->window->getSize().x - this->enemy.getSize().x
			)),
		0.f
	); 

	this->enemy.setFillColor(sf::Color::Green);

	// spawn the enemy.
	this->enemies.push_back(this->enemy);
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

	// update enemies
	this->UpdateEnemies();

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

void GameEngine::UpdateEnemies()
{
	/**
		@return void

		Updates the enemy spawn timer 
		and triggers an enemy to spawn if
		we are bellow the max number of enemies
		and we have waited more then the enemySpawnTimerMax.

		Moves the enemies downwards.
		TODO:: Remove the enemy at the edge of the screen
	*/

	// Updating the time for enemy spawning.
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->SpawnEnemies();
			this->enemySpawnTimer = 0.f;
		}
		else
		{
			this->enemySpawnTimer++;
		}
	}

	// move and update the enemies. 
	bool deleteEnemy = false;
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, 5.f);

		// check if clicked upon
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (
				this->enemies[i].getGlobalBounds().contains(
					this->mousePosView
				))
			{
				deleteEnemy = true;

				// Gain points for killing the enemy.
				this->points += 10.f;
			}
		}

		// if the enemy is past the bottom of the screen,
		// delete them.
		if (this->enemies[i].getPosition().y >
			this->window->getSize().y)
		{
			deleteEnemy = true;
		}

		if (deleteEnemy)
		{
			deleteEnemy = false;
			this->enemies.erase(this->enemies.begin() + i);
		}
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

	// TODO:: draw game objects.
	this->RenderEnemies();

	// finally display the updated render to the player.
	this->window->display();
}

void GameEngine::RenderEnemies()
{
	// rendering all the enemies
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}
