#pragma once

#include <vector>
#include <string>
#include <memory>
#include <optional>

#include "IObject.h"

class Game;

class Level: public IObject {
private:
	Game& game;
	std::vector<std::unique_ptr<IObject>> gameObjects;

public:
	Level(Game& game);

public:
	void onUpdate(float ts) override;
	void onRender() override;
};