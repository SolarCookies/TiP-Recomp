cbuffer xe_system_cbuffer : register(b0) { float4 xe_system_pad[29]; };
cbuffer xe_float_cbuffer  : register(b1) { float4 xe_float_constants[18]; };
cbuffer xe_fetch_cbuffer  : register(b3) { uint4  xe_fetch_pad[48]; };

Texture2DArray<float4> xe_texture0_2d_u : register(t1);
Texture2DArray<float4> xe_texture0_2d_s : register(t2);
Texture2DArray<float4> xe_texture1_2d_u : register(t3);
Texture2DArray<float4> xe_texture1_2d_s : register(t4);
TextureCube  <float4>  xe_texture4_cube_u : register(t5);
TextureCube  <float4>  xe_texture4_cube_s : register(t6);
Texture2DArray<float4> xe_texture2_2d_u : register(t7);
Texture2DArray<float4> xe_texture2_2d_s : register(t8);
Texture2DArray<float4> xe_texture6_2d_u : register(t9);
Texture2DArray<float4> xe_texture6_2d_s : register(t10);
Texture2DArray<float4> xe_texture5_2d_u : register(t11);
Texture2DArray<float4> xe_texture5_2d_s : register(t12);

SamplerState xe_s0 : register(s0);
SamplerState xe_s1 : register(s1);
SamplerState xe_s2 : register(s2);
SamplerState xe_s3 : register(s3);
SamplerState xe_s4 : register(s4);
SamplerState xe_s5 : register(s5);
SamplerState xe_s6 : register(s6);

// Vertex shader outputs.
// t0.xy  = bump UV 0              (dcl_texcoord0 r0.xy)
// t1.xy  = bump UV 1              (dcl_texcoord1 r1.xy)
// t2.xyz = world position         (dcl_texcoord2 r2.xyz)
// t3     = clip-space screen pos  (dcl_texcoord3 r3.xyzw); xy/w -> screen UV [0,1]
// t4     = depth coords           (dcl_texcoord4 r4.xyzw); xyz/w.z ~= 1-waterDepthNDC
struct PSInput {
    float4 t0  : TEXCOORD0;
    float4 t1  : TEXCOORD1;
    float4 t2  : TEXCOORD2;
    float4 t3  : TEXCOORD3;
    float4 t4  : TEXCOORD4;
    float4 pos : SV_Position;
};

[earlydepthstencil]
float4 main(PSInput i) : SV_Target0
{
    // ── Embedded 'def' constants baked into the XPS bytecode ─────────────
    // def c6,  2.0,    -1.0,    0.5,   0.1
    // def c9,  1.0,    0.02037, 0.97963, 128.0   (Schlick F0 = 0.02037)
    // def c11, 0.0,    1.0,     0.0,   0.0       (world up)
    // def c12, 0.0,    0.2,     0.2,   0.0       (ambient water tint)
    // def c13, 0.8,    0.95,    0.95,  0.0       (refraction color tint)
    // def c14, 1.5,    0.5,     0.6,   0.7       (cube: bias, scale, ...)
    // def c20, 0.7,    0.3,     0.0,   0.0       (macro normal blend: up=0.7, detail=0.3)
    // def c21, 0.8,    0.8,     0.9,   0.5       (reflection color scale)
    static const float4 c6  = float4( 2.0f,     -1.0f,    0.5f,    0.1f);
    static const float4 c9  = float4( 1.0f,  0.02037f, 0.97963f, 128.0f);
    static const float4 c11 = float4( 0.0f,     1.0f,    0.0f,    0.0f);
    static const float4 c13 = float4( 0.8f,    0.95f,   0.95f,    0.0f);
    static const float4 c14 = float4( 1.5f,     0.5f,    0.6f,    0.7f);
    static const float4 c20 = float4( 0.7f,     0.3f,    0.0f,    0.0f);
    static const float4 c21 = float4( 0.8f,     0.8f,    0.9f,    0.5f);

    // ── Runtime constants (set by diggablesurfaceDrawRender) ──────────────
    // c0 = IDirect3DDevice9_SetPixelShaderConstantF(device, 0, &camPos, 1)
    // c1 = IDirect3DDevice9_SetPixelShaderConstantF(device, 1, &ambientLight, 1)
    // c15 = reflection blend factor (not explicitly set in water pass -> 0)
    float3 camPos   = xe_float_constants[0].xyz;
    float  c15x     = xe_float_constants[15].x;

    // ── 1. Sample both bump maps ─────────────────────────────────────────
    // tfetch2D r0.xyz_, r0.xy, tf0
    // tfetch2D r1.xyz_, r1.xy, tf1
    float3 bump0 = xe_texture0_2d_u.Sample(xe_s0, float3(i.t0.xy, 0.0f)).xyz;
    float3 bump1 = xe_texture1_2d_u.Sample(xe_s1, float3(i.t1.xy, 0.0f)).xyz;

    // ── 2. Perspective-divide texcoord4 (stores inverted water depth) ────
    // rcpc r4.w, r4.w  /  mul r8.xyz, r4, r4.w
    float3 r8 = i.t4.xyz * rcp(max(abs(i.t4.w), 1e-6f));

    // ── 3. Decode normal maps [0,1] -> [-1,1] ────────────────────────────
    // mad r0.xyz, r0, c6.x, c6.y  (= sample*2 - 1)
    // mad r1.xyz, r1, c6.x, c6.y
    float3 n0 = bump0 * c6.x + c6.y;
    float3 n1 = bump1 * c6.x + c6.y;

    // ── 4. Combine and normalize -> water surface normal ─────────────────
    // add r1, r1, r0  /  dp3 r1.w, r1, r1  /  rsqc r1.w, r1.w  /  mul r1.xyz, r1, r1.w
    float3 waterNormal = normalize(n0 + n1);

    // ── 5. XZY swizzle for world-space handedness ─────────────────────────
    // mov r0.xyz, r1.xzy
    float3 worldNormal = waterNormal.xzy;

    // ── 6. Normal-scaled refraction screen-space offset ──────────────────
    // mul r1.xyz, r1, c6.w  (c6.w = 0.1)
    float2 refrOffset = waterNormal.xy * c6.w;

    // ── 7. Normalised view direction (surface -> camera, XPS convention) ──
    // add r2.xyz, r2, -c0  /  dp3/rsqc/mul
    float3 viewDir = normalize(i.t2.xyz - camPos);

    // ── 8. Macro normal: blend world-up with detail normal ────────────────
    // mul r6.xyz, r0, c20.y  /  mad r6.xyz, c11, c20.x, r6  /  normalize
    // = normalize( (0,1,0)*0.7 + worldNormal*0.3 )
    float3 macroNormal = normalize(c11.xyz * c20.x + worldNormal * c20.y);

    // ── 9. Reflection direction off macro normal ──────────────────────────
    // dp3 r5.w, r2, r6  /  add r5.w, r5.w, r5.w  /  mad r5.xyz, -r5.w, r6, r2
    // = viewDir - 2*dot(viewDir, macroNormal)*macroNormal
    float3 reflDir = normalize(viewDir - 2.0f * dot(viewDir, macroNormal) * macroNormal);
    // mad r5.xyz, r6, c15.x, r5  (bias toward macro normal; c15x usually 0)
    reflDir += macroNormal * c15x;

    // ── 10. Sky cube map sample ──────────────────────────────────────────
    // cube r6, ... / rcp / mad / tfetchCube r6.xyzw, r6.yxw, tf4
    // mul r6.xyz, r6, c14.y  (* 0.5)
    float4 cubeColor = xe_texture4_cube_u.Sample(xe_s4, reflDir);
    cubeColor.xyz *= c14.y;

    // ── 11. Schlick Fresnel, remapped ─────────────────────────────────────
    // dp3_sat r5, r0, -r2  -> NdotV = sat(dot(worldNormal, -viewDir))
    float NdotV        = saturate(dot(worldNormal, -viewDir));
    float oneMinusN    = 1.0f - NdotV;
    // (1-NdotV)^5
    float pow5         = oneMinusN * oneMinusN;
    pow5               = pow5 * pow5 * oneMinusN;
    // Schlick: c9.y + c9.z * (1-NdotV)^5
    float schlick      = c9.y + c9.z * pow5;
    // Remap: fresnel = 1 - (1-schlick)^4, clamped to c6.z (0.5)
    float invF         = 1.0f - schlick;
    invF               = invF * invF;
    invF               = invF * invF;
    float fresnel      = min(1.0f - invF, c6.z);

    // ── 12. Screen-space UVs via perspective divide of texcoord3 ─────────
    // t3.xy / t3.w is already in [0,1] UV space (VS outputs it that way).
    // rcpc r0.w, r3.w  /  mul r1.xyz, r3, r1.w  -> non-refracted screen UV
    // mad r2.xy, r3, r0.w, r1  -> refracted screen UV
    float  invW3     = rcp(max(abs(i.t3.w), 1e-6f));
    float2 screenUV  = i.t3.xy * invW3;
    float2 refractUV = screenUV + refrOffset;

    // ── 13. Screen-half boundary fix ─────────────────────────────────────
    // The XPS keeps the refracted x on the same side of 0.5 as the pixel
    // (originally for Xbox 360 tiled memory). On PC this still prevents the
    // refraction offset from crossing the buffer midpoint and causing a seam.
    float halfDist = abs(0.5f - refractUV.x);
    float2 sampleUV;
    sampleUV.x = (screenUV.x >= 0.5f) ? (0.5f + halfDist) : (0.5f - halfDist);
    sampleUV.y = clamp(refractUV.y, 0.0f, 1.0f);

    // ── 14. Sample screen color + depth at refracted UV ──────────────────
    // tfetch2D r0.xyzw, r9.xy, tf2, point
    // tfetch2D r8.x___, r9.xy, tf6, point
    float4 screenColor = xe_texture2_2d_u.Sample(xe_s2, float3(sampleUV, 0.0f));
    float  sceneDepth  = xe_texture6_2d_u.Sample(xe_s6, float3(sampleUV, 0.0f)).x;

    // ── 15. Depth occlusion test ──────────────────────────────────────────
    // XPS: p0 = ((1-sceneDepth) - r8.z) > 0  →  (p0) jmp L1  (SKIP fallback, KEEP refracted color)
    //      (!p0) exec → overwrite r0 with non-refracted sample (object is closer than water)
    // So: show distortion when (1-sceneDepth) > r8.z; fall back to plain screenUV otherwise.
    bool refractOccluded = (sceneDepth > 0.0f) && ((1.0f - sceneDepth) - r8.z) <= 0.0f;
    bool reflFromFallback = false;
    if (refractOccluded) {
        sampleUV        = screenUV;
        screenColor     = xe_texture2_2d_u.Sample(xe_s2, float3(screenUV, 0.0f));
        reflFromFallback = true;
    }

    // ── 16. Sample reflection buffer ─────────────────────────────────────
    // Main path: 4-tap point-sampled bilinear at offsets (0,0)(1,0)(1,1)(0,1) * 0.25
    // Fallback:  single point sample at straight-down UV
    // D3D12: bilinear sampler already handles the 4-tap, single sample suffices.
    float4 refl = xe_texture5_2d_u.Sample(xe_s5, float3(sampleUV, 0.0f));

    // ── 17. Reflection validity ───────────────────────────────────────────
    // XPS main path: max4 r4.w, -r9  -> r4.w < 0 iff all 4 tap alphas > 0
    //   setp_gt r4._, -r4.w  -> p0 = (min alpha > 0) = reflection valid
    // Fallback: single sample alpha in [0,1] -> never negative -> always lerp
    bool reflValid = !reflFromFallback && (refl.w > 0.0f);

    // ── 18. Select reflection source: prefer buffer, fall back to cube ────
    // setp_eq r6._, r6.w  -> if cubeAlpha == 0: use reflection buffer
    // min r6.w, r6.w, c14.y  -> cubeAlpha = min(cubeColor.w, 0.5)
    // setp_gt r4._, -r4.w -> if reflValid: use reflection buffer directly
    // else: lerp( reflBuffer, cube, cubeAlpha )
    float  cubeAlpha  = min(cubeColor.w, c14.y);
    float3 reflection;
    if (cubeColor.w == 0.0f || reflValid) {
        // No cube data, or reflection buffer fully covers this area
        reflection = refl.xyz;
    } else {
        // Lerp: refl*(1-cubeAlpha) + cube*cubeAlpha
        // (!p0) add r6.xyz, r6, -r4  / (!p0) mad r6.xyz, r6, r6.w, r4
        reflection = (cubeColor.xyz - refl.xyz) * cubeAlpha + refl.xyz;
    }
    // mul r6.xyz, r6, c21  -> scale by (0.8, 0.8, 0.9)
    reflection *= c21.xyz;

    // ── 19. Tint refracted screen color ──────────────────────────────────
    // mul r0.xyz, r0, c13  -> (0.8, 0.95, 0.95) gives cool underwater tint
    float3 refraction = screenColor.xyz * c13.xyz;

    // ── 20. Final Fresnel blend ───────────────────────────────────────────
    // add r6.xyz, r6, -r0  /  mad r0.xyz, r6, r7.w, r0
    // = refraction + fresnel * (reflection - refraction)
    float3 output = refraction + fresnel * (reflection - refraction);

    // mov oC0, r0  (+ movs r0.w, c9.x -> alpha = 1.0)
    return float4(output, 1.0f);
}

