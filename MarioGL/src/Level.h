#pragma once

#include <vector>
#include <string>
#include "IObject.h"

class Game;

class Level: public IObject {
private:
	Game& game;
	std::vector<std::vector<std::string>> levelData;

public:
	Level(Game& game);

public:
	void onUpdate(float ts) override;
	void onRender() override;
};