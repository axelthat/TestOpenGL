#include "Ground.h"
#include "Game.h"
#include "Renderer2D.h"

Ground::Ground(Game& game): game(game) {
	game.registerGameObject(*this);
}

void Ground::onUpdate(float ts) {
}

void Ground::onRender() {
	Renderer2D::DrawTexture(
		glm::vec2(game.GetWidth() / 2, game.GetHeight() / 2)
	, 0.0f, glm::vec2(200.0f), Texture::GetTexture("Tile"), 0.0f, 0.0f, 1.0f, 1.0f);
}