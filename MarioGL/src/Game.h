#pragma once

#include <vector>

#include "IObject.h"
#include "Character.h"
#include "Level.h"
#include "Camera.h"

class Game {
private:
	unsigned int height;
	unsigned int width;
	unsigned int frames;
	float deltaTimePerSecond = 0.0f;
	unsigned int fps = 0;

	std::vector<IObject*> gameObjects;
	Character* character = nullptr;
	Level* level = nullptr;
	Camera camera;

public:
	Game(unsigned int width, unsigned int height);
	~Game();

public:
	inline unsigned int& GetHeight() { return height; };
	inline unsigned int& GetWidth() { return width; };

public:
	void OnInit();
	void OnUpdate(float ts);
	void OnRender();

	void RegisterGameObject(IObject& gameObject);

	void CheckCollisions();

private:
	void LoadShaders() const;
	void LoadTextures() const;
};