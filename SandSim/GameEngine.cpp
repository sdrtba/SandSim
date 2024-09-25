#include "GameEngine.h"

GameEngine::GameEngine() {
	isLeftMPressed = false;
}

void GameEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) window->close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isLeftMPressed = true;
		}
		else {
			isLeftMPressed = false;
		}
	}

	if (isLeftMPressed) {
		game.setCell(sf::Mouse::getPosition(*window));
	}
}

void GameEngine::update() {
	game.update();
}

void GameEngine::draw() {
	window->clear(sf::Color::Black);
	game.draw();
	window->display();
}

void GameEngine::run() {
	while (window->isOpen()) {
		input();
		update();
		draw();
	}
}