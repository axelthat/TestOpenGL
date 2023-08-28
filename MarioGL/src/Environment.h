#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <glm/glm.hpp>

#include "IObject.h"

class Game;

class Environment : public IObject {
private:
	Game& game;
	const glm::vec4 m_Uv;

public:
	static inline const float OBJECT_SIZE = 50.0f;

public:
	Environment(Game& game, const glm::vec4 uv, glm::vec2 initialPosition);

public:
	void onUpdate(float ts) override;
	void onRender() override;
};