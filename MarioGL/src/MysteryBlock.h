#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <optional>
#include <glm/glm.hpp>

#include "IObject.h"

class Game;

class MysteryBlock : public IObject {
private:
	glm::vec4 m_Uv;
	glm::vec4 m_Uv2;
	glm::vec4 m_Uv3;

	glm::vec4* m_CurrentUv;
	unsigned int m_CurrentUvIndex = 0;

	float elapsedTime = 0.0f;
	float delay = 0.3f;

public:
	static inline const float OBJECT_SIZE = 50.0f;

public:
	MysteryBlock(Game& game, glm::vec2 initialPosition);

public:
	void onUpdate(float ts) override;
	void onCollision(IObject* gameObject, glm::vec4 direction) override;
	void onRender() override;
};