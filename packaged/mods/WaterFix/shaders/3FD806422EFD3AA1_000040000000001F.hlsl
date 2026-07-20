cbuffer xe_system_cbuffer : register(b0) {
    float4 xe_system_pad[29];
};

cbuffer xe_float_cbuffer : register(b1) {
    float4 xe_float_constants[18];
};

cbuffer xe_fetch_cbuffer : register(b3) {
    uint4 xe_fetch_pad[48];
};

Texture2DArray<float4> xe_texture0_2d_u : register(t1);
Texture2DArray<float4> xe_texture0_2d_s : register(t2);
Texture2DArray<float4> xe_texture1_2d_u : register(t3);
Texture2DArray<float4> xe_texture1_2d_s : register(t4);
TextureCube<float4> xe_texture4_cube_u : register(t5);
TextureCube<float4> xe_texture4_cube_s : register(t6);
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

struct PSInput {
    float4 t0 : TEXCOORD0;
    float4 t1 : TEXCOORD1;
    float4 t2 : TEXCOORD2;
    float4 t3 : TEXCOORD3;
    float4 t4 : TEXCOORD4;
    float4 pos : SV_Position;
};

[earlydepthstencil]
float4 main(PSInput i) : SV_Target0
{
    static const float4 c6 = float4(2.0f, -1.0f, 0.5f, 0.1f);
    static const float4 c9 = float4(1.0f, 0.02037f, 0.97963f, 128.0f);
    static const float4 c11 = float4(0.0f, 1.0f, 0.0f, 0.0f);
    static const float4 c13 = float4(0.8f, 0.95f, 0.95f, 0.0f);
    static const float4 c14 = float4(1.5f, 0.5f, 0.6f, 0.7f);
    static const float4 c20 = float4(0.7f, 0.3f, 0.0f, 0.0f);
    static const float4 c21 = float4(0.8f, 0.8f, 0.9f, 0.5f);
    float3 camPos = xe_float_constants[0].xyz;
    float c15x = xe_float_constants[15].x;
    float3 bump0 = xe_texture0_2d_u.Sample(xe_s0, float3(i.t0.xy, 0.0f)).xyz;
    float3 bump1 = xe_texture1_2d_u.Sample(xe_s1, float3(i.t1.xy, 0.0f)).xyz;
    float3 r8 = i.t4.xyz * rcp(max(abs(i.t4.w), 1e-6f));
    float3 n0 = bump0 * c6.x + c6.y;
    float3 n1 = bump1 * c6.x + c6.y;
    float3 waterNormal = normalize(n0 + n1);
    float3 worldNormal = waterNormal.xzy;
    float2 refrOffset = waterNormal.xy * c6.w;
    float3 viewDir = normalize(i.t2.xyz - camPos);
    float3 macroNormal = normalize(c11.xyz * c20.x + worldNormal * c20.y);
    float3 reflDir = normalize(viewDir - 2.0f * dot(viewDir, macroNormal) * macroNormal);
    reflDir += macroNormal * c15x;
    float4 cubeColor = xe_texture4_cube_u.Sample(xe_s4, reflDir);
    cubeColor.xyz *= c14.y;
    float NdotV = saturate(dot(worldNormal, -viewDir));
    float oneMinusN = 1.0f - NdotV;
    float pow5 = oneMinusN * oneMinusN;
    pow5 = pow5 * pow5 * oneMinusN;
    float schlick = c9.y + c9.z * pow5;
    float invF = 1.0f - schlick;
    invF = invF * invF;
    invF = invF * invF;
    float fresnel = min(1.0f - invF, c6.z);
    float invW3 = rcp(max(abs(i.t3.w), 1e-6f));
    float2 screenUV = i.t3.xy * invW3;
    float2 refractUV = screenUV + refrOffset;
    float halfDist = abs(0.5f - refractUV.x);
    float2 sampleUV;
    sampleUV.x = (screenUV.x >= 0.5f) ? (0.5f + halfDist) : (0.5f - halfDist);
    sampleUV.y = clamp(refractUV.y, 0.0f, 1.0f);
    float4 screenColor = xe_texture2_2d_u.Sample(xe_s2, float3(sampleUV, 0.0f));
    float sceneDepth = xe_texture6_2d_u.Sample(xe_s6, float3(sampleUV, 0.0f)).x;
    bool refractOccluded = (sceneDepth > 0.0f) && ((1.0f - sceneDepth) - r8.z) <= 0.0f;
    bool reflFromFallback = false;
    if (refractOccluded) {
        sampleUV = screenUV;
        screenColor = xe_texture2_2d_u.Sample(xe_s2, float3(screenUV, 0.0f));
        reflFromFallback = true;
    }
    float4 refl = xe_texture5_2d_u.Sample(xe_s5, float3(sampleUV, 0.0f));
    bool reflValid = !reflFromFallback && (refl.w > 0.0f);
    float cubeAlpha = min(cubeColor.w, c14.y);
    float3 reflection;
    if (cubeColor.w == 0.0f || reflValid) {
        reflection = refl.xyz;
    } else {
        reflection = (cubeColor.xyz - refl.xyz) * cubeAlpha + refl.xyz;
    }
    reflection *= c21.xyz;
    float3 refraction = screenColor.xyz * c13.xyz;
    float3 output = refraction + fresnel * (reflection - refraction);
    return float4(output, 1.0f);
}
