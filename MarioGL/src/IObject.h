#pragma once

#include <glm/glm.hpp>
#include <memory>

class IObject {
protected:
	glm::vec2 m_Position;
	float m_Rotation;
	glm::vec2 m_Scale;
	bool m_Solid;

public:
	IObject(bool solid) : m_Solid(solid) {};

public:
	virtual void onUpdate(float ts) = 0;
	virtual void onRender() = 0;
	virtual void onCollision(IObject* gameObject, glm::vec4 direction) = 0;

public:
	inline glm::vec2 GetPosition() const { return m_Position; }
	inline float GetRotation() const { return m_Rotation; }
	inline glm::vec2 GetScale() const { return m_Scale; }
	inline bool IsSolid() { return m_Solid; };
};