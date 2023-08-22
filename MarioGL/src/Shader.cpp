#include <glad/glad.h>
#include <unordered_map>
#include "Util.h"

#include "Shader.h"

static std::unordered_map<std::string, Shader> shaders;

void Shader::LoadShader(const std::string name, const std::string vertexShaderPath, const std::string fragmentShaderPath) {
	std::string vertexShader, fragmentShader;

	try {
		vertexShader = Util::ReadFileContents(vertexShaderPath);
		fragmentShader = Util::ReadFileContents(fragmentShaderPath);
	} catch (std::exception e) {
		std::cout << "Shader Load Failed: " << e.what() << std::endl;
		return;
	}

	Shader shader;
	shader.Compile(vertexShader.c_str(), fragmentShader.c_str());
	shaders[name] = std::move(shader);
}

Shader& Shader::GetShader(const std::string name) {
	return shaders[name];
}

void Shader::Compile(const char* vertexShader, const char* fragmentShader) {
	unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShader, nullptr);
	glCompileShader(vs);
	Validate(vs, "SHADER");

	unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShader, nullptr);
	glCompileShader(fs);
	Validate(fs, "FRAGMENT");

	this->m_Id = glCreateProgram();
	glAttachShader(this->m_Id, vs);
	glAttachShader(this->m_Id, fs);
	glLinkProgram(this->m_Id);
	Validate(this->m_Id, "PROGRAM");

	glDeleteShader(vs);
	glDeleteShader(fs);
}

void Shader::Validate(unsigned int id, std::string type) const {
	int result;
	
	if (type == "PROGRAM") {
		glGetProgramiv(id, GL_LINK_STATUS, &result);
		if (!result) {
			int length = 0;
			glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetProgramInfoLog(id, length, &length, message);
			std::cout << "Program Link Failed: " << message << std::endl;

			delete[] message;
			message = nullptr;
		}
	}
	else {
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (!result) {
			int length = 0;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = new char[length];
			glGetShaderInfoLog(id, length, &length, message);
			std::cout << "Shader Compilation Failed: " << message << std::endl;

			delete[] message;
			message = nullptr;
		}
	}
}

void Shader::Bind() const {
	glUseProgram(this->m_Id);
}

void Shader::UnBind() const {
	glUseProgram(0);
}

unsigned int Shader::GetUniformCache(std::string name) {
	if (uniformCache.find(name) == uniformCache.end())
		return uniformCache[name];
	unsigned int location = glGetUniformLocation(m_Id, name.c_str());
	uniformCache[name] = location;
	return location;
}

void Shader::SetInt(const char* name, int value)
{
	glUniform1i(GetUniformCache(name), value);
}

void Shader::SetInt(const char* name, int count, int* value)
{
	glUniform1iv(GetUniformCache(name), count, value);
}

void Shader::SetFloat(const char* name, float value)
{
	glUniform1f(GetUniformCache(name), value);
}

void Shader::SetVector2(const char* name, glm::vec2 value)
{
	glUniform2f(GetUniformCache(name), value.x, value.y);
}

void Shader::SetVector3(const char* name, glm::vec3 value)
{
	glUniform3f(GetUniformCache(name), value.x, value.y, value.z);
}

void Shader::SetVector4(const char* name, glm::vec4 value)
{
	glUniform4f(GetUniformCache(name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const char* name, glm::mat4 value)
{
	glUniformMatrix4fv(GetUniformCache(name), 1, false, glm::value_ptr(value));
}