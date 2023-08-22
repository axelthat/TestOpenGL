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
	delete ground;

	character = nullptr;
	level = nullptr;
	ground = nullptr;
}

void Game::onInit() {
	LoadShaders();
	LoadTextures();

	Renderer2D::onInit();

	character = new Character(*this);
	level = new Level(*this);
	ground = new Ground(*this);
}

void Game::onUpdate(float ts) {
	for (size_t i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->onUpdate(ts);
	}
}

void Game::onRender() {
	Renderer2D::BeginScene(camera);

	for (size_t i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->onRender();
	}
}

void Game::LoadShaders() const {
	Shader::LoadShader("Flat", "Shaders/Flat.vert.glsl", "Shaders/Flat.frag.glsl");
	Shader::LoadShader("Sprite", "Shaders/Sprite.vert.glsl", "Shaders/Sprite.frag.glsl");
}

void Game::LoadTextures() const {
	Texture::LoadTexture("Tile", "Textures/tile.png", true);
}

void Game::registerGameObject(IObject& gameObject) {
	gameObjects.push_back(&gameObject);
}