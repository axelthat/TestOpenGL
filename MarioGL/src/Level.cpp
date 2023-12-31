#include <iostream>

#include "Level.h"
#include "Game.h"
#include "Util.h"
#include "Environment.h"
#include "TileMap.h"
#include "Renderer2D.h"
#include "MysteryBlock.h"

Level::Level(Game& game): IObject(false), game(game) {
	std::string level;

	try {
		level = Util::ReadFileContents("Levels/World1Level1.csv");
	} catch (std::exception e) {
		std::cout << "Level Load Failed: " << e.what() << std::endl;
		return;
	}

	auto rows = Util::Split(level, '\n');
	for (size_t i = 0; i < rows.size(); ++i) {
		auto cells = Util::Split(rows[i], ',');

		for (size_t j = 0; j < cells.size(); ++j) {
			float x = j * Environment::OBJECT_SIZE;
			float y = (rows.size() - i - 1) * Environment::OBJECT_SIZE;
			auto uv = TileMap::GetUvCoordinates(cells[j]);

			if (uv.has_value()) {
				if (cells[j] == "24") {
					gameObjects.push_back(
						std::make_unique<MysteryBlock>(game, glm::vec2(x, y))
					);
				}
				else {
					gameObjects.push_back(
						std::make_unique<Environment>(
							game,
							uv.value(),
							glm::vec2(x, y),
							TileMap::IsSolid(cells[j])
						)
					);
				}
			}
		}
	}

	game.RegisterGameObject(*this);
}

void Level::onUpdate(float ts) {
	for (auto& gameOject : gameObjects) {
		gameOject->onUpdate(ts);
	}
}

void Level::onCollision(IObject* gameObject, glm::vec4 direction) {

}

void Level::onRender() {
	Renderer2D::BeginBatch();

	for (auto& gameOject : gameObjects) {
		gameOject->onRender();
	}

	Renderer2D::EndBatch(Texture::GetTexture("Tileset"));
}