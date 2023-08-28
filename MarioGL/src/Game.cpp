#include "imgui/imgui.h"

#include "Game.h"
#include "Shader.h"
#include "Renderer2D.h"
#include "Constants.h"

Game::Game(unsigned int width, unsigned int height) :
	width(width), height(height), camera(0.0f, width, 0.0f, height)
{

}

Game::~Game() {
	Renderer2D::onDestroy();

	delete character;
	delete level;

	character = nullptr;
	level = nullptr;
}

void Game::onInit() {
	LoadShaders();
	LoadTextures();

	Renderer2D::onInit();

	character = new Character(*this);
	level = new Level(*this);
}

void Game::onUpdate(float ts) {
	deltaTimePerSecond += ts;
	frames += 1;

	if (deltaTimePerSecond >= 1.0f) {
		fps = frames;
		frames = 0;
		deltaTimePerSecond = 0.0f;
	}

	Renderer2D::ResetDrawCall();

	for (size_t i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->onUpdate(ts);
	}

	auto translation = glm::vec2(camera.GetPosition().x, camera.GetPosition().y);

	ImGui::Begin("Camera");
	ImGui::SliderFloat("Translate (X)", &translation.x, 0.0f, -8660.0f);
	ImGui::SliderFloat("Translate (Y)", &translation.y, 0.0f, static_cast<float>(height));
	ImGui::End();

	camera.SetPosition(translation);
}

void Game::onRender() {
	Renderer2D::BeginScene(camera);

	for (size_t i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->onRender();
	}

	ImGui::Begin("Statistics");
	ImGui::Text(("Draw Calls: " + std::to_string(Renderer2D::GetDrawCall())).c_str());
	ImGui::Text(("FPS: " + std::to_string(fps)).c_str());
	ImGui::End();
}

void Game::LoadShaders() const {
	Shader::LoadShader("Flat", "Shaders/Flat.vert.glsl", "Shaders/Flat.frag.glsl");
	Shader::LoadShader("Sprite", "Shaders/Sprite.vert.glsl", "Shaders/Sprite.frag.glsl");
}

void Game::LoadTextures() const {
	Texture::LoadTexture("Tileset", "Textures/tileset.png", true);
}

void Game::registerGameObject(IObject& gameObject) {
	gameObjects.push_back(&gameObject);
}