#version 330 core

out vec4 FragColor;

in vec3 color;

in vec2 texCoord;

in vec3 Normal;
in vec3 crntPos;

uniform vec4 LineColor;

void main()
{

    //debug UVs
    //vec4 texColor = texture(tex0, texCoord*vec2(1.0f, -1.0f)); // Flip Y for correct texture sampling
    //vec4 uvColor = vec4(texCoord*vec2(1.0f, -1.0f), 0.0f, 1.0f); // Debug UVs as color
    //FragColor = texColor + uvColor * 0.5f; // Combine texture color with UVs for visibility

    FragColor = LineColor; // Unlit color output

}