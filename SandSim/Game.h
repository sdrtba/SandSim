#pragma once
#include "AssetManager.h"
#include "GameSound.h"
#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <math.h>

class Game {
private:
	sf::RenderWindow& window;
public:
	explicit Game(sf::RenderWindow&);
	void update(sf::Time const&);
};