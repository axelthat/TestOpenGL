#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Texture.h"

class Renderer2D {
public:
	static void onInit();
	static void onDestroy();

	static void BeginScene(Camera& camera);

	static void DrawQuad(glm::vec2 position, float rotation, glm::vec2 scale, glm::vec4 color);
	static void DrawTexture(glm::vec2 position, float rotation, glm::vec2 scale, Texture& texture, float u1, float v1, float u2, float v2);
};