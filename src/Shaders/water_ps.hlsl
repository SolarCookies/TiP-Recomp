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

struct PSInput {
    float4 t0  : TEXCOORD0;
    float4 t1  : TEXCOORD1;
    float4 t2  : TEXCOORD2;
    float4 t3  : TEXCOORD3;
    float4 t4  : TEXCOORD4;
    float4 pos : SV_Position;
    uint   ff  : SV_IsFrontFace;
};

[earlydepthstencil]
float4 main(PSInput i) : SV_Target0 {

    float2 uv = i.t0.xy;
    float3 n0 = xe_texture0_2d_u.Sample(xe_s0, float3(uv,             0)).xyz * 2.0 - 1.0;
    float3 n1 = xe_texture0_2d_u.Sample(xe_s0, float3(uv * 2.7 + 0.37, 0)).xyz * 2.0 - 1.0;

    float3 n = normalize(float3((n0.xy + n1.xy) * 0.85, 1.0));

    float3 V = float3(0.0, 0.0, 1.0);
    float3 L = normalize(float3(0.45, 0.30, 0.85));
    float3 H = normalize(L + V);
    float3 R = reflect(-V, n);

    float NdotV = saturate(dot(n, V));
    float fres  = 0.02 + 0.98 * pow(1.0 - NdotV, 5.0);

    float skyT  = saturate(R.z * 0.5 + 0.5);
    float3 sky  = lerp(float3(0.06, 0.10, 0.16),     // horizon
                       float3(0.55, 0.70, 0.95),     // zenith
                       skyT);

    float3 deep    = float3(0.005, 0.020, 0.040);
    float3 shallow = float3(0.020, 0.060, 0.085);
    float3 body    = lerp(deep, shallow, NdotV);

    float3 col = lerp(body, sky, fres);

    float NdotH = saturate(dot(n, H));
    float spec  = pow(NdotH, 220.0) * 1.6;
    float spec2 = pow(NdotH,  40.0) * 0.18;
    col        += (spec + spec2) * float3(1.00, 0.96, 0.85);

    static const float bayer4[16] = {
         0.0/16.0,  8.0/16.0,  2.0/16.0, 10.0/16.0,
        12.0/16.0,  4.0/16.0, 14.0/16.0,  6.0/16.0,
         3.0/16.0, 11.0/16.0,  1.0/16.0,  9.0/16.0,
        15.0/16.0,  7.0/16.0, 13.0/16.0,  5.0/16.0,
    };
    
    uint2 px  = uint2(i.pos.xy);
    float th  = bayer4[(px.y & 3) * 4 + (px.x & 3)];

    float opacity = lerp(0.45, 0.95, fres);
    clip(opacity - th);

    return float4(col, 1.0);
}

