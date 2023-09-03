#pragma once

#include <memory>

#include "IObject.h"

class Game;

class Character: public IObject {
private:
	Game& game;
	glm::vec2 m_InitialPosition;
	glm::vec2 m_PrevPosition;
	glm::vec4 m_CollisionDirection;
	bool m_Collision = false;

public:
	static inline const float OBJECT_SIZE = 50.0f;
	static inline const glm::vec2 INSET_PADDING = glm::vec2(6.0f, 0.0f);

public:
	Character(Game& game);

public:
	void onUpdate(float ts) override;
	void onCollision(IObject* gameObject, glm::vec4 direction) override;
	void onRender() override;
};