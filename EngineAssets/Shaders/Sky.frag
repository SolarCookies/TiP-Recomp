#version 330 core

out vec4 FragColor;

in vec3 viewDir;

uniform vec3 uSunDirection = vec3(0.0, -0.0, -1.0); // Constant sun direction

void main()
{
    // Gradient: mix horizon (light blue) and zenith (deep blue)
    vec3 horizonColor = vec3(0.7, 0.85, 1.0); // light blue
    vec3 zenithColor = vec3(0.05, 0.2, 0.6);  // deep blue
    float t = clamp(viewDir.y * 0.5 + 0.5, 0.0, 1.0); // -1..1 -> 0..1
    vec3 skyColor = mix(horizonColor, zenithColor, t);

    // Sun disk parameters
    float sunDiskRadius = 0.02; // radians, adjust for size
    float sunSoftness = 0.008;  // edge softness
    vec3 sunColor = vec3(1.0, 0.95, 0.7);

    float sunDot = dot(normalize(viewDir), normalize(uSunDirection));
    float sunDisk = smoothstep(sunDiskRadius + sunSoftness, sunDiskRadius - sunSoftness, acos(sunDot));
    skyColor = mix(skyColor, sunColor, sunDisk);

    // Optional: subtle sun glow
    float sunGlow = pow(max(sunDot, 0.0), 32.0) * 0.5;
    skyColor += sunColor * sunGlow;

    FragColor = vec4(skyColor, 1.0);
}