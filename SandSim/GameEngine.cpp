#include "GameEngine.h"

GameEngine::GameEngine() {
	background.setTexture(&AssetManager::GetTexture("image/back.png"));
	//if (!icon.loadFromFile("image/icon.png")) window->close();
	//window->setIcon(256, 256, icon.getPixelsPtr());
	//text.setFont(AssetManager::GetFont("fonts/font.ttf"));
	text.setFillColor(sf::Color::Green);
}

void GameEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (pause.checkClick(sf::Mouse::getPosition(*window))) mypause = !mypause;
				if (sound.checkClick(sf::Mouse::getPosition(*window))) mus = !mus;
				if (restart.checkClick(sf::Mouse::getPosition(*window))) {}
				if (exit.checkClick(sf::Mouse::getPosition(*window))) myexit = true;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				restart.checkClick();
				exit.checkClick();
			}
		}
	}
}

void GameEngine::update(sf::Time const& deltaTime) {
	if (!mypause) game.update(deltaTime);

	if (myexit) {
		tm += deltaTime;
		if (tm > sf::seconds(1))
		{
			if (myexit) window->close();
		}
	}
}

void GameEngine::draw() {
	window->clear(sf::Color::Black);
	//game.draw();
	window->draw(background);
	window->draw(*pause.getSprite());
	window->draw(*restart.getSprite());
	window->draw(*sound.getSprite());
	window->draw(*exit.getSprite());
	text.setPosition(15, 515);
	text.setString(" < score > ");
	window->draw(text);
	window->display();
}

void GameEngine::run() {
	sf::Clock clock;

	while (window->isOpen()) {
		sf::Time dt = clock.restart();
		input();
		update(dt);
		draw();
	}
}