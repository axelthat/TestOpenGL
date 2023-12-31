#pragma once

#include <string>
#include <unordered_map>
#include <optional>
#include <memory>
#include <glm/glm.hpp>

#include "IObject.h"

class Game;

class Environment : public IObject {
private:
	const glm::vec4 m_Uv;

public:
	static inline const float OBJECT_SIZE = 50.0f;
	static inline const glm::vec2 INSET_PADDING = glm::vec2(5.0f, 0.0f);

public:
	Environment(Game& game, const glm::vec4 uv, glm::vec2 initialPosition, bool solid);

public:
	void onUpdate(float ts) override;
	void onRender() override;
	void onCollision(IObject* gameObject, glm::vec4 direction) override;
};