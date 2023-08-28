#version 330 core

layout(location = 0) in vec2 a_Pos;
layout(location = 1) in vec2 a_Tex;

uniform mat4 u_View;
uniform mat4 u_Projection;

out vec2 texCoords;

void main()
{
    texCoords = a_Tex;

	gl_Position = u_Projection * u_View * vec4(a_Pos, 1.0, 1.0);
};