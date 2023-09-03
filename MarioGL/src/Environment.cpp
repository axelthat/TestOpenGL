#include "Environment.h"
#include "Game.h"
#include "Renderer2D.h"

Environment::Environment(Game& game, const glm::vec4 uv, glm::vec2 initialPosition, bool solid) : IObject(solid), m_Uv(uv) {
	m_Position = glm::vec2(OBJECT_SIZE / 2, OBJECT_SIZE / 2) + initialPosition;
	m_Rotation = 0.0f;
	m_Scale = glm::vec2(OBJECT_SIZE);
}

void Environment::onUpdate(float ts) {

}

void Environment::onCollision(IObject* gameObject, glm::vec4 direction) {

}

void Environment::onRender() {
	Renderer2D::DrawTexture(m_Position, m_Rotation, m_Scale, Texture::GetTexture("Tileset"), m_Uv.x, m_Uv.y, m_Uv.z, m_Uv.w);
}