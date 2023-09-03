#include "MysteryBlock.h"
#include "TileMap.h"
#include "Texture.h"
#include "Renderer2D.h"

MysteryBlock::MysteryBlock(Game& game, glm::vec2 initialPosition): IObject(true) {
	m_Position = glm::vec2(OBJECT_SIZE / 2, OBJECT_SIZE / 2) + initialPosition;
	m_Rotation = 0.0f;
	m_Scale = glm::vec2(OBJECT_SIZE);

	m_Uv = TileMap::GetUvCoordinates("24").value();
	m_Uv2 = TileMap::GetUvCoordinates("25").value();
	m_Uv3 = TileMap::GetUvCoordinates("26").value();

	m_CurrentUv = &m_Uv;
}

void MysteryBlock::onUpdate(float ts) {
	elapsedTime += ts;

	if (elapsedTime < delay) {
		return;
	}

	m_CurrentUvIndex = (m_CurrentUvIndex + 1) % 3;

	if (m_CurrentUvIndex == 0) {
		m_CurrentUv = &m_Uv;
	}
	else if (m_CurrentUvIndex == 1) {
		m_CurrentUv = &m_Uv2;
	}
	else if (m_CurrentUvIndex == 2) {
		m_CurrentUv = &m_Uv3;
	}

	if (m_CurrentUvIndex > 0) {
		delay = 0.2f;
	}
	else {
		delay = 0.3f;
	}

	elapsedTime = 0.0f;
}

void MysteryBlock::onCollision(IObject* gameObject, glm::vec4 direction) {

}

void MysteryBlock::onRender() {
	Renderer2D::DrawTexture(m_Position, m_Rotation, m_Scale, Texture::GetTexture("Tileset"), (*m_CurrentUv).x, (*m_CurrentUv).y, (*m_CurrentUv).z, (*m_CurrentUv).w);
}