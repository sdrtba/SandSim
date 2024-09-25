#pragma once
#include "Button.h"
#include "Game.h"


class GameEngine {
public:
	GameEngine();
	void run();
private:
	AssetManager manager;
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 640), L"Sand", sf::Style::Close);

	Game game = Game(*window);

	bool isLeftMPressed;

	void input();
	void update();
	void draw();
};