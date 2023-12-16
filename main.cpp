#include <SFML/Graphics.hpp>


int main()
{
	// Create the window.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Planet Demo");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that where triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window.
			if (sf::Event::Closed == event.type)
				window.close();
		}

		// clear the window with black colour
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}

	return 0;
}
