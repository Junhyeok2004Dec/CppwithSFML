#ifndef SRC_COMPONENT_BUTTON_H_
#define SRC_COMPONENT_BUTTON_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Button
{
private:
	sf::RectangleShape shape;
	sf::Font* font;

public:
	Button();
	~Button();
	};





#endif /* SRC_COMPONENT_BUTTON_H_ */
