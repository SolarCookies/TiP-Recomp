#version 330 core

out vec4 FragColor;

uniform vec4 wireColor;

void main()
{
    FragColor = wireColor;
}
