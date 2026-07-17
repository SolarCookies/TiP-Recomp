cbuffer xe_system_cbuffer : register(b0) {
    uint4 xe_system_consts[29];
};

cbuffer xe_float_cbuffer : register(b1) {
    float4 xe_float_constants[9];
};

cbuffer xe_bool_loop_cbuffer : register(b2) {
    uint4 xe_bool_constants[2];
    uint4 xe_loop_pad[8];
};

#define C_NDECODE xe_float_constants[0]
#define C_CUBE xe_float_constants[1]
#define C_LIGHT xe_float_constants[2]
#define C_LDIR xe_float_constants[3]
#define C_SHNORM xe_float_constants[4]
#define C_CAMPOS xe_float_constants[5]
#define C_SHADOW xe_float_constants[6]
#define C_OUTMUL xe_float_constants[7]
#define C_AMBIENT xe_float_constants[8]

Texture2DArray<float4> xe_texture15_2d_u : register(t1);
Texture2DArray<float4> xe_texture0_2d_u : register(t3);
Texture2DArray<float4> xe_texture2_2d_u : register(t5);
TextureCube<float4> xe_texture3_cube_u : register(t7);
Texture2DArray<float4> xe_texture1_2d_u : register(t9);

SamplerState xe_sampler15_ppp : register(s0);
SamplerState xe_sampler0_fff : register(s1);
SamplerState xe_sampler2_fff : register(s2);
SamplerState xe_sampler3_fff : register(s3);
SamplerState xe_sampler1_fff : register(s4);

struct PSInput {
    float4 t0 : TEXCOORD0;
    float4 t1 : TEXCOORD1;
    float4 t2 : TEXCOORD2;
    float4 t3 : TEXCOORD3;
    float4 t4 : TEXCOORD4;
    float4 t5 : TEXCOORD5;
    float4 t6 : TEXCOORD6;
    float4 pos : SV_Position;
};

float4 main(PSInput i) : SV_Target0
{
    float sc = xe_texture15_2d_u.Sample(xe_sampler15_ppp, float3(i.t2.xy, 0.0f)).x;
    float sR = xe_texture15_2d_u.Sample(xe_sampler15_ppp, float3(i.t2.xy, 0.0f), int2( 1, 0)).x;
    float sL = xe_texture15_2d_u.Sample(xe_sampler15_ppp, float3(i.t2.xy, 0.0f), int2(-1, 0)).x;
    float sD = xe_texture15_2d_u.Sample(xe_sampler15_ppp, float3(i.t2.xy, 0.0f), int2( 0, 1)).x;
    float sU = xe_texture15_2d_u.Sample(xe_sampler15_ppp, float3(i.t2.xy, 0.0f), int2( 0, -1)).x;
    float refDepth = saturate(dot(i.t1.xyz, C_SHADOW.xyz) + C_SHADOW.w);
    float lit = (sc >= refDepth ? 1.0f : 0.0f) + (sR >= refDepth ? 1.0f : 0.0f) + (sL >= refDepth ? 1.0f : 0.0f) + (sD >= refDepth ? 1.0f : 0.0f) + (sU >= refDepth ? 1.0f : 0.0f);
    float shadow = lit * C_SHNORM.z;
    float4 albSample = xe_texture0_2d_u.Sample(xe_sampler0_fff, float3(i.t0.xy, 0.0f));
    float3 albedo = albSample.xyz;
    float outAlpha = albSample.w;
    float2 nm = xe_texture2_2d_u.Sample(xe_sampler2_fff, float3(i.t0.xy, 0.0f)).xy;
    nm = nm * C_NDECODE.x + C_NDECODE.y;
    float nz = sqrt(abs(-dot(nm, nm) - C_NDECODE.y));
    float3 tsN = float3(nm, nz);
    float3 N = normalize(float3(dot(i.t4.xyz, tsN), dot(i.t5.xyz, tsN), dot(i.t3.xyz, tsN)));
    float3 V = normalize(i.t1.xyz - C_CAMPOS.xyz);
    float3 L = C_LDIR.xyz;
    float NdotL = saturate(dot(-L, N));
    float3 Rlight = 2.0f * dot(N, L) * N - L;
    float RdotV = saturate(dot(Rlight, V));
    float3 diffuse = NdotL * C_LIGHT.xyz * shadow;
    float specTerm = pow(abs(RdotV), i.t1.w);
    float3 specular = specTerm * (C_LIGHT.xyz * shadow);
    specular *= i.t6.xyz;
    if ((xe_bool_constants[1].x & 0x2u) != 0u) {
        float3 reflVec = 2.0f * dot(N, V) * N - V;
        albedo += xe_texture3_cube_u.Sample(xe_sampler3_fff, reflVec).xyz;
    }
    float4 tex1 = xe_texture1_2d_u.Sample(xe_sampler1_fff, float3(i.t0.xy, 0.0f));
    float3 ambient = max(C_AMBIENT.xyz, 0.0f);
    float3 color = albedo * (diffuse + ambient) + specular;
    color *= tex1.xyz;
    color *= C_OUTMUL.xyz;
    float alpha = outAlpha * C_OUTMUL.w;
    uint flags = xe_system_consts[0].x;
    uint alphaFunc = (flags >> 7) & 0x7u;
    if (alphaFunc != 7u) {
        float ref = asfloat(xe_system_consts[13].w);
        bool passAlpha;
        if (alphaFunc == 5u) passAlpha = alpha != ref;
        else passAlpha = ((alphaFunc & 1u) && alpha < ref) || ((alphaFunc & 2u) && alpha == ref) || ((alphaFunc & 4u) && alpha > ref);
        if (!passAlpha) discard;
    }
    float bias = asfloat(xe_system_consts[15].x);
    return float4(color, alpha) * bias;
}
