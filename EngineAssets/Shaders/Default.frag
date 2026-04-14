#version 330 core

out vec4 FragColor;

in vec3 color;

in vec2 texCoord;
in vec4 fragPosLight;

in vec3 Normal;
in vec3 crntPos;

uniform sampler2D tex0; // DiffuseMap

uniform sampler2D tex1; // NormalMap

uniform sampler2D ShadowMap; // ShadowMap

uniform vec4 lightColor;
uniform vec3 lightPos;
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

    vec4 texNormal = texture(tex1, flippedTexCoord);

    vec3 directxNormal = texNormal.rgb * 2.0f - 1.0f;
    directxNormal.y = -directxNormal.y; // Invert Y for DirectX-to-OpenGL
    vec3 normal = normalize(Normal + directxNormal); // Normal map adjustment
    vec3 lightDirection = normalize(lightPos - crntPos);

    // Diffuse
    float diffuse = max(dot(normal, lightDirection), 0.0f);

    // Specular
    vec3 viewDir = normalize(cameraPos - crntPos);
    vec3 reflectDir = reflect(-lightDirection, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32.0f); // Shininess = 32

    vec4 texColor = texture(tex0, flippedTexCoord);

    vec3 ambient = skylight * texColor.rgb * 0.3; // Ambient strength
    vec3 diffuseColor = texColor.rgb * lightColor.rgb * diffuse;
    vec3 specular = lightColor.rgb * spec * 0.5; // Specular strength

    float shadow = 0.0f;
    vec3 lightCoords = fragPosLight.xyz / fragPosLight.w;
    if(lightCoords.z <= 1.0f){
        lightCoords = (lightCoords + 1.0f) / 2.0f;

        float closestDepth = texture(ShadowMap, lightCoords.xy).r;
        float currentDepth = lightCoords.z;

        float bias = 0.005f;
        if(currentDepth > closestDepth + bias){
            shadow = 1.0;
        }
    }

    vec3 result = ambient + (diffuseColor * (1.0f - shadow)) + specular;
    FragColor = vec4(result, texColor.a);
}