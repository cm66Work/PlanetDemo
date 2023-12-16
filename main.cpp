#include <SFML/Graphics.hpp>

int main()
{
	// Create the window.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Planet Demo", sf::Style::Titlebar | sf::Style::Close);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// input from the user or other areas of the game.
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				// "X" button pressed on the window
			case sf::Event::Closed:
				window.close();
				break;
			
				// if "ESC" pressed, close the game.
			case sf::Event::KeyPressed:
				if (sf::Keyboard::Escape == event.key.code)
				{
					window.close();
					break;
				}
			}
		}

		// update the game.

		// render the new change to the game based on the updated data.
		// clear the window.
		window.clear(sf::Color::Black);

		// draw everything here.

		// end current frame.
		window.display();

	}
	return 0;
}

