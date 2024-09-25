#include "Game.h"
#include <iostream>

//Game::Game(sf::RenderWindow& window, int width, int height, int cellSize) : window(window), width(width), height(height), cellSize(cellSize) {
//	grid = 
//}

Game::Game(sf::RenderWindow& window) : window(window) {

}

void Game::update() {
	
}

void Game::draw() {

}

void Game::setCell(sf::Vector2i mousePos) {
	int x = mousePos.x;
	int y = mousePos.y;
	if (x > 640) { x = 640; }
	else if (x < 0) { x = 0; }
	if (y > 640) { y = 640; }
	else if (y < 0) { y = 0; }

	std::cout << mousePos.x << std::endl;
}