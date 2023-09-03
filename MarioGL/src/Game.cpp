#include "imgui/imgui.h"

#include "Game.h"
#include "Shader.h"
#include "Renderer2D.h"
#include "Constants.h"

float CalculateOverlap(float minA, float maxA, float minB, float maxB) {
	return std::max(0.0f, std::min(maxA, maxB) - std::max(minA, minB));
}

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

void Game::OnInit() {
	LoadShaders();
	LoadTextures();

	Renderer2D::onInit();

	level = new Level(*this);

	character = new Character(*this);
}

void Game::OnUpdate(float ts) {
	deltaTimePerSecond += ts;
	frames += 1;

	if (deltaTimePerSecond >= 1.0f) {
		fps = frames;
		frames = 0;
		deltaTimePerSecond -= 1.0f;
	}

	Renderer2D::ResetDrawCall();

	for (size_t i = 0; i < gameObjects.size(); ++i) {
		gameObjects[i]->onUpdate(ts);
	}

	CheckCollisions();

	auto translation = glm::vec2(camera.GetPosition().x, camera.GetPosition().y);

	ImGui::Begin("Camera");
	ImGui::SliderFloat("Translate (X)", &translation.x, 0.0f, -8660.0f);
	ImGui::SliderFloat("Translate (Y)", &translation.y, 0.0f, static_cast<float>(height));
	ImGui::End();

	auto characterPosition = character->GetPosition() + character->GetScale();

	if (characterPosition.x > width / 2.0) {
		camera.SetPosition({
			std::max(-8660.0f, static_cast<float>(width / 2.0 - characterPosition.x)),
			std::min(camera.GetPosition().y, characterPosition.y)
		});
	}
}

void Game::OnRender() {
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
	Shader::LoadShader("Single", "Shaders/Single.vert.glsl", "Shaders/Single.frag.glsl");
}

void Game::LoadTextures() const {
	Texture::LoadTexture("Tileset", "Textures/tileset.png", true);
	Texture::LoadTexture("Characters", "Textures/characters.png", true);
}

void Game::RegisterGameObject(IObject& gameObject) {
	gameObjects.push_back(&gameObject);
}

void Game::CheckCollisions() {
	auto& gameObjects = level->GetGameObjects();

	for (auto& gameObject : gameObjects) {
		if (!gameObject->IsSolid()) {
			continue;
		}

		auto gameObjectPosition = gameObject->GetPosition();
		auto gameObjectSize = gameObject->GetScale();
		auto characterPosition = character->GetPosition() + character->INSET_PADDING;
		auto characterSize = character->GetScale() - (character->INSET_PADDING * 2.0f);

		bool isXCollision = (characterPosition.x + characterSize.x) >= gameObjectPosition.x &&
			(gameObjectPosition.x + gameObjectSize.x) >= characterPosition.x;
		bool isYCollision = (characterPosition.y + characterSize.y) >= gameObjectPosition.y &&
			(gameObjectPosition.y + gameObjectSize.y) >= characterPosition.y;

		glm::vec2 characterCenter = characterPosition + characterSize * 0.5f;
		glm::vec2 gameObjectCenter = gameObjectPosition + gameObjectSize * 0.5f;

		glm::vec2 distance = characterCenter - gameObjectCenter;

		if (isXCollision && isYCollision) {
			auto absDistance = glm::abs(distance);
			auto collisionDirection = glm::vec4(0.0f);

			if (absDistance.x > absDistance.y) {
				if (distance.x > 0) {
					collisionDirection.x = 1.0f;
					//std::cout << "LEFT" << std::endl;
				}
				else {
					collisionDirection.y = 1.0f;
					//std::cout << "RIGHT" << std::endl;
				}
			}
			else {
				if (distance.y > 0) {
					collisionDirection.z = 1.0f;
					//std::cout << "TOP" << std::endl;
				}
				else {
					collisionDirection.w = 1.0f;
					//std::cout << "BOTTOM" << std::endl;
				}
			}
			character->onCollision(gameObject.get(), collisionDirection);
		}
	}
}