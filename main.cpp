#include <iostream>
#include "Game.h"

int main()
{
	// Init Game Engine.
	Game game;
	
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

