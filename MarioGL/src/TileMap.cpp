#include "TileMap.h"

const std::unordered_map<std::string, TileMap::TileType> TileMap::Map = {
	{"0", TileType::GROUND },
	{"33", TileType::CADBURY},
	{"24", TileType::MYSTERY_BOX},
	{"25", TileType::MYSTERY_BOX_2},
	{"26", TileType::MYSTERY_BOX_3},
	{"1", TileType::WALL},
	{ "272", TileType::DARK_GRASS_L },
	{ "273", TileType::DARK_GRASS_M },
	{ "274", TileType::DARK_GRASS_R },
	{ "305", TileType::DARK_GRASS_BUSH_R },
	{ "306", TileType::DARK_GRASS_BUSH },
	{ "307", TileType::DARK_GRASS_BUSH_L },
	{ "308", TileType::LIGHT_GRASS_L },
	{ "309", TileType::LIGHT_GRASS_M },
	{ "310", TileType::LIGHT_GRASS_R },
	{ "374", TileType::LIGHT_GRASS_L },
	{ "375", TileType::LIGHT_GRASS_M },
	{ "376", TileType::LIGHT_GRASS_R },
	{ "363", TileType::PIPE_BL },
	{ "364", TileType::PIPE_BR },
	{ "330", TileType::PIPE_TL },
	{ "331", TileType::PIPE_TR },
	{ "297", TileType::PIPE_BL },
	{ "298", TileType::PIPE_BR },
	{ "264", TileType::PIPE_TL },
	{ "265", TileType::PIPE_TR },
	{ "693", TileType::CLOUD_BL },
	{ "694", TileType::CLOUD_BM },
	{ "695", TileType::CLOUD_BR },
	{ "660", TileType::CLOUD_TL },
	{ "661", TileType::CLOUD_TM },
	{ "662", TileType::CLOUD_TR },
	{ "313", TileType::STICK },
	{ "280", TileType::STICK_CIRCLE },
};

const std::optional<const glm::vec4> TileMap::GetUvCoordinates(const std::string& id) {
	auto iter = Map.find(id);
	if (iter == Map.end()) {
		return std::nullopt;
	}

	std::optional<glm::vec4> uv = std::nullopt;

	switch (iter->second) {
	case TileType::GROUND:
		uv = glm::vec4(0.0f, 27.0f / 28.0f, 1.0f / 33.0f, 1.0f);
		break;
	case TileType::CADBURY:
		uv = glm::vec4(0.0f, 26.0f / 28.0f, 1.0f / 33.0f, 27.0f / 28.0f);
		break;
	case TileType::MYSTERY_BOX:
		uv = glm::vec4(24.0f / 33.0f, 27.0f / 28.0f, 25.0f / 33.0f, 1.0f);
		break;
	case TileType::MYSTERY_BOX_2:
		uv = glm::vec4(25.0f / 33.0f, 27.0f / 28.0f, 26.0f / 33.0f, 1.0f);
		break;
	case TileType::MYSTERY_BOX_3:
		uv = glm::vec4(26.0f / 33.0f, 27.0f / 28.0f, 27.0f / 33.0f, 1.0f);
		break;
	case TileType::WALL:
		uv = glm::vec4(1.0f / 33.0f, 27.0f / 28.0f, 2.0f / 33.0f, 1.0f);
		break;
	case TileType::DARK_GRASS_L:
		uv = glm::vec4(8.0f / 33.0f, 19.0f / 28.0f, 9.0f / 33.0f, 20.0f / 28.0f);
		break;
	case TileType::DARK_GRASS_M:
		uv = glm::vec4(9.0f / 33.0f, 19.0f / 28.0f, 10.0f / 33.0f, 20.0f / 28.0f);
		break;
	case TileType::DARK_GRASS_R:
		uv = glm::vec4(10.0f / 33.0f, 19.0f / 28.0f, 11.0f / 33.0f, 20.0f / 28.0f);
		break;
	case TileType::DARK_GRASS_BUSH:
		uv = glm::vec4(9.0f / 33.0f, 18.0f / 28.0f, 10.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::DARK_GRASS_BUSH_L:
		uv = glm::vec4(10.0f / 33.0f, 18.0f / 28.0f, 11.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::DARK_GRASS_BUSH_R:
		uv = glm::vec4(8.0f / 33.0f, 18.0f / 28.0f, 9.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::LIGHT_GRASS_L:
		uv = glm::vec4(11.0f / 33.0f, 18.0f / 28.0f, 12.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::LIGHT_GRASS_M:
		uv = glm::vec4(12.0f / 33.0f, 18.0f / 28.0f, 13.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::LIGHT_GRASS_R:
		uv = glm::vec4(13.0f / 33.0f, 18.0f / 28.0f, 14.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::PIPE_BL:
		uv = glm::vec4(0.0f, 18.0f / 28.0f, 1.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::PIPE_BR:
		uv = glm::vec4(1.0f / 33.0f, 18.0f / 28.0f, 2.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::PIPE_TL:
		uv = glm::vec4(0.0f, 19.0f / 28.0f, 1.0f / 33.0f, 20.0f / 28.0f);
		break;
	case TileType::PIPE_TR:
		uv = glm::vec4(1.0f / 33.0f, 19.0f / 28.0f, 2.0f / 33.0f, 20.0f / 28.0f);
		break;
	case TileType::CLOUD_BL:
		uv = glm::vec4(0.0f, 6.0f / 28.0f, 1.0f / 33.0f, 7.0f / 28.0f);
		break;
	case TileType::CLOUD_BM:
		uv = glm::vec4(1.0f / 33.0f, 6.0f / 28.0f, 2.0f / 33.0f, 7.0f / 28.0f);
		break;
	case TileType::CLOUD_BR:
		uv = glm::vec4(2.0f / 33.0f, 6.0f / 28.0f, 3.0f / 33.0f, 7.0f / 28.0f);
		break;
	case TileType::CLOUD_TL:
		uv = glm::vec4(0.0f, 7.0f / 28.0f, 1.0f / 33.0f, 8.0f / 28.0f);
		break;
	case TileType::CLOUD_TM:
		uv = glm::vec4(1.0f / 33.0f, 7.0f / 28.0f, 2.0f / 33.0f, 8.0f / 28.0f);
		break;
	case TileType::CLOUD_TR:
		uv = glm::vec4(2.0f / 33.0f, 7.0f / 28.0f, 3.0f / 33.0f, 8.0f / 28.0f);
		break;
	case TileType::STICK:
		uv = glm::vec4(16.0f / 33.0f, 18.0f / 28.0f, 17.0f / 33.0f, 19.0f / 28.0f);
		break;
	case TileType::STICK_CIRCLE:
		uv = glm::vec4(16.0f / 33.0f, 19.0f / 28.0f, 17.0f / 33.0f, 20.0f / 28.0f);
		break;
	}
	
	return uv;
}

const bool TileMap::IsSolid(const std::string& id) {
	auto iter = Map.find(id);
	if (iter == Map.end()) {
		return false;
	}

	std::array<TileType, 10> solidBlocks = {
		TileType::GROUND, TileType::CADBURY, TileType::MYSTERY_BOX, TileType::MYSTERY_BOX_2, TileType::MYSTERY_BOX_3,
		TileType::WALL, TileType::PIPE_BL, TileType::PIPE_BR, TileType::PIPE_TL, TileType::PIPE_TR
	};

	return std::find(solidBlocks.begin(), solidBlocks.end(), iter->second) != solidBlocks.end();
}