#pragma once

#include <vector>

#include "IObject.h"
#include "Character.h"
#include "Level.h"
#include "Camera.h"
#include "Ground.h"

class Game {
private:
	unsigned int height;
	unsigned int width;

	std::vector<IObject*> gameObjects;
	Character* character = nullptr;
	Level* level = nullptr;
	Ground* ground = nullptr;
	Camera camera;

public:
	Game(unsigned int width, unsigned int height);
	~Game();

public:
	inline unsigned int& GetHeight() { return height; };
	inline unsigned int& GetWidth() { return width; };

public:
	void onInit();
	void onUpdate(float ts);
	void onRender();

	void registerGameObject(IObject& gameObject);

private:
	void LoadShaders() const;
	void LoadTextures() const;
};