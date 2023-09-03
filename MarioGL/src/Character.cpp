#include "imgui/imgui.h"

#include "Character.h"
#include "Game.h"
#include "Renderer2D.h"
#include "Input.h"

struct CollisionInfo {
	glm::vec4 direction;
	float overlapX;
	float overlapY;
};

std::vector<CollisionInfo> collisions;

Character::Character(Game& game) : IObject(true), game(game), m_CollisionDirection(0.0f) {
	m_InitialPosition = glm::vec2(OBJECT_SIZE / 2, OBJECT_SIZE / 2 + 100.0f);

	m_Position = m_InitialPosition;
	m_PrevPosition = m_InitialPosition;
	m_Rotation = 0.0f;
	m_Scale = glm::vec2(OBJECT_SIZE);

	game.RegisterGameObject(*this);
}

void Character::onUpdate(float ts) {
	ImGui::Begin("Character");
	ImGui::SliderFloat2("Translate", &m_Position.x, 0.0f, 1360.0f);
	ImGui::End();

	float speed = 300.0f;

	if (Input::GetKey(GLFW_KEY_W) && !m_CollisionDirection.w) {
		m_Position.y += speed * ts;
	}

	if (Input::GetKey(GLFW_KEY_S) && !m_CollisionDirection.z) {
		m_Position.y -= speed * ts;
	}

	if (Input::GetKey(GLFW_KEY_A) && !m_CollisionDirection.x) {
		m_Position.x -= speed * ts;
	}

	if (Input::GetKey(GLFW_KEY_D) && !m_CollisionDirection.y) {
		m_Position.x += speed * ts;
	}

	m_Collision = false;
	m_CollisionDirection = glm::vec4(0.0f);
}

void Character::onCollision(IObject* gameObject, glm::vec4 direction) {
	m_Collision = true;
	m_CollisionDirection = direction;

	glm::vec2 gameObjectPosition = gameObject->GetPosition();
	glm::vec2 gameObjectSize = gameObject->GetScale();

	if (direction.x == 1.0f) {
		m_Position.x = gameObjectPosition.x + gameObjectSize.x;
	}
	else if (direction.y == 1.0f) {
		m_Position.x = gameObjectPosition.x - m_Scale.x;
	}
	else if (direction.z == 1.0f) {
		m_Position.y = gameObjectPosition.y + gameObjectSize.y;
	}
	else if (direction.w == 1.0f) {
		m_Position.y = gameObjectPosition.y - m_Scale.y;
	}
}

void Character::onRender() {
	Renderer2D::DrawTexture(m_Position, m_Rotation, m_Scale, Texture::GetTexture("Characters"), 0.0f, 0.0f, 16.0 / 80.0f, 1.0f);
}