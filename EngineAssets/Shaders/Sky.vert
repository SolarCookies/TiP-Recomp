#version 330 core

layout (location = 0) in vec3 apos;

out vec3 viewDir;

uniform mat4 camMatrix;

void main()
{
	// w=0 strips translation from the view matrix, keeping only rotation
	vec4 pos = camMatrix * vec4(apos, 0.0);
	// z=w puts the skybox at the far plane (max depth)
	gl_Position = pos.xyww;
	viewDir = normalize(apos);
}