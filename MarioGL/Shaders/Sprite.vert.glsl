#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec2 aOffset;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec2 texCoords;

void main()
{
	texCoords = aPos.zw;

	gl_Position = u_Projection * u_View * u_Model * vec4(aPos.xy + aOffset, 1.0, 1.0);
};