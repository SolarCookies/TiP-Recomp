#version 330 core

layout (location = 0) in vec3 apos;
layout (location = 1) in vec3 acolor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec3 color;

out vec2 texCoord;
out vec4 fragPosLight;

out vec3 Normal;
out vec3 vCrntPos;

out DATA
{
	vec3 Normal;
	vec3 color;
	vec2 texCoord;
	mat4 projection;
} data_out;

uniform mat4 camMatrix;
uniform mat4 model;
uniform mat4 lightProjection;

void main()
{
	vCrntPos = vec3(model * vec4(apos, 1.0));
	
	gl_Position = camMatrix * vec4(vCrntPos, 1.0);
	color = acolor;
	texCoord = aTex;
	// transform normal to world space (assumes model matrix encodes model->world)
	vec3 worldNormal = normalize(mat3(model) * aNormal);
	Normal = worldNormal;
	fragPosLight = lightProjection * vec4(vCrntPos,1.0f);

	data_out.Normal = worldNormal;
	data_out.color = acolor;
	data_out.texCoord = aTex;
	data_out.projection = camMatrix;
}