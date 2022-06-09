#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello World",
			sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(256.0f,256.0f));
	sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));


	player.setFillColor(sf::Color::Yellow);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				printf("Å©±â : ( %i , %i )", event.size.width, event.size.height);
				break;

			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					printf("%c", event.text.unicode);
				}
				break;
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f,0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f,-0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f,0.1f);
		}
		window.clear();
		window.setView(view);
		window.draw(player);
		window.display();
	}

	return 0;
}
