#include "imgui/imgui.h"

#include "Character.h"
#include "Game.h"
#include "Renderer2D.h"

Character::Character(Game& game) : game(game) {
	m_Position = glm::vec2(game.GetWidth() / 2, game.GetHeight() / 2);
	m_Rotation = 0.0f;
	m_Scale = glm::vec2(game.GetHeight() / 2);

	game.registerGameObject(*this);
}

void Character::onUpdate(float ts) {
	//ImGui::Begin("Character");
	//ImGui::SliderFloat2("Scale", &m_Scale.x, 0, game.GetWidth());
	//ImGui::End();
}

void Character::onRender() {
	//Renderer2D::DrawQuad(m_Position, m_Rotation, m_Scale, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
}