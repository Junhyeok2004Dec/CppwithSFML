#include <iostream>
#include "./program/Game.h"

int main() {

	std::srand(static_cast<unsigned>(time(NULL)));

	Game game;


	while(game.isRunning()) {

		//update
		game.update();
		//render
		game.render();

	}

	return 0;
}
