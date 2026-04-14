#version 330 core

out vec4 FragColor;

in vec3 color;

in vec2 texCoord;
in vec4 fragPosLight;

in vec3 Normal;
in vec3 crntPos;
in float layer; // normalized shell layer [0..1]

//uniform float inflateScale; // how much to inflate based on vertex normal

uniform sampler2D tex0; // DiffuseMap

uniform sampler2D ShadowMap; // ShadowMap

uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;
uniform int unlit; // Unlit flag

void main()
{
    const float inflateScale = 0.0f;

    //debug UVs
    //vec4 texColor = texture(tex0, texCoord*vec2(1.0f, -1.0f)); // Flip Y for correct texture sampling
    //vec4 uvColor = vec4(texCoord*vec2(1.0f, -1.0f), 0.0f, 1.0f); // Debug UVs as color
    //FragColor = texColor + uvColor * 0.5f; // Combine texture color with UVs for visibility

    //shifted uvs based on layer
    vec2 shiftedUV = (texCoord * vec2(10.0f, -10.0f)) + vec2(0.0f, layer*0.1f);

    if (unlit == 1) {
        FragColor = texture(tex0, shiftedUV); // Unlit mode, just return the texture color
        return;
    }

    vec2 flippedTexCoord = texCoord * vec2(1.0f, -1.0f); // Flip Y for correct texture sampling
    
	vec3 skylight = vec3(0.45f, 0.55f, 0.60f) * 2; // Ambient light


    //vec4 texAlpha = texture(tex2, flippedTexCoord*10.0f);

    vec3 normal = normalize(Normal); // Normal map adjustment (used for lighting)

    // apply a small positional displacement based on the vertex normal (not the normal map)
    // this makes the outer shells inflate following the mesh vertex normals
    vec3 vertexNormal = normalize(Normal);
    vec3 displacedPos = crntPos + vertexNormal * (layer * inflateScale);
    vec3 lightDirection = normalize(lightPos - displacedPos);

    // Diffuse
    float diffuse = max(dot(Normal, lightDirection), 0.0f);

    // Specular — compute view direction from displaced position so view-dependent terms match inflation
    vec3 viewDir = normalize(cameraPos - displacedPos);
    vec3 reflectDir = reflect(-lightDirection, Normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32.0f); // Shininess = 32

    vec4 texColor = texture(tex0, shiftedUV);

    // use displaced pos for view dependent terms as well for consistent 'inflation' look
    vec3 ambient = skylight * vec3(1.0f,1.0f,1.0f) * 0.3; // Ambient strength
    vec3 diffuseColor = vec3(1.0f,1.0f,1.0f) * lightColor.rgb * diffuse;
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
    if (texColor.a < 0.01){
        if (texColor.a < 0.01){
            if (layer <= 0.1f){
            }else{
                discard;
            }
        }
    }
    if (layer <= 0.1f){
        FragColor = vec4(result*layer, 1.0f);
    }
    else{
        FragColor = vec4(result*layer, texColor.a);
    }
}