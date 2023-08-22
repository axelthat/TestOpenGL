#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
	glm::vec2 m_Position;
	glm::mat4 m_View;
	glm::mat4 m_Projection;

public:
	Camera(float left, float right, float bottom, float top);

public:
	inline const glm::vec2& GetPosition() { return m_Position; }
	inline const glm::mat4& GetView() { return m_View; }
	inline const glm::mat4& GetProjection() { return m_Projection; }
};