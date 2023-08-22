#pragma once

#include "IObject.h"

class Game;

class Character: public IObject {
private:
	Game& game;

public:
	Character(Game& game);

public:
	void onUpdate(float ts) override;
	void onRender() override;
};