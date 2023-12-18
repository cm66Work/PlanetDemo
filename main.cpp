#include "GameEngine.h"

int main()
{
	// init seed for random number generator.
	std::srand(static_cast<unsigned>(time(NULL)));

	// Init Game Engine.
	GameEngine game;
	
	// run the program as long as the window is open
	while (game.IsRunning())
	{
		// update
		game.Update();

		// render
		game.Render();
	}
	return 0;
}

