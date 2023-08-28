#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	glm::vec2 m_Position;
	glm::mat4 m_View;
	glm::mat4 m_Projection;

public:
	Camera(float left, float right, float bottom, float top);

public:
	inline const glm::vec2& GetPosition() { return m_Position; }
	inline const glm::mat4& GetView() { return m_View; }
	inline const glm::mat4& GetProjection() { return m_Projection; }

	inline void SetPosition(glm::vec2 position) {
		m_Position = position;
		m_View = glm::translate(glm::mat4(1.0f), { position.x, position.y, 0.0f });
	}
};