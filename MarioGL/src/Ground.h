#pragma once

#include "IObject.h"

class Game;

class Ground: public IObject {
private:
	Game& game;

public:
	Ground(Game& game);

public:
	void onUpdate(float ts) override;
	void onRender() override;
};