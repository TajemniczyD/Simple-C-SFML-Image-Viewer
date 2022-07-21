#include "SFML/Graphics.hpp"

sf::Texture textures[4];
sf::Sprite sprite;

int main()
{
	// -----------------------------------------640, 480
	sf::RenderWindow renderWindow(sf::VideoMode(448, 448), "Hello World!", sf::Style::Titlebar | sf::Style::Close);
	renderWindow.setFramerateLimit(120);

	int count = 0;

	textures[0].loadFromFile("Beach.png");
	textures[1].loadFromFile("Island.png");
	textures[2].loadFromFile("Mountains.png");
	textures[3].loadFromFile("Desert.png");

	sprite.setTexture(textures[count]);
	sprite.setPosition(0, 0);
	sprite.setScale(7, 7);

	sf::Event event;
	while (renderWindow.isOpen())
	{
		sprite.setTexture(textures[count]);
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				renderWindow.close();
			}

			if (event.type == sf::Event::EventType::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					count--;
					if (count < 0)
						count = 3;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					count++;
					if (count > 3)
						count = 0;
				}
			}
		}

		renderWindow.clear(sf::Color::White);
		renderWindow.draw(sprite);
		renderWindow.display();
	}
}
