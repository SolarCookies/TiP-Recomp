#version 330 core

out vec4 FragColor;

in vec3 color;

in vec2 texCoord;

in vec3 Normal;
in vec3 crntPos;

uniform sampler2D tex0; // DiffuseMap

uniform vec4 uSunColor = vec4(1.0, 0.95, 0.7, 1.0); // Sun color
uniform vec3 uSunDirection = vec3(0.5, 0.5, 0.0); // Constant sun direction

uniform vec3 cameraPos;
uniform int unlit; // Unlit flag

void main()
{

    //debug UVs
    //vec4 texColor = texture(tex0, texCoord*vec2(1.0f, -1.0f)); // Flip Y for correct texture sampling
    //vec4 uvColor = vec4(texCoord*vec2(1.0f, -1.0f), 0.0f, 1.0f); // Debug UVs as color
    //FragColor = texColor + uvColor * 0.5f; // Combine texture color with UVs for visibility

    if (unlit == 1) {
        FragColor = texture(tex0, texCoord * vec2(1.0f, -1.0f)); // Unlit mode, just return the texture color
        return;
    }

    vec2 flippedTexCoord = texCoord * vec2(1.0f, -1.0f); // Flip Y for correct texture sampling
    
	vec3 skylight = vec3(0.45f, 0.55f, 0.60f) * 2; // Ambient light

    vec3 normal = normalize(Normal);
    vec3 sunDir = normalize(uSunDirection);

    // Diffuse
    float diffuse = max(dot(normal, sunDir), 0.0f);

    // Specular
    vec3 viewDir = normalize(cameraPos - crntPos);
    vec3 reflectDir = reflect(-sunDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 64.0f); // Shininess = 32

    vec4 texColor = texture(tex0, flippedTexCoord);

    vec3 ambient = skylight * texColor.rgb * 0.3;
    vec3 diffuseColor = texColor.rgb * uSunColor.rgb * diffuse;
    vec3 specular = uSunColor.rgb * spec * 0.5;

    vec3 result = ambient + diffuseColor + specular;
    if(texColor.a < 0.1)
        discard;
    FragColor = vec4(result, 1.0f);
}