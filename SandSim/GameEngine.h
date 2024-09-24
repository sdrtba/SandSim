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
	
	sf::Image icon;
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(640, 640));

	Button pause = Button(sf::Vector2f(13, 140),
		AssetManager::GetTexture("image/play.png"), AssetManager::GetTexture("image/pause.png"));
	Button restart = Button(sf::Vector2f(13, 220),
		AssetManager::GetTexture("image/restart1.png"), AssetManager::GetTexture("image/restart2.png"));
	Button sound = Button(sf::Vector2f(13, 300),
		AssetManager::GetTexture("image/nosound.png"), AssetManager::GetTexture("image/sound.png"));
	Button exit = Button(sf::Vector2f(13, 380),
		AssetManager::GetTexture("image/exit1.png"), AssetManager::GetTexture("image/exit2.png"));

	sf::Text text;

	Game game = Game(*window);

	void input();
	void update(sf::Time const& deltaTime);
	void draw();

	bool myexit = false;
	bool mypause = false;
	bool mus = false;
	sf::Time tm;
};