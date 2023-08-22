#include <iostream>

#include "Level.h"
#include "Game.h"
#include "Util.h"

Level::Level(Game& game): game(game) {
	std::string level;

	try {
		level = Util::ReadFileContents("Levels/World1Level1.csv");
	} catch (std::exception e) {
		std::cout << "Level Load Failed: " << e.what() << std::endl;
		return;
	}

	for (auto& subData : Util::Split(level, '\n')) {
		std::cout << Util::Split(subData, ',').size() << std::endl;
		levelData.push_back(Util::Split(subData, ','));
	}

	/*for (size_t i = 0; i < levelData.size(); ++i) {
		if (i != levelData.size() - 1) {
			continue;
		}

		for (size_t j = 0; j < levelData[i].size(); j++) {
			std::cout << levelData[i][j] << std::endl;
		}
	}*/

	game.registerGameObject(*this);
}

void Level::onUpdate(float ts) {

}

void Level::onRender() {

}