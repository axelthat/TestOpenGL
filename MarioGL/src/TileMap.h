#pragma once

#include <unordered_map>
#include <algorithm>
#include <array>
#include <string>
#include <optional>
#include <glm/glm.hpp>

class TileMap {
private:
	enum class TileType {
		GROUND,
		CADBURY,
		MYSTERY_BOX,
		MYSTERY_BOX_2,
		MYSTERY_BOX_3,
		WALL,
		DARK_GRASS_L,
		DARK_GRASS_R,
		DARK_GRASS_M,
		DARK_GRASS_BUSH,
		DARK_GRASS_BUSH_L,
		DARK_GRASS_BUSH_R,
		LIGHT_GRASS_L,
		LIGHT_GRASS_R,
		LIGHT_GRASS_M,
		PIPE_BL,
		PIPE_BR,
		PIPE_TL,
		PIPE_TR,
		CLOUD_BL,
		CLOUD_BM,
		CLOUD_BR,
		CLOUD_TL,
		CLOUD_TM,
		CLOUD_TR,
		STICK,
		STICK_CIRCLE
	};

private:
	static const std::unordered_map<std::string, TileType> Map;

public:
	static const std::optional<const glm::vec4> GetUvCoordinates(const std::string& id);
	static const bool IsSolid(const std::string& id);
};