
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>
#include <ctime>
/*
 * Game.h
 *
 *  Created on: 2022. 6. 16.
 *      Author: user
 *
 *
 *      메인 클래스
 */


#ifndef SRC_PROGRAM_GAME_H_
#define SRC_PROGRAM_GAME_H_



class Game
{
private:

	//Window
	sf::RenderWindow* window;
	sf::VideoMode vidMode;
	sf::Event ev;



	//Mouse:input
	sf::Vector2i mousePos;

	//System:Game


	//점수
	int point;

	//MobTimer
	float mobTimer;
	float mobTimerMax;
	int maxMobCounts;


	//GameObject::Entity
	std::vector<sf::RectangleShape> entityList;
	sf::RectangleShape entity;

	void initVar();
	void initWindow();

	void initEntity();


public:
	Game();
	virtual ~Game();

	const bool isRunning() const;

	//함수

	void spawnEntity();
	void renderEntity();
	void updateEntity();

	void pollEvent();
	void updateMouse();

	void update();


	void render();


};




#endif /* SRC_PROGRAM_GAME_H_ */
