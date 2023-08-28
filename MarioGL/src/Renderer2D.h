#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Texture.h"

class Renderer2D {
private:
	static inline bool batching = false;

	static inline unsigned int drawCall = 0;
public:
	static inline unsigned int& GetDrawCall() { return drawCall; }
	static inline void ResetDrawCall() { drawCall = 0; }

public:
	static void onInit();
	static void onDestroy();

	static void BeginScene(Camera& camera);

	static void BeginBatch();
	static void EndBatch();

	static void DrawQuad(glm::vec2 position, float rotation, glm::vec2 scale, glm::vec4 color);
	static void DrawTexture(glm::vec2 position, float rotation, glm::vec2 scale, Texture& texture, float u1, float v1, float u2, float v2);
};