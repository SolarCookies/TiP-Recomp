#version 330 core

layout (location = 0) in vec3 apos;


uniform mat4 model;
uniform mat4 camMatrix;

void main()
{
	gl_Position = camMatrix * model * vec4(apos, 1.0f);
}