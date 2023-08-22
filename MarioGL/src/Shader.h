#pragma once

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <unordered_map>

class Shader {
private:
	unsigned int m_Id;
	std::unordered_map<std::string, unsigned int> uniformCache;

public:
	static void LoadShader(const std::string name, const std::string vertexShaderPath, const std::string fragmentShaderPath);
	static Shader& GetShader(const std::string name);

private:
	void Compile(const char* vertexShader, const char* fragmentShader);
	void Validate(unsigned int id, std::string type) const;
	unsigned int GetUniformCache(std::string name);

public:
	void Bind() const;
	void UnBind() const;

	void SetInt(const char* name, int value);
	void SetInt(const char* name, int count, int* value);
	void SetFloat(const char* name, float value);
	void SetVector2(const char* name, glm::vec2 value);
	void SetVector3(const char* name, glm::vec3 value);
	void SetVector4(const char* name, glm::vec4 value);
	void SetMatrix4(const char* name, glm::mat4 value);
};