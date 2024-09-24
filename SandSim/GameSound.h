#pragma once
#include <array>
#include <SFML/Audio.hpp>
#include "AssetManager.h"

class GameSound {
private:
	static const int n = 2;
	std::array<sf::Sound, n> GSound;
public:
	GameSound() {
		std::array<std::string, n> namefilebuf{ "sound/back.ogg", "sound/back1.ogg" };
		for (int i = 0; i < n; i++) {
			GSound[i].setBuffer(AssetManager::GetSoundBuffer(namefilebuf[i]));
		}
		GSound[0].setLoop(true);
	};

	void play(int index);
	void stop(int index);
	void AllStop();
};