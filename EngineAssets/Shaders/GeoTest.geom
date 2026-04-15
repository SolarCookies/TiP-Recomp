#version 330 core
layout (triangles) in;
// Emit wireframe shells as line strips. Limited by hardware max emitted vertices.
// Reduce shells so total emitted vertices fit common hardware limits.
// 18 shells * 3 edges * 2 verts = 108 max vertices (fits under reported limit of 113)
// Emit filled triangle shells. Each shell is a triangle (3 verts).
// 18 shells * 3 verts = 54 max vertices
// Use triangle_strip (supported) and EndPrimitive() after each 3 emitted vertices
layout (triangle_strip, max_vertices = 54) out;

out vec3 Normal;
out vec3 color;
out vec2 texCoord;
out float layer;  // normalized shell layer [0..1]
out vec3 crntPos; // pass world position to fragment

in DATA
{
    vec3 Normal;
    vec3 color;
    vec2 texCoord;
    mat4 projection;
} data_in[];

in vec3 vCrntPos[]; // receive per-vertex world position from vertex shader (from vertex shader's vCrntPos)

// Default main function
void main()
{
    // Base positions for the triangle
    vec4 p0 = gl_in[0].gl_Position;
    vec4 p1 = gl_in[1].gl_Position;
    vec4 p2 = gl_in[2].gl_Position;

    // Small normal-based offset direction (same as before) - keep value hard-coded
    vec3 vector0 = vec3(p0 - p1);
    vec3 vector1 = vec3(p2 - p1);
    // normalized direction in world/clip space, w=0 so additions translate positions only
    vec4 SN = vec4(normalize(cross(vector0,vector1)), 0.0) * 0.01;

    // Hard-coded number of shells for shell fur
    // Reduced from 32 to 18 to fit typical hardware geometry shader vertex limits
    const int SHELLS = 18;

    // For each shell, emit a filled triangle (3 vertices) offset along the VERTEX normal in WORLD space
    // Project the world-space displaced position with the supplied projection (camMatrix) so depth ordering is consistent
    // 3 vertices per shell -> fits within max_vertices
    for (int s = 1; s <= SHELLS; ++s)
    {
          // normalized layer value in [0,1] where 0 is inner/bottom and 1 is outer/top
          float layerVal = 0.0;
          if (SHELLS > 1) layerVal = float(s - 1) / float(SHELLS - 1);

          // world-space displacement along the vertex normal
          float scale = 0.001; // per-shell base scale in world units (tweakable)

          vec3 wpos0 = vCrntPos[0] + normalize(data_in[0].Normal) * (scale * float(s));
          vec3 wpos1 = vCrntPos[1] + normalize(data_in[1].Normal) * (scale * float(s));
          vec3 wpos2 = vCrntPos[2] + normalize(data_in[2].Normal) * (scale * float(s));

          // project displaced world positions into clip space using the projection matrix passed from the vertex shader
          vec4 clip0 = data_in[0].projection * vec4(wpos0, 1.0);
          vec4 clip1 = data_in[1].projection * vec4(wpos1, 1.0);
          vec4 clip2 = data_in[2].projection * vec4(wpos2, 1.0);

          gl_Position = clip0;
          Normal = data_in[0].Normal;
          color = data_in[0].color;
          texCoord = data_in[0].texCoord;
          crntPos = vCrntPos[0];
          layer = layerVal;
        EmitVertex();

          gl_Position = clip1;
          Normal = data_in[1].Normal;
          color = data_in[1].color;
          texCoord = data_in[1].texCoord;
          crntPos = vCrntPos[1];
          layer = layerVal;
        EmitVertex();

          gl_Position = clip2;
          Normal = data_in[2].Normal;
          color = data_in[2].color;
          texCoord = data_in[2].texCoord;
          crntPos = vCrntPos[2];
          layer = layerVal;
        EmitVertex();

        EndPrimitive();
    }
}