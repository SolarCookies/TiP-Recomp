cbuffer xe_system_cbuffer : register(b0) {
    uint4 xe_system_consts[29];
};

cbuffer xe_float_cbuffer : register(b1) {
    float4 xe_float_constants[10];
};

cbuffer xe_bool_loop_cbuffer : register(b2) {
    uint4 xe_bool_constants[2];
    uint4 xe_loop_constants[8];
};

#define C_CAMPOS xe_float_constants[0]
#define C_DIR xe_float_constants[1]
#define C_C4 xe_float_constants[2]
#define C_C6 xe_float_constants[3]
#define C_FADE xe_float_constants[4]
#define C_FOG xe_float_constants[5]
#define C_PARAM xe_float_constants[6]
#define C_UVSCALE xe_float_constants[7]
#define C_TINT xe_float_constants[8]
#define C_C255 xe_float_constants[9]

Texture2DArray<float4> xe_texture1_2d_u : register(t1);
Texture2DArray<float4> xe_texture3_2d_u : register(t3);
Texture2DArray<float4> xe_texture7_2d_u : register(t5);
Texture2DArray<float4> xe_texture2_2d_u : register(t7);
Texture2DArray<float4> xe_texture0_2d_u : register(t9);

SamplerState xe_sampler1_fff : register(s0);
SamplerState xe_sampler3_fff : register(s1);
SamplerState xe_sampler7_llf : register(s2);
SamplerState xe_sampler2_fff : register(s3);
SamplerState xe_sampler0_llf : register(s4);

struct PSInput {
    float4 t0 : TEXCOORD0;
    float4 t1 : TEXCOORD1;
    float4 t2 : TEXCOORD2;
    float4 t3 : TEXCOORD3;
    float4 t4 : TEXCOORD4;
    float4 t5 : TEXCOORD5;
    float4 pos : SV_Position;
};

float4 main(PSInput i) : SV_Target0
{
    float2 uv = i.t5.zw;
    float2 bump = xe_texture1_2d_u.Sample(xe_sampler1_fff, float3(uv * C_UVSCALE.x, 0)).xy;
    float noise = xe_texture3_2d_u.Sample(xe_sampler3_fff, float3(uv * C_UVSCALE.w, 0)).x;
    float mC = xe_texture7_2d_u.Sample(xe_sampler7_llf, float3(uv, 0)).y;
    float mR = xe_texture7_2d_u.Sample(xe_sampler7_llf, float3(uv, 0), int2(1, 0)).y;
    float mL = xe_texture7_2d_u.Sample(xe_sampler7_llf, float3(uv, 0), int2(-1, 0)).y;
    float mD = xe_texture7_2d_u.Sample(xe_sampler7_llf, float3(uv, 0), int2(0, 1)).y;
    float mU = xe_texture7_2d_u.Sample(xe_sampler7_llf, float3(uv, 0), int2(0, -1)).y;
    float3 viewDir = normalize(i.t4.xyz - C_CAMPOS.xyz);
    float maxXZ = max(abs(i.t4.x), abs(i.t4.z));
    float radialFade = saturate((maxXZ * C_FADE.z - C_FADE.x) * C_FADE.y);
    float maskAvg = (mR + mL + mD + mU) * C_C6.z + mC * C_C6.z;
    float invMask = C_C4.w - maskAvg;
    float coverage = invMask + radialFade + noise;
    float2 nxy = bump * C_C6.x + C_C6.y;
    float nz = 1.0f - dot(nxy, nxy);
    float3 N = normalize(nxy.x * i.t1.xyz + nxy.y * i.t2.xyz + nz * i.t0.xyz);
    float VdotN = dot(viewDir, N);
    float3 refl = 2.0f * dot(N, -C_DIR.xyz) * N + C_DIR.xyz;
    float spec = pow(abs(saturate(dot(refl, -viewDir))), C_FOG.w);
    float3 specular = saturate(spec.xxx * C_FOG.z);
    float fres = sqrt(C_C4.w + C_TINT.w * (VdotN * VdotN - C_C4.w));
    float rscale = C_PARAM.w * VdotN - fres;
    float3 rray = normalize(i.t0.xyz * rscale + C_PARAM.w * viewDir) * C_C255.w;
    float4 r4 = float4(i.t5.z, i.t4.y * C_C255.w, i.t5.w, 0.0f);
    float stepScale = C_PARAM.z / rray.y;
    r4.xyz = stepScale * rray + r4.xyz;
    float2 puv = float2(0, 0);
    [loop] for (int s = 0; s < 7; ++s) {
        puv = r4.xz * C_UVSCALE.y;
        float h = xe_texture2_2d_u.Sample(xe_sampler2_fff, float3(puv, 0)).x;
        h = h * C_PARAM.x + C_PARAM.y;
        float above = (r4.y > h) ? 1.0f : 0.0f;
        r4.xyz = above * rray + r4.xyz;
    }
    float3 col = xe_texture0_2d_u.Sample(xe_sampler0_llf, float3(puv, 0)).xyz;
    float dist = length(float3(i.t5.z, i.t4.y * C_C255.w, i.t5.w) - r4.xyz);
    float fog = saturate(C_FOG.x * exp2(dist * C_FOG.y));
    col = saturate(fog * (C_TINT.xyz - col) + col);
    col = saturate(col + specular);
    return float4(col, coverage);
}
