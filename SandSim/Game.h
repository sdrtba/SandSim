#pragma once
#include "AssetManager.h"
#include "GameSound.h"
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <math.h>

enum class CellType { Stone, Sand, Water, Fire, Wood };

class Cell {

};

class Game {
private:
	int height;
	int width;
	int cellSize;
	sf::RenderWindow& window;
	std::vector<std::vector<CellType>> grid;
	
	
public:
	explicit Game(sf::RenderWindow&);
	void update();
	void draw();

	void setCell(sf::Vector2i mousePos);
};