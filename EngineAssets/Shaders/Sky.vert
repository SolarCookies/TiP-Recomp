#version 330 core

layout (location = 0) in vec3 apos;

out vec3 viewDir;

uniform mat4 camMatrix;
uniform mat4 model;

void main()
{
	// Use model matrix to position skybox in world, then project normally
	vec4 worldPos = model * vec4(apos, 1.0);
	gl_Position = camMatrix * worldPos;
	viewDir = normalize(apos);
}