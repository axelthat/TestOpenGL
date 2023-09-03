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
	inline const std::vector<std::unique_ptr<IObject>>& GetGameObjects() const { return gameObjects; }

public:
	void onUpdate(float ts) override;
	void onCollision(IObject* gameObject, glm::vec4 direction) override;
	void onRender() override;
};