#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Camera.h"
#include "Texture.h"

class Renderer2D {
private:
	struct VertexData {
		glm::vec2 position;
		glm::vec2 texture;

		VertexData(const glm::vec2 position, const glm::vec2 texture) : position(position), texture(texture) {};
	};

private:
	static inline bool m_Batching = false;
	static inline unsigned int m_DrawCall = 0;

	static inline std::vector<VertexData> m_VertexBatch;
	static inline std::vector<unsigned int> m_IndicesBatch;
public:
	static inline unsigned int& GetDrawCall() { return m_DrawCall; }
	static inline void ResetDrawCall() { m_DrawCall = 0; }

public:
	static void onInit();
	static void onDestroy();

	static void BeginScene(Camera& camera);

	static void BeginBatch();
	static void EndBatch(Texture& texture);

	static void DrawQuad(glm::vec2 position, float rotation, glm::vec2 scale, glm::vec4 color);
	static void DrawTexture(glm::vec2 position, float rotation, glm::vec2 scale, Texture& texture, float u1, float v1, float u2, float v2);
};