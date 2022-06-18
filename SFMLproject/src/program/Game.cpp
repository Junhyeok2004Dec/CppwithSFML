#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdio>

const bool Game::isRunning() const {
	return this->window->isOpen();
}

Game::Game() {

	this->initVar();
	this->initWindow();
	this->initEntity();
}

Game::~Game() {
	delete this->window;

}

void Game::initVar() {
	this->window = nullptr;

	//System:game

	//점수
	int point;

	//MobTimer
	float mobTimer;
	float mobTimerMax;
	int maxMobCounts;

	//init
	this->point = 0;
	this->mobTimerMax = 0.0f;
	this->mobTimer = this->mobTimerMax;
	this->maxMobCounts = 30;

}

void Game::initWindow() {
	this->vidMode.height = 720;
	this->vidMode.width = 1280;

	this->window = new sf::RenderWindow(this->vidMode, "I have an pizza!",
			sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);

	this->window->setFramerateLimit(250);

}

void Game::pollEvent() {

	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {

		case sf::Event::Closed:
			this->window->close();
			break;

		}
	}

}
void Game::update() {
	this->pollEvent();

	this->updateMouse();

	std::cout << "P(" << sf::Mouse::getPosition(*this->window).x << ","
			<< sf::Mouse::getPosition(*this->window).y << ")\n";

}

// Entity

void Game::updateEntity() {

	if (this->entityList.size() < this->maxMobCounts) {

		//timer
		if (this->mobTimer >= this->mobTimerMax) {
			this->mobTimer = 0.0f;
		} else
			this->mobTimer += 1.0f;
	}

	//move Entity
	for (auto &e : this->entityList) {
		e.move(1.0f, 0.f);
	}
}
void Game::renderEntity() {
	for (auto &e : this->entityList) {
		this->window->draw(e);
	}

}
void Game::render() {

	this->window->clear(sf::Color(20, 20, 202, 255));
	this->window->draw(this->entity);

	this->renderEntity();

	this->updateEntity();

	this->window->display();
}
//input
void Game::updateMouse() {
	//vector2i형, void

	this->mousePos = sf::Mouse::getPosition(*this->window);

}

// 게임 오브젝트

void Game::initEntity() {

	this->entity.setPosition(sf::Vector2f(0.0f, 0.0f));

	this->entity.setSize(sf::Vector2f(150.0f, 150.0f));
	this->entity.setFillColor(sf::Color::Yellow);
	this->entity.setOutlineColor(sf::Color::Cyan);
	this->entity.setOutlineThickness(2.0f);

}

void Game::spawnEntity() {

	/*
	 * 임의의 값(색깔,종류,사이즈) 등으로 일단 구성할 예정
	 * EntityList와 관련된 코드
	 */

	this->entity.setPosition(
			static_cast<float>(rand()
					% static_cast<int>(this->window->getSize().x
							- this->entity.getSize().x)), 0.0f

			);

	this->entity.setFillColor(sf::Color::Red);
	this->entityList.push_back(this->entity);

}
